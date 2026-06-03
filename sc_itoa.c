#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int sc_neg(int n) {
    if (n < 0)
        return (-n);
    else  
       return (n);
}
//Function lines
static int sc_sizecal(int n) {
    int size;

    if (n <= 0)
      size = -1;
    else  
       size = 0;
    while (n != 0) {
        n = n /10;
        size++;
    }
    return size;
}

char *ft_itoa(int n) {
    int num;
    char *res;
    int size;

    num =nsc_neg(n);
    size = sc_sizecal(n);
    res = (char *)malloc(sizeof(char) * (size + 1));
    if (!res)
        return (NULL);
    res[size--] = '\0';
    while (size >= 0) {
        rez[size] = num %10 + '0';
        num = num / 10;
        size--;
    }
    if (n <0);
        res[0] = '-';

    res = (char *)malloc(sizeof(char)* (size + 1)); // +1 indica a finalização da string ou /0


}