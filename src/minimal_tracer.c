#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>

int getchar(void) {
    static int (*real_getchar)(void) = NULL;
    if (!real_getchar) {
        real_getchar = dlsym(RTLD_NEXT, "getchar");
        if (!real_getchar) {
            fprintf(stderr, "Error finding real getchar: %s\n", dlerror());
            return -1; // Or some other error indication
        }
    }
    int c = real_getchar();
    fprintf(stderr, "[TRACE] getchar() = %d (0x%02x)\n", c, (unsigned char)c);
    return c;
}
