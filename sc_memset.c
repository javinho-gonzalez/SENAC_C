#include <stdio.h>

// Sua função sc_memset personalizada
void *sc_memset(void *b, int c, size_t len) {
    // 1. Converte o ponteiro genérico (void*) para um ponteiro de byte (unsigned char*)
    unsigned char *p = (unsigned char *)b;
    size_t i = 0;

    // 2. Loop while para andar por cada posição da memória até atingir o tamanho 'len'
    while (i < len) {
        p[i] = (unsigned char)c; // Preenche a posição atual com o caractere desejado
        i++;
    }

    // 3. Boa prática do C: retornar o ponteiro original de volta
    return b;
}

int main() {
    // Vamos criar uma string de teste com 10 caracteres
    char texto[11] = "Senha12345"; 
    
    printf("Antes do sc_memset: \"%s\"\n", texto);

    // Queremos "limpar/mascarar" os 8 primeiros caracteres com '*'
    // Passamos o texto, o caractere '*' e o tamanho 8
    sc_memset(texto, '*', 8);

    printf("Depois do sc_memset: \"%s\"\n", texto);

    return 0;
}