#ifndef BCPL_PLATFORM_GENERIC_H
#define BCPL_PLATFORM_GENERIC_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

const char *bcpl_platform_name(void);
const char *bcpl_temp_dir(void);
const char *bcpl_exe_extension(void);
const char *bcpl_lib_extension(void);
char bcpl_path_separator(void);
char bcpl_path_list_separator(void);
int bcpl_file_executable(const char *path);
long bcpl_file_size(const char *path);
int bcpl_mkdir(const char *path);
char *bcpl_getcwd(char *buf, size_t size);
int bcpl_chdir(const char *path);
int bcpl_platform_init(void);
void bcpl_platform_cleanup(void);
int bcpl_cpu_count(void);
size_t bcpl_page_size(void);
uint64_t bcpl_nano_time(void);

#ifdef __cplusplus
}
#endif

#endif // BCPL_PLATFORM_GENERIC_H
