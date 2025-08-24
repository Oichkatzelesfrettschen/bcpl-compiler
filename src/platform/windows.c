/**
 * Windows Platform Implementation for BCPL Compiler
 * Provides Windows-specific runtime support
 */

#ifdef _WIN32

#include <fcntl.h>
#include <io.h>
#include <malloc.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <windows.h>

#include "../include/bcpl_types.h"
#include "../include/platform.h"
#include "../include/universal_platform.h"

// Basic type definitions for Windows
typedef intptr_t bcpl_word;

// File operation flags
#define BCPL_FILE_READ 1
#define BCPL_FILE_WRITE 2
#define BCPL_FILE_APPEND 4

// File operations
int bcpl_open_file(const char *filename, int mode) {
  int flags = 0;

  if (mode & BCPL_FILE_READ) {
    flags |= _O_RDONLY;
  }
  if (mode & BCPL_FILE_WRITE) {
    flags |= _O_WRONLY | _O_CREAT | _O_TRUNC;
  }
  if (mode & BCPL_FILE_APPEND) {
    flags |= _O_WRONLY | _O_CREAT | _O_APPEND;
  }

  return _open(filename, flags | _O_BINARY, _S_IREAD | _S_IWRITE);
}

void bcpl_close_file(int fd) { _close(fd); }

size_t bcpl_read_file(int fd, void *buffer, size_t size) {
  int result = _read(fd, buffer, (unsigned int)size);
  return result >= 0 ? (size_t)result : 0;
}

size_t bcpl_write_file(int fd, const void *buffer, size_t size) {
  int result = _write(fd, buffer, (unsigned int)size);
  return result >= 0 ? (size_t)result : 0;
}

// Time functions
uint64_t bcpl_get_time_ns(void) {
  LARGE_INTEGER freq, counter;

  if (!QueryPerformanceFrequency(&freq) || !QueryPerformanceCounter(&counter)) {
    // Fallback to GetTickCount64 if high-resolution timer fails
    return GetTickCount64() * 1000000ULL;
  }

  return (uint64_t)((double)counter.QuadPart * 1000000000.0 /
                    (double)freq.QuadPart);
}

int bcpl_get_cpu_count(void) {
  SYSTEM_INFO si;
  GetSystemInfo(&si);
  return (int)si.dwNumberOfProcessors;
}

// Process control
void bcpl_exit(int code) { ExitProcess((UINT)code); }

// Environment variables
const char *bcpl_get_env(const char *name) {
  static char buffer[32768];
  DWORD result = GetEnvironmentVariableA(name, buffer, sizeof(buffer));
  return result > 0 && result < sizeof(buffer) ? buffer : NULL;
}

// Windows-specific startup/shutdown
/*
 * Initialize Windows-specific subsystems.
 *
 * This mirrors the interface defined in platform.h where the function
 * returns an integer status code.  Historically this implementation
 * returned void which led to a signature mismatch and warnings when
 * linking against the runtime.  The function now returns `int` and
 * always indicates success with a zero result to align with the other
 * platform implementations.
 */
BCPL_EXPORT int bcpl_platform_init(void) {
  /* Set console to UTF-8 if available.  This allows UTF-8 encoded
     text to be displayed correctly on supported terminals. */
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);

  /* Initialize the high-resolution timer so that subsequent calls to
     QueryPerformanceCounter use the cached frequency. */
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);

  /* Nothing can reasonably fail here so report success. */
  return 0;
}

void bcpl_platform_cleanup(void) {
  // Nothing specific needed for Windows cleanup
}

// Windows error handling
const char *bcpl_get_error_string(void) {
  static char error_buffer[1024];
  DWORD error = GetLastError();

  if (FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                     NULL, error, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                     error_buffer, sizeof(error_buffer), NULL)) {
    // Remove trailing newline
    size_t len = strlen(error_buffer);
    if (len > 0 && error_buffer[len - 1] == '\n') {
      error_buffer[len - 1] = '\0';
      if (len > 1 && error_buffer[len - 2] == '\r') {
        error_buffer[len - 2] = '\0';
      }
    }
    return error_buffer;
  }

  snprintf(error_buffer, sizeof(error_buffer), "Windows error %lu", error);
  return error_buffer;
}

// =============================================================================
// UNIVERSAL PLATFORM INTERFACE IMPLEMENTATION
// =============================================================================

uint64_t bcpl_platform_get_timestamp(void) { return bcpl_get_time_ns(); }

void bcpl_platform_sleep(uint64_t nanoseconds) {
  DWORD ms = (DWORD)(nanoseconds / 1000000ULL);
  if (ms == 0 && nanoseconds > 0)
    ms = 1;
  Sleep(ms);
}

uint64_t bcpl_platform_get_time_ns(void) { return bcpl_get_time_ns(); }

void bcpl_platform_sleep_ms(uint32_t milliseconds) { Sleep(milliseconds); }

int bcpl_platform_get_cpu_count(void) { return bcpl_get_cpu_count(); }

int bcpl_platform_get_last_error(void) { return (int)GetLastError(); }

const char *bcpl_platform_getenv(const char *name) {
  return bcpl_get_env(name);
}

void bcpl_platform_print_stacktrace(FILE *file) {
  (void)file;
  fputs("Stack trace not available on Windows\n", stderr);
}

void bcpl_platform_memcpy(void *dest, const void *src, size_t size) {
  memcpy(dest, src, size);
}

void bcpl_platform_memset(void *dest, int value, size_t size) {
  memset(dest, value, size);
}

int bcpl_platform_memcmp(const void *ptr1, const void *ptr2, size_t size) {
  return memcmp(ptr1, ptr2, size);
}

_Noreturn void bcpl_platform_exit(int code) { bcpl_exit(code); }

bcpl_cpu_features_t bcpl_platform_get_cpu_features(void) {
  bcpl_cpu_features_t features = {0};
  SYSTEM_INFO si;
  GetSystemInfo(&si);
  strncpy(features.arch_name,
          si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64 ? "x86_64"
                                                                    : "x86",
          sizeof(features.arch_name) - 1);
  features.core_count = (int)si.dwNumberOfProcessors;
  features.has_simd = IsProcessorFeaturePresent(PF_MMX_INSTRUCTIONS_AVAILABLE);
  features.has_aes = false;
  features.feature_flags = BCPL_CPU_FEATURE_SSE2;
  return features;
}

#endif // _WIN32
