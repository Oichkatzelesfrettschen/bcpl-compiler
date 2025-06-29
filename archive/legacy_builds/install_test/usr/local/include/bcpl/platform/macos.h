/**
 * @file platform/macos.h
 * @brief macOS-specific platform declarations
 * @author BCPL Compiler Modernization Team
 * @date 2025
 */

#ifndef BCPL_PLATFORM_MACOS_H
#define BCPL_PLATFORM_MACOS_H

#include <mach/mach_time.h>
#include <sys/types.h>

// macOS-specific constants
#define MACOS_VM_FLAGS_ANYWHERE 0x0001
#define MACOS_PROT_READ 0x01
#define MACOS_PROT_WRITE 0x02
#define MACOS_PROT_EXEC 0x04

// macOS-specific function declarations
int macos_get_page_size(void);
void *macos_mmap(void *addr, size_t length, int prot, int flags, int fd,
                 long offset);
int macos_munmap(void *addr, size_t length);

#endif // BCPL_PLATFORM_MACOS_H
