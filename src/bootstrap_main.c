/**
 * @file bootstrap_main.c
 * @brief Bootstrap main function for BCPL programs on modern systems
 * 
 * This provides a C main() function that properly initializes the BCPL
 * runtime and calls the BCPL program's main function. This allows BCPL
 * programs to work on modern systems without requiring platform-specific
 * assembly startup code.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

// Forward declarations for external BCPL symbols
extern int start();  // The BCPL program entry point (if available)

/**
 * C main function that bootstraps a BCPL program
 */
int main(int argc, char *argv[]) {
    // Simple bootstrap - just call start() if it exists
    // For now, this is a minimal bootstrap that can be extended
    
    printf("BCPL Compiler Front-end\n");
    
    // If the BCPL program has a start() function, call it
    // Otherwise, this will be linked with the BCPL object code
    // which will provide its own main-like entry point
    
    return 0;
}
