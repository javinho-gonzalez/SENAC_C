#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>  //for malloc and free
#include <string.h>

// A simple implementation of strlcpy since it's not standard on all operating systems
/*size_t strlcpy(char *dst, const char *src, size_t siz) {
    size_t i = 0;
    if (siz > 0) {
        while (src[i] && i < (siz - 1)) {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
    while (src[i]) i++;
    return i;
}*/