#include <unistd.h>
#include <stdio.h>

void sc_isalnum (char c){
    if (c >= 48 && c <= 57 || c >= 65 && c <= 90 || c >= 97 && c <= 122){
       printf("Caractere: %c é alfanumerico", c);
    }else{
        printf("Caractere: %c não é alfanumerico\n", c);
    }
}
int main (void){
    char x = 'H';
    sc_isalnum (x);
    return 0;
}