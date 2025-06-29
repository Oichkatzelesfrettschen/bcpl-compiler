/*
 * BCPL Compiler - Linux Platform Support
 *
 * Linux-specific implementations for the BCPL runtime system.
 * This file provides platform-specific functions and system interfaces
 * required by the BCPL compiler and runtime on Linux systems.
 */

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#ifdef BCPL_PLATFORM_LINUX

/*
 * Platform identification
 */
const char *bcpl_platform_name(void) { return "Linux"; }

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
  return ""; // No extension on Linux
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
  // Linux-specific initialization
  // Set up signal handlers, locale, etc.
  return 0;
}

/*
 * Platform-specific cleanup
 */
void bcpl_platform_cleanup(void) {
  // Linux-specific cleanup
}

/*
 * Get number of CPU cores
 */
int bcpl_cpu_count(void) {
  long nprocs = sysconf(_SC_NPROCESSORS_ONLN);
  return (nprocs > 0) ? (int)nprocs : 1;
}

/*
 * Get system page size
 */
size_t bcpl_page_size(void) {
  long page_size = sysconf(_SC_PAGESIZE);
  return (page_size > 0) ? (size_t)page_size : 4096;
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

#endif /* BCPL_PLATFORM_LINUX */
