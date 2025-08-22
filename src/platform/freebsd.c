/*
 * BCPL Compiler - FreeBSD Platform Support
 *
 * FreeBSD-specific implementations for the BCPL runtime system.
 * This file provides platform-specific functions and system interfaces
 * required by the BCPL compiler and runtime on FreeBSD systems.
 */

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/sysctl.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#include "../include/bcpl_types.h"
#include "../include/platform.h"
#include "../include/universal_platform.h"

#ifdef BCPL_PLATFORM_FREEBSD

/*
 * Platform identification
 */
const char *bcpl_platform_name(void) { return "FreeBSD"; }

/*
 * Get platform-specific temporary directory
 */
const char *bcpl_temp_dir(void) {
  const char *tmpdir = getenv("TMPDIR");
  if (tmpdir && tmpdir[0])
    return tmpdir;

  tmpdir = getenv("TMP");
  if (tmpdir && tmpdir[0])
    return tmpdir;

  return "/tmp";
}

/*
 * Get platform-specific executable extension
 */
const char *bcpl_exe_extension(void) {
  return ""; // No extension on FreeBSD
}

/*
 * Get platform-specific shared library extension
 */
const char *bcpl_lib_extension(void) { return ".so"; }

/*
 * Get platform-specific path separator
 */
char bcpl_path_separator(void) { return '/'; }

/*
 * Get platform-specific path list separator
 */
char bcpl_path_list_separator(void) { return ':'; }

/*
 * Check if a file exists and is executable
 */
int bcpl_file_executable(const char *path) {
  if (!path)
    return 0;
  return access(path, X_OK) == 0;
}

/*
 * Get file size
 */
long bcpl_file_size(const char *path) {
  struct stat st;
  if (stat(path, &st) != 0)
    return -1;
  return st.st_size;
}

/*
 * Create directory if it doesn't exist
 */
int bcpl_mkdir(const char *path) {
  if (!path)
    return -1;

  struct stat st;
  if (stat(path, &st) == 0) {
    return S_ISDIR(st.st_mode) ? 0 : -1;
  }

  return mkdir(path, 0755);
}

/*
 * Get current working directory
 */
char *bcpl_getcwd(char *buf, size_t size) { return getcwd(buf, size); }

/*
 * Change current working directory
 */
int bcpl_chdir(const char *path) {
  if (!path)
    return -1;
  return chdir(path);
}

/*
 * Platform-specific initialization
 */
int bcpl_platform_init(void) {
  // FreeBSD-specific initialization
  return 0;
}

/*
 * Platform-specific cleanup
 */
void bcpl_platform_cleanup(void) {
  // FreeBSD-specific cleanup
}

/*
 * Get number of CPU cores using FreeBSD sysctl
 */
int bcpl_cpu_count(void) {
  int ncpu;
  size_t len = sizeof(ncpu);

  if (sysctlbyname("hw.ncpu", &ncpu, &len, NULL, 0) == 0) {
    return ncpu;
  }

  // Fallback to sysconf
  long nprocs = sysconf(_SC_NPROCESSORS_ONLN);
  return (nprocs > 0) ? (int)nprocs : 1;
}

/*
 * High-resolution timer (nanoseconds since epoch)
 */
uint64_t bcpl_nano_time(void) {
  struct timespec ts;
  if (clock_gettime(CLOCK_MONOTONIC, &ts) != 0) {
    return 0;
  }
  return (uint64_t)ts.tv_sec * 1000000000ULL + (uint64_t)ts.tv_nsec;
}

// =============================================================================
// UNIVERSAL PLATFORM INTERFACE IMPLEMENTATION
// =============================================================================

uint64_t bcpl_platform_get_timestamp(void) { return bcpl_nano_time(); }

void bcpl_platform_sleep(uint64_t nanoseconds) {
  struct timespec ts;
  ts.tv_sec = nanoseconds / 1000000000ULL;
  ts.tv_nsec = nanoseconds % 1000000000ULL;
  nanosleep(&ts, NULL);
}

uint64_t bcpl_platform_get_time_ns(void) { return bcpl_nano_time(); }

void bcpl_platform_sleep_ms(uint32_t milliseconds) {
  bcpl_platform_sleep((uint64_t)milliseconds * 1000000ULL);
}

int bcpl_platform_get_cpu_count(void) { return bcpl_cpu_count(); }

int bcpl_platform_get_last_error(void) { return errno; }

const char *bcpl_platform_getenv(const char *name) { return getenv(name); }

void bcpl_platform_print_stacktrace(FILE *file) {
  (void)file;
  fprintf(stderr, "Stack trace not available on FreeBSD\n");
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

_Noreturn void bcpl_platform_exit(int code) { exit(code); }

bcpl_cpu_features_t bcpl_platform_get_cpu_features(void) {
  bcpl_cpu_features_t features = {0};
  strncpy(features.arch_name, "x86_64", sizeof(features.arch_name) - 1);
  features.core_count = bcpl_cpu_count();
  features.has_simd = true;
  features.has_aes = false;
  features.feature_flags = BCPL_CPU_FEATURE_SSE2;
  return features;
}

#endif /* BCPL_PLATFORM_FREEBSD */
