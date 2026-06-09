#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sc_striteri(char *s, void (*f)(unsigned int, char*)) {
    if (!s || !f) return;
    unsigned int i = 0;
    while (s[i]) {
        f(i, &s[i]);
        i++;
    }
}
// 2. A função que modifica os caracteres (Obrigatoriamente ANTES da main!)
void simular_iteracao(unsigned int i, char *c) {
    // Evita avisar que não usamos o índice 'i' no código
    (void)i; 
    
    // Se o caractere apontado for 'a', transforma em 'X'
    if (*c == 'a') {
        *c = 'X';
    }
}
int main() {
    printf("==================================================\n");
    printf("         EXECUTANDO TESTE C           \n");
    printf("==================================================\n\n");

    char texto_iterar[] = "banana";
    sc_striteri(texto_iterar, simular_iteracao);
    printf("7. sc_striteri: %s\n\n", texto_iterar);

    return 0;
}