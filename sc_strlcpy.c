#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>  //for malloc and free
#include <string.h>

// A simple implementation of strlcpy since it's not standard on all operating systems
size_t strlcpy(char *dst, const char *src, size_t siz) {
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
}
int main (void) {
    char dst[10];
    const char *src = "Pedro Pablo";

    size_t result = strlcpy(dst,src,sizeof(dst));

    printf("Source: \"%s\"\n", src);
    printf("Destination: \"%s\"\n", dst);
    printf("Return value: %zu\n", result);

    if (result >= sizeof(dst))
       printf("String was truncated.\n");
    else
       printf("String copied completely.\n");

    return 0;
}