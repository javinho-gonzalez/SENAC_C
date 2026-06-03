#include <unistd.h>
#include <stdio.h>

void sc_isprint (char c){
    if (c >= 32 && c <= 126){
       printf("Caractere: %c pode ser impreso \n", c);
    }else{
        printf("Caractere: %c não pode ser impreso, verifique se não é um comando\n", c);
    }
}
int main (void){
    char x = 30;
    sc_isprint (x);
    return 0;
}