#include <unistd.h>
#include <stdio.h>

void sc_isdigit (char c){
    if (c >= 48 && c <= 57){
       printf("Caractere: %c é um digito\n", c);
    }else{
        printf("Caractere: %c não é um digito\n", c);
    }
}
int main (void){
    char x = '1';
    sc_isdigit (x);
    return 0;
}