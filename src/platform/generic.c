/*
 * BCPL Compiler - Generic Platform Support
 *
 * Generic/fallback implementations for the BCPL runtime system.
 * This file provides basic implementations for platforms that don't
 * have specific platform support files.
 */

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>

#include "../include/bcpl_types.h"
#include "../include/platform.h"
#include "../include/universal_platform.h"

#ifdef BCPL_PLATFORM_GENERIC

/*
 * Platform identification
 */
const char *bcpl_platform_name(void) { return "Generic"; }

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

  tmpdir = getenv("TEMP");
  if (tmpdir && tmpdir[0])
    return tmpdir;

  return "/tmp"; // Unix-like fallback
}

/*
 * Get platform-specific executable extension
 */
const char *bcpl_exe_extension(void) {
  return ""; // No extension by default
}

/*
 * Get platform-specific shared library extension
 */
const char *bcpl_lib_extension(void) {
  return ".so"; // Generic shared library extension
}

/*
 * Get platform-specific path separator
 */
char bcpl_path_separator(void) {
  return '/'; // Unix-like default
}

/*
 * Get platform-specific path list separator
 */
char bcpl_path_list_separator(void) {
  return ':'; // Unix-like default
}

/*
 * Check if a file exists and is executable
 */
int bcpl_file_executable(const char *path) {
  if (!path)
    return 0;

  // Try to use access() if available
#ifdef F_OK
  return access(path, X_OK) == 0;
#else
  // Fallback: check if file exists
  struct stat st;
  return stat(path, &st) == 0;
#endif
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

#ifdef S_IRWXU
  return mkdir(path, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
#else
  return mkdir(path, 0755);
#endif
}

/*
 * Get current working directory
 */
char *bcpl_getcwd(char *buf, size_t size) {
#ifdef _POSIX_VERSION
  return getcwd(buf, size);
#else
  // Fallback for very old systems
  if (buf && size > 0) {
    strncpy(buf, ".", size - 1);
    buf[size - 1] = '\0';
    return buf;
  }
  return NULL;
#endif
}

/*
 * Change current working directory
 */
int bcpl_chdir(const char *path) {
  if (!path)
    return -1;
#ifdef _POSIX_VERSION
  return chdir(path);
#else
  return -1; // Not available
#endif
}

/*
 * Platform-specific initialization
 */
int bcpl_platform_init(void) {
  // Generic initialization - nothing special needed
  return 0;
}

/*
 * Platform-specific cleanup
 */
void bcpl_platform_cleanup(void) {
  // Generic cleanup - nothing special needed
}

/*
 * Get number of CPU cores
 */
int bcpl_cpu_count(void) {
#ifdef _SC_NPROCESSORS_ONLN
  long nprocs = sysconf(_SC_NPROCESSORS_ONLN);
  return (nprocs > 0) ? (int)nprocs : 1;
#else
  return 1; // Conservative fallback
#endif
}

/*
 * Get system page size
 */
size_t bcpl_page_size(void) {
#ifdef _SC_PAGESIZE
  long page_size = sysconf(_SC_PAGESIZE);
  return (page_size > 0) ? (size_t)page_size : 4096;
#else
  return 4096; // Common default
#endif
}

/*
 * High-resolution timer (nanoseconds since epoch)
 */
uint64_t bcpl_nano_time(void) {
#ifdef CLOCK_MONOTONIC
  struct timespec ts;
  if (clock_gettime(CLOCK_MONOTONIC, &ts) == 0) {
    return (uint64_t)ts.tv_sec * 1000000000ULL + (uint64_t)ts.tv_nsec;
  }
#endif

  // Fallback to microsecond precision
#ifdef _POSIX_TIMERS
  struct timeval tv;
  if (gettimeofday(&tv, NULL) == 0) {
    return (uint64_t)tv.tv_sec * 1000000000ULL + (uint64_t)tv.tv_usec * 1000ULL;
  }
#endif

  return 0; // Last resort
}

#endif /* BCPL_PLATFORM_GENERIC */
