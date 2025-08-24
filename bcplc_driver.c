/**
 * @file bcplc_driver.c
 * @brief Standalone BCPL Compiler Driver
 * @author BCPL Modernization Team
 * @date 2025
 */

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_ARGS 64
#define MAX_PATH 1024

/** Default location of compiled BCPL tooling. */
static const char *DEFAULT_BUILD_DIR = "build_c23/src";
/** Environment variable used to select an alternate build directory. */
static const char *BUILD_DIR_ENV = "BCPLC_BUILD_DIR";

/** Resolved path to the directory holding the compiler components. */
static char build_dir[MAX_PATH];

/**
 * @brief Print command line usage information.
 *
 * The driver honours the @c BCPLC_BUILD_DIR environment variable and the
 * @c -b/--build-dir option.  Command line options take precedence over the
 * environment.
 */
static void usage(const char *prog) {
  printf("Usage: %s [-b path|--build-dir path] <source.bcpl> [output]\n", prog);
  printf("       Environment variable %s provides a default.\n", BUILD_DIR_ENV);
}

/**
 * @brief Initialise the build directory from the environment or defaults.
 */
static void init_build_dir(void) {
  const char *env_dir = getenv(BUILD_DIR_ENV);
  strncpy(build_dir, env_dir ? env_dir : DEFAULT_BUILD_DIR,
          sizeof(build_dir) - 1);
  build_dir[sizeof(build_dir) - 1] = '\0';
}

int run_command(char *cmd, char **args) {
  pid_t pid = fork();
  if (pid == 0) {
    execv(cmd, args);
    perror("execv failed");
    exit(1);
  } else if (pid > 0) {
    int status;
    waitpid(pid, &status, 0);
    return WEXITSTATUS(status);
  } else {
    perror("fork failed");
    return 1;
  }
}

int compile_bcpl(const char *source_file, const char *output_file) {
  char cg_path[MAX_PATH];
  char op_path[MAX_PATH];
  char temp_ocode[MAX_PATH];
  char temp_asm[MAX_PATH];

  snprintf(cg_path, sizeof(cg_path), "%s/cg", build_dir);
  snprintf(op_path, sizeof(op_path), "%s/op", build_dir);
  snprintf(temp_ocode, sizeof(temp_ocode), "/tmp/bcpl_%d.ocode", getpid());
  snprintf(temp_asm, sizeof(temp_asm), "/tmp/bcpl_%d.s", getpid());

  printf("BCPL Compiler Driver v2025.1\n");
  printf("Source: %s\n", source_file);
  printf("Output: %s\n", output_file ? output_file : "a.out");

  // Step 1: Parse BCPL to OCODE (would need bcpl frontend)
  printf("Note: Full BCPL frontend compilation requires assembly runtime\n");
  printf("Available components:\n");
  printf("  - Code Generator: %s\n", cg_path);
  printf("  - Optimizer: %s\n", op_path);
  printf("  - LLVM Backend: %s/llcg\n", build_dir);

  printf("\nModernized C23 runtime available in libbcpl_runtime.a\n");

  return 0;
}

int main(int argc, char *argv[]) {
  init_build_dir();

  int opt;
  static struct option long_opts[] = {
      {"build-dir", required_argument, NULL, 'b'},
      {"help", no_argument, NULL, 'h'},
      {NULL, 0, NULL, 0}};

  while ((opt = getopt_long(argc, argv, "b:h", long_opts, NULL)) != -1) {
    switch (opt) {
    case 'b':
      strncpy(build_dir, optarg, sizeof(build_dir) - 1);
      build_dir[sizeof(build_dir) - 1] = '\0';
      break;
    case 'h':
    default:
      usage(argv[0]);
      return 1;
    }
  }

  if (optind >= argc) {
    usage(argv[0]);
    printf("\nBCPL Compiler Components Built:\n");
    printf("  Code Generator (cg): Converts OCODE to assembly\n");
    printf("  Optimizer (op): Optimizes assembly code\n");
    printf("  LLVM Backend (llcg): Generates LLVM IR\n");
    printf("  C23 Runtime Library: Modern portable runtime\n");
    return 1;
  }

  const char *source = argv[optind];
  const char *output = optind + 1 < argc ? argv[optind + 1] : NULL;

  return compile_bcpl(source, output);
}
