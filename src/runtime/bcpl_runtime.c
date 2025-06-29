/**
 * @file bcpl_runtime.c
 * @brief Core BCPL runtime system implementation
 * @author BCPL Compiler Modernization Team
 * @date 2025
 */

#include "../include/bcpl_runtime.h"
#include "../include/platform.h"
#include <stdlib.h>
#include <string.h>

// Global BCPL context
static bcpl_context_t *g_bcpl_ctx = NULL;

/**
 * @brief Initialize the BCPL runtime system
 */
bcpl_context_t *bcpl_runtime_init(int argc, char **argv, char **envp) {
  (void)envp; // Suppress unused parameter warning

  if (g_bcpl_ctx != NULL) {
    return g_bcpl_ctx; // Already initialized
  }

  bcpl_context_t *ctx = malloc(sizeof(bcpl_context_t));
  if (!ctx) {
    return NULL;
  }

  memset(ctx, 0, sizeof(bcpl_context_t));

  // Initialize basic context
  ctx->argc = argc;
  ctx->argv = argv;        // Direct assignment - types match
  ctx->global_size = 1000; // Default global vector size

  // Initialize platform-specific components
  if (bcpl_platform_init() != 0) {
    free(ctx);
    return NULL;
  }

  g_bcpl_ctx = ctx;
  return ctx;
}

/**
 * @brief Cleanup and shutdown the BCPL runtime
 */
void bcpl_runtime_cleanup(bcpl_context_t *ctx) {
  if (!ctx)
    return;

  bcpl_platform_cleanup();

  if (ctx == g_bcpl_ctx) {
    g_bcpl_ctx = NULL;
  }

  free(ctx);
}

/**
 * @brief Get the global BCPL context
 */
bcpl_context_t *bcpl_get_context(void) { return g_bcpl_ctx; }
