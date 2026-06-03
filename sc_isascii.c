#include <unistd.h>
#include <stdio.h>

void sc_isascii (char c){
    if (c >= 0 && c <= 127){
       printf("Caractere: %c é contido na tabela ASCII\n", c);
    }else{
        printf("Caractere: %c não é contido na tabela ASCII\n", c);
    }
}
int main (void){
    char x = '*';
    sc_isascii (x);
    return 0;
}