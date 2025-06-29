/**
 * @file startup.c
 * @brief BCPL Startup System - Complete C23 implementation
 * @author BCPL Compiler Modernization Team
 * @date 2025
 * @copyright Copyright (c) 2025 BCPL Compiler Team. All rights reserved.
 *
 * This file provides the BCPL program startup and initialization system
 * implemented in modern C23. It replaces the original assembly implementation
 * (su.s) with a portable, maintainable startup environment.
 *
 * ## Key Features
 * - **Program Entry**: Universal program entry point
 * - **Global Vector**: BCPL global vector initialization
 * - **Stack Management**: Separate BCPL stack allocation and setup
 * - **Argument Processing**: Command-line argument parsing and setup
 * - **Cross-Platform**: Works on all supported platforms
 */

#include "../include/bcpl_runtime.h"
#include "../include/platform.h"
#include <setjmp.h>
#include <signal.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Forward declarations for string conversion functions
BCPL_EXPORT void bcpl_c_to_string(const char *c_str, bcpl_string_t *bcpl_str,
                                  size_t max_len);

// Forward declarations for functions defined in rt.c
extern void bcpl_c_to_string(const char *c_str, bcpl_string_t *bcpl_str,
                             size_t max_len);
extern void bcpl_string_to_c(const bcpl_string_t *bcpl_str, char *c_str,
                             size_t max_len);
extern bcpl_word_t bcpl_findfail(bcpl_word_t stream_idx);

// =============================================================================
// STARTUP CONFIGURATION
// =============================================================================

#define BCPL_STACK_SIZE (4 * 1024 * 1024) ///< 4MB BCPL stack
#define BCPL_GLOBAL_SIZE 1000             ///< Default global vector size
#define BCPL_MAX_ARGS 1024                ///< Maximum command line arguments

// Global vector standard indices
#define G_START 1      ///< Entry point function (global 1)
#define G_STACKBASE 95 ///< Base of BCPL stack
#define G_STACKEND 96  ///< End of BCPL stack
#define G_ARGC 97      ///< Command line argument count
#define G_ARGV 98      ///< Command line argument vector
#define G_PARAM 99     ///< Parameter string

// =============================================================================
// GLOBAL STARTUP STATE
// =============================================================================

static bcpl_context_t *g_startup_ctx = NULL; ///< Startup context
static bcpl_word_t *g_bcpl_stack = NULL;     ///< BCPL stack memory
static bcpl_word_t *g_global_vector = NULL;  ///< Global vector
static bcpl_word_t *g_bcpl_argv = NULL;      ///< BCPL argument vector
static bool g_startup_initialized = false;   ///< Initialization flag
static jmp_buf g_error_context;              ///< Error recovery context

// =============================================================================
// FORWARD DECLARATIONS
// =============================================================================

static int setup_global_vector(int argc, char **argv);
static int setup_bcpl_stack(void);
static int setup_arguments(int argc, char **argv);
static void signal_handler(int sig);
static void startup_cleanup(void);

// =============================================================================
// MAIN PROGRAM ENTRY POINT
// =============================================================================

/**
 * @brief Main program entry point
 * @param argc Argument count
 * @param argv Argument vector
 * @return Exit status
 *
 * This is the main entry point for BCPL programs. It replaces the assembly
 * _start routine with a portable C implementation that sets up the complete
 * BCPL runtime environment.
 */
int main(int argc, char **argv) {
  int exit_status = 0;

  // Set up error recovery point
  if (setjmp(g_error_context) != 0) {
    // Error occurred, cleanup and exit
    startup_cleanup();
    return 1;
  }

  // Install signal handlers
  signal(SIGSEGV, signal_handler);
  signal(SIGABRT, signal_handler);
  signal(SIGINT, signal_handler);

  // Initialize the runtime system
  if (bcpl_rt_init() != 0) {
    fprintf(stderr, "BCPL: Failed to initialize runtime system\n");
    return 1;
  }

  // Initialize startup context
  g_startup_ctx = bcpl_init(argc, argv, NULL);
  if (!g_startup_ctx) {
    fprintf(stderr, "BCPL: Failed to initialize startup context\n");
    bcpl_rt_cleanup();
    return 1;
  }

  // Set up BCPL environment
  if (setup_global_vector(argc, argv) != 0 || setup_bcpl_stack() != 0 ||
      setup_arguments(argc, argv) != 0) {
    fprintf(stderr, "BCPL: Failed to set up BCPL environment\n");
    startup_cleanup();
    return 1;
  }

  g_startup_initialized = true;

  // Get the START function from global vector
  bcpl_function_t start_func = (bcpl_function_t)g_global_vector[G_START];
  if (!start_func) {
    fprintf(stderr, "BCPL: No START function found in global vector\n");
    startup_cleanup();
    return 1;
  }

  // Call the BCPL START function with parameter string
  bcpl_word_t param_word = 0; // Empty parameter for now
  bcpl_word_t bcpl_result = start_func(&param_word);
  exit_status = (int)bcpl_result;

  // Cleanup and exit
  startup_cleanup();
  return exit_status;
}

// =============================================================================
// GLOBAL VECTOR SETUP
// =============================================================================

/**
 * @brief Set up the BCPL global vector
 * @param argc Argument count
 * @param argv Argument vector
 * @return 0 on success, non-zero on failure
 */
static int setup_global_vector(int argc, char **argv) {
  (void)argc; // Suppress unused parameter warning
  (void)argv;

  // Allocate global vector
  size_t global_size = BCPL_GLOBAL_SIZE * sizeof(bcpl_word_t);
  g_global_vector = malloc(global_size);
  if (!g_global_vector) {
    return -1;
  }

  // Initialize global vector to zero
  memset(g_global_vector, 0, global_size);

  // Set up standard runtime functions in global vector
  // These indices match the original BCPL runtime layout
  g_global_vector[104] = (bcpl_word_t)bcpl_rdch;       // RDCH
  g_global_vector[112] = (bcpl_word_t)bcpl_wrch;       // WRCH
  g_global_vector[132] = (bcpl_word_t)bcpl_getvec;     // GETVEC
  g_global_vector[136] = (bcpl_word_t)bcpl_freevec;    // FREEVEC
  g_global_vector[152] = (bcpl_word_t)bcpl_findinput;  // FINDINPUT
  g_global_vector[156] = (bcpl_word_t)bcpl_findoutput; // FINDOUTPUT
  g_global_vector[160] = (bcpl_word_t)bcpl_endread;    // ENDREAD
  g_global_vector[164] = (bcpl_word_t)bcpl_endwrite;   // ENDWRITE
  g_global_vector[168] = (bcpl_word_t)bcpl_findfail;   // FINDFAIL

  // Store global vector in context
  g_startup_ctx->global_vector = g_global_vector;
  g_startup_ctx->global_size = BCPL_GLOBAL_SIZE;

  return 0;
}

// =============================================================================
// BCPL STACK SETUP
// =============================================================================

/**
 * @brief Set up the BCPL stack
 * @return 0 on success, non-zero on failure
 */
static int setup_bcpl_stack(void) {
  // Allocate BCPL stack
  g_bcpl_stack = malloc(BCPL_STACK_SIZE);
  if (!g_bcpl_stack) {
    return -1;
  }

  // Initialize stack to zero
  memset(g_bcpl_stack, 0, BCPL_STACK_SIZE);

  // Calculate stack boundaries in words
  bcpl_word_t stack_base =
      (bcpl_word_t)((uintptr_t)g_bcpl_stack / sizeof(bcpl_word_t));
  bcpl_word_t stack_end = stack_base + (BCPL_STACK_SIZE / sizeof(bcpl_word_t));

  // Set up global vector entries for stack
  g_global_vector[G_STACKBASE] = stack_base;
  g_global_vector[G_STACKEND] = stack_end;

  // Store stack information in context
  g_startup_ctx->stack_base = g_bcpl_stack;
  g_startup_ctx->stack_size = BCPL_STACK_SIZE;

  return 0;
}

// =============================================================================
// ARGUMENT PROCESSING
// =============================================================================

/**
 * @brief Set up command-line arguments for BCPL
 * @param argc Argument count
 * @param argv Argument vector
 * @return 0 on success, non-zero on failure
 */
