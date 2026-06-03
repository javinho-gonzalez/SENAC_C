#include <stdio.h>
#include <stdlib.h> // Necessário para usar malloc e free
#include <string.h> // Necessário para usar strlen, strcpy e strcat

char *sc_strjoin(char const *s1, char const *s2) {
    char *res;
    size_t tamanho_total;

    // Seguranca básica: se alguma das strings for nula, não faz nada
    if (!s1 || !s2)
        return NULL;

    // 1. Calcula o tamanho total necessário (s1 + s2 + 1 para o '\0')
    tamanho_total = strlen(s1) + strlen(s2) + 1;

    // 2. Aloca a memória para a nova string combinada
    res = (char *)malloc(sizeof(char) * tamanho_total);

    // Se o computador estiver sem memória, o malloc falha e retorna NULL
    if (!res)
        return NULL;

    // 3. Copia a primeira string para o início do espaço alocado
    strcpy(res, s1);

    // 4. Junta (concatena) a segunda string logo em seguida
    strcat(res, s2);

    // Retorna a nova string pronta!
    return res;
}

int main() {
    char *nome = "Pedro ";
    char *sobrenome = "Silva";
    char *resultado;

    printf("String 1: \"%s\"\n", nome);
    printf("String 2: \"%s\"\n", sobrenome);

    // Chama a função para juntar as duas strings
    resultado = sc_strjoin(nome, sobrenome);

    // Verifica se a alocação funcionou antes de imprimir
    if (resultado != NULL) {
        printf("Resultado do sc_strjoin: \"%s\"\n", resultado);
        
        // MUITO IMPORTANTE: Sempre liberar a memória alocada por um malloc
        free(resultado);
    } else {
        printf("Erro ao alocar memoria!\n");
    }

    return 0;
}