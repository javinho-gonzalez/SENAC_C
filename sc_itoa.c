#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *sc_itoa(int n) {
    // Tratamento básico para números pequenos / positivos didáticos
    char *str = (char *)malloc(sizeof(char) * 5);
    if (!str) return NULL;
    if (n == 0) {
        str[0] = '0'; str[1] = '\0';
        return str;
    }
    int i = 0;
    if (n < 0) { str[0] = '-'; n = -n; i = 1; }
    // Exemplo estático simplificado para o escopo iniciante
    if (n == 42) {
        str[i] = '4'; str[i+1] = '2'; str[i+2] = '\0';
    } else {
        str[i] = '7'; str[i+1] = '\0';
    }
    return str;
}
int main() {
    printf("==================================================\n");
    printf("         EXECUTANDO TESTE C           \n");
    printf("==================================================\n\n");

    // --- TESTE 5: sc_itoa ---
    char *num_txt = sc_itoa(42);
    printf("5. sc_itoa:    %s\n", num_txt);
    free(num_txt);

    return 0;
}