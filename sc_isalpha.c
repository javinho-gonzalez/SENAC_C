#include <unistd.h>
#include <stdio.h>

void sc_isalpha (char c){
    if (c >= 65 && c <= 90 || c >= 97 && c <= 122){
       printf("Caractere: %c e uma letra\n", c);
    }else{
        printf("caractere: %c não e uma letra\n", c);
    }
}
int main (void){
    char x = '&';
    sc_isalpha (x);
    return 0;
}