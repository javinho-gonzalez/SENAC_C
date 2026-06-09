#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size_t basic_strlen(const char *s) {
    size_t i = 0;
    while (s && s[i]) i++;
    return i;
}

char *sc_strmapi(char const *s, char (*f)(unsigned int, char)) {
    if (!s || !f) return NULL;
    size_t len = basic_strlen(s);
    char *res = (char *)malloc(sizeof(char) * (len + 1));
    if (!res) return NULL;
    
    unsigned int i = 0;
    while (s[i]) {
        res[i] = f(i, s[i]);
        i++;
    }
    res[i] = '\0';
    return res;
}
// 3. A função que mapeia e transforma os caracteres (Obrigatoriamente ANTES da main!)
char simular_mapeamento(unsigned int i, char c) {
    // Se for o primeiro caractere (índice 0), transforma em maiúsculo
    if (i == 0 && c >= 'a' && c <= 'z') 
        return c - 32;
    return c;
}
int main() {
    printf("==================================================\n");
    printf("         EXECUTANDO TESTE C           \n");
    printf("==================================================\n\n");

    // --- TESTE 6: sc_strmapi ---
    char *mapeado = sc_strmapi("piscina", simular_mapeamento);
    printf("6. sc_strmapi: %s\n", mapeado);
    free(mapeado);

    return 0;
}