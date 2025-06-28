#define _GNU_SOURCE // For REG_RIP etc. in ucontext.h if not implicitly available
#include <stdio.h>
#include <signal.h>
#include <ucontext.h>
#include <stdlib.h>
#include <unistd.h>    // For execvp, write, _exit, STDERR_FILENO
#include <string.h>    // For strcmp, strsignal
#include <execinfo.h>  // For backtrace
#include <fcntl.h>     // For open, O_WRONLY, O_CREAT, O_TRUNC
#include <errno.h>     // For perror

// Global log file descriptor
int trace_log_fd = -1; // Initialize to an invalid fd

void handler(int sig, siginfo_t *si, void *unused) {
    int target_fd = (trace_log_fd != -1) ? trace_log_fd : STDERR_FILENO;
    char buffer[512]; // Increased buffer size
    int len;

    len = snprintf(buffer, sizeof(buffer), "Caught signal %d (%s) at address: %p\n", sig, strsignal(sig), si->si_addr);
    write(target_fd, buffer, len);

    ucontext_t *uc = (ucontext_t *)unused;
    len = snprintf(buffer, sizeof(buffer), "Registers:\n");
    write(target_fd, buffer, len);
    len = snprintf(buffer, sizeof(buffer), "  RIP: 0x%016llx  RSP: 0x%016llx  RBP: 0x%016llx\n",
             (unsigned long long)uc->uc_mcontext.gregs[REG_RIP],
             (unsigned long long)uc->uc_mcontext.gregs[REG_RSP],
             (unsigned long long)uc->uc_mcontext.gregs[REG_RBP]);
    write(target_fd, buffer, len);
    len = snprintf(buffer, sizeof(buffer), "  RAX: 0x%016llx  RBX: 0x%016llx  RCX: 0x%016llx\n",
             (unsigned long long)uc->uc_mcontext.gregs[REG_RAX],
             (unsigned long long)uc->uc_mcontext.gregs[REG_RBX],
             (unsigned long long)uc->uc_mcontext.gregs[REG_RCX]);
    write(target_fd, buffer, len);
    len = snprintf(buffer, sizeof(buffer), "  RDX: 0x%016llx  RSI: 0x%016llx  RDI: 0x%016llx\n",
             (unsigned long long)uc->uc_mcontext.gregs[REG_RDX],
             (unsigned long long)uc->uc_mcontext.gregs[REG_RSI],
             (unsigned long long)uc->uc_mcontext.gregs[REG_RDI]);
    write(target_fd, buffer, len);
    len = snprintf(buffer, sizeof(buffer), "   R8: 0x%016llx   R9: 0x%016llx  R10: 0x%016llx\n",
             (unsigned long long)uc->uc_mcontext.gregs[REG_R8],
             (unsigned long long)uc->uc_mcontext.gregs[REG_R9],
             (unsigned long long)uc->uc_mcontext.gregs[REG_R10]);
    write(target_fd, buffer, len);
    len = snprintf(buffer, sizeof(buffer), "  R11: 0x%016llx  R12: 0x%016llx  R13: 0x%016llx\n",
             (unsigned long long)uc->uc_mcontext.gregs[REG_R11],
             (unsigned long long)uc->uc_mcontext.gregs[REG_R12],
             (unsigned long long)uc->uc_mcontext.gregs[REG_R13]);
    write(target_fd, buffer, len);
    len = snprintf(buffer, sizeof(buffer), "  R14: 0x%016llx  R15: 0x%016llx\n",
             (unsigned long long)uc->uc_mcontext.gregs[REG_R14],
             (unsigned long long)uc->uc_mcontext.gregs[REG_R15]);
    write(target_fd, buffer, len);

    void *array[30];
    size_t size;

    size = backtrace(array, 30);
    len = snprintf(buffer, sizeof(buffer), "Backtrace (%zd frames):\n", size);
    write(target_fd, buffer, len);
    backtrace_symbols_fd(array, size, target_fd);

    // Add a final marker to be sure handler completed its writes
    len = snprintf(buffer, sizeof(buffer), "--- End of Trace Handler Output ---\n");
    write(target_fd, buffer, len);

    if (target_fd != STDERR_FILENO) { // Close only if it's our specific file
        close(target_fd);
    }

    _exit(128 + sig); // Exit with a code indicating the signal
}

int main(int argc, char **argv) {
    // Open the log file early. If this fails, trace_log_fd remains -1, handler uses stderr.
    trace_log_fd = open("/tmp/explicit_trace_log.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (trace_log_fd == -1) {
        // Not using perror here to avoid its own stderr usage if that's problematic
        write(STDERR_FILENO, "Warning: Failed to open /tmp/explicit_trace_log.txt, trace will go to stderr.\n", sizeof("Warning: Failed to open /tmp/explicit_trace_log.txt, trace will go to stderr.\n")-1);
    }

    if (argc < 2) {
        char usage_msg[100];
        int len = snprintf(usage_msg, sizeof(usage_msg), "Usage: %s <program> [args...]\n", argv[0]);
        if (trace_log_fd != -1) write(trace_log_fd, usage_msg, len);
        else write(STDERR_FILENO, usage_msg, len);

        if (trace_log_fd != -1 && trace_log_fd != STDERR_FILENO) close(trace_log_fd);
        return 127;
    }

    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO | SA_RESETHAND;
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = handler;

    const char *sig_err_msg = NULL;
    if (sigaction(SIGSEGV, &sa, NULL) == -1) sig_err_msg = "Error setting SIGSEGV handler\n";
    if (sigaction(SIGILL, &sa, NULL) == -1) sig_err_msg = "Error setting SIGILL handler\n";
    if (sigaction(SIGBUS, &sa, NULL) == -1) sig_err_msg = "Error setting SIGBUS handler\n";
    if (sigaction(SIGFPE, &sa, NULL) == -1) sig_err_msg = "Error setting SIGFPE handler\n";

    if (sig_err_msg) {
        if (trace_log_fd != -1) write(trace_log_fd, sig_err_msg, strlen(sig_err_msg));
        else write(STDERR_FILENO, sig_err_msg, strlen(sig_err_msg));
        if (trace_log_fd != -1 && trace_log_fd != STDERR_FILENO) close(trace_log_fd);
        return 1;
    }

    execvp(argv[1], argv + 1);

    // If execvp returns, an error occurred
    char exec_err_msg[100];
    // Using snprintf then write to avoid mixing perror's stderr with potential log file
    snprintf(exec_err_msg, sizeof(exec_err_msg), "execvp for %s failed: ", argv[1]);
    if (trace_log_fd != -1) {
        write(trace_log_fd, exec_err_msg, strlen(exec_err_msg));
        // Can't easily write errno string without sprintf or strerror, which might not be safe
        // Just indicate failure.
        write(trace_log_fd, "Error\n", 6);
    } else {
         write(STDERR_FILENO, exec_err_msg, strlen(exec_err_msg));
         perror(NULL); // This will print actual error to stderr
    }

    if (trace_log_fd != -1 && trace_log_fd != STDERR_FILENO) {
        close(trace_log_fd);
    }
    return 1;
}
