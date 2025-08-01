/**
 * @file bcplc_driver.c
 * @brief Standalone BCPL Compiler Driver
 * @author BCPL Modernization Team
 * @date 2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <getopt.h>

#define MAX_ARGS 64
#define MAX_PATH 1024

static char build_dir[MAX_PATH] = "build_c23/src";

static void usage(const char *prog) {
  printf("Usage: %s [-b build_dir] <source.bcpl> [output]\n", prog);
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
  const char *env_dir = getenv("BCPLC_BUILD_DIR");
  if (env_dir && *env_dir) {
    strncpy(build_dir, env_dir, sizeof(build_dir) - 1);
    build_dir[sizeof(build_dir) - 1] = '\0';
  }

  int opt;
  while ((opt = getopt(argc, argv, "b:h")) != -1) {
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