static int setup_arguments(int argc, char **argv) {
  if (argc > BCPL_MAX_ARGS) {
    argc = BCPL_MAX_ARGS;
  }

  // Allocate BCPL argument vector - convert argc to unsigned for size
  // calculation
  if (argc < 0) {
    return -1; // Invalid argument count
  }
  size_t argv_size = (size_t)argc * sizeof(bcpl_word_t);
  g_bcpl_argv = malloc(argv_size);
  if (!g_bcpl_argv) {
    return -1;
  }

  // Convert C strings to BCPL strings and store pointers
  for (int i = 0; i < argc; i++) {
    size_t arg_len = strlen(argv[i]);
    if (arg_len > 255) {
      arg_len = 255; // BCPL string length limit
    }

    // Allocate BCPL string
    bcpl_string_t *bcpl_arg = malloc(sizeof(bcpl_string_t) + arg_len);
    if (!bcpl_arg) {
      return -1;
    }

    // Convert to BCPL string format (manual conversion for now)
    // Cast to bcpl_strlen_t for length assignment - check bounds first
    if (arg_len > UINT32_MAX) {
      arg_len = 255; // Fallback to BCPL string limit
    }
    bcpl_arg->length = (bcpl_strlen_t)arg_len;
    strncpy((char *)bcpl_arg->data, argv[i], arg_len);
    if (arg_len < 255)
      bcpl_arg->data[arg_len] = '\0';
    g_bcpl_argv[i] = (bcpl_word_t)bcpl_arg;
  }

  // Set up global vector entries for arguments - cast argc to unsigned
  g_global_vector[G_ARGC] = (bcpl_word_t)argc;
  g_global_vector[G_ARGV] = (bcpl_word_t)g_bcpl_argv;

  // Store argument information in context
  g_startup_ctx->argc = argc;
  // Convert BCPL argument vector to char** - allocate separate array
  char **c_argv = malloc((size_t)argc * sizeof(char *));
  if (!c_argv) {
    return -1;
  }
  for (int i = 0; i < argc; i++) {
    c_argv[i] = argv[i]; // Copy original string pointers
  }
  g_startup_ctx->argv = c_argv;

  return 0;
}

// =============================================================================
// ERROR HANDLING AND CLEANUP
// =============================================================================

/**
 * @brief Signal handler for runtime errors
 * @param sig Signal number
 */
static void signal_handler(int sig) {
  const char *sig_name = "Unknown";

  switch (sig) {
  case SIGSEGV:
    sig_name = "Segmentation fault";
    break;
  case SIGABRT:
    sig_name = "Abort";
    break;
  case SIGINT:
    sig_name = "Interrupt";
    break;
  }

  fprintf(stderr, "BCPL: Runtime error - %s (signal %d)\n", sig_name, sig);

  // Jump to error recovery point
  longjmp(g_error_context, sig);
}

/**
 * @brief Clean up startup resources
 */
static void startup_cleanup(void) {
  if (!g_startup_initialized) {
    return;
  }

  // Free BCPL argument strings
  if (g_bcpl_argv && g_startup_ctx) {
    for (int i = 0; i < g_startup_ctx->argc; i++) {
      free((void *)g_bcpl_argv[i]);
    }
    free(g_bcpl_argv);
    g_bcpl_argv = NULL;

    // Free the c_argv array we allocated
    if (g_startup_ctx->argv) {
      free(g_startup_ctx->argv);
      g_startup_ctx->argv = NULL;
    }
  }

  // Free BCPL stack
  free(g_bcpl_stack);
  g_bcpl_stack = NULL;

  // Free global vector
  free(g_global_vector);
  g_global_vector = NULL;

  // Cleanup startup context
  if (g_startup_ctx) {
    bcpl_cleanup(g_startup_ctx);
    g_startup_ctx = NULL;
  }

  // Cleanup runtime system
  bcpl_rt_cleanup();

  g_startup_initialized = false;
}

// =============================================================================
// UTILITY FUNCTIONS
// =============================================================================

/**
 * @brief Get current BCPL context
 * @return Current context or NULL
 */
BCPL_EXPORT bcpl_context_t *bcpl_get_startup_context(void) {
  return g_startup_ctx;
}

/**
 * @brief Get global vector
 * @return Global vector pointer or NULL
 */
BCPL_EXPORT bcpl_word_t *bcpl_get_global_vector(void) {
  return g_global_vector;
}

/**
 * @brief Set START function in global vector
 * @param start_func Pointer to START function
 */
BCPL_EXPORT void bcpl_set_start_function(bcpl_function_t start_func) {
  if (g_global_vector) {
    g_global_vector[G_START] = (bcpl_word_t)start_func;
  }
}

/**
 * @brief Emergency exit function
 * @param exit_code Exit code
 */
BCPL_EXPORT void bcpl_stop(int exit_code) {
  startup_cleanup();
  exit(exit_code);
}
