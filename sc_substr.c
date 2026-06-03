#include <stdio.h>
#include <stdlib.h> // Necessário para usar malloc e free

char *sc_substr(char const *s, unsigned int start, size_t len) {
    char *sub;
    size_t i;

    // Segurança: se a string original for nula, não há o que extrair
    if (!s)
        return NULL;

    // 1. Aloca memória para o pedaço cortado (tamanho desejado + 1 para o '\0')
    sub = (char *)malloc(sizeof(char) * (len + 1));

    // Se o computador estiver sem memória livre, aborta
    if (!sub)
        return NULL;

    // 2. Copia os caracteres a partir da posição 'start'
    i = 0;
    while (i < len && s[start + i] != '\0') {
        sub[i] = s[start + i]; // Copia a letra da string original para a nova
        i++;
    }

    // 3. Coloca o caractere nulo obrigatório no final da nova string
    sub[i] = '\0';

    // Retorna o ponteiro com a substring novinha
    return sub;
}

int main() {
    char *telefone = "(85) 99999-1234";
    char *ddd;

    printf("Telefone completo: \"%s\"\n", telefone);

    // Queremos começar no índice 1 (pula o '(') e pegar 2 caracteres ('8' e '5')
    ddd = sc_substr(telefone, 1, 2);

    if (ddd != NULL) {
        printf("DDD extraido:      \"%s\"\n", ddd);
        
        // Sempre libere a memória criada pelo malloc depois de usar!
        free(ddd);
    } else {
        printf("Erro ao alocar memoria para o DDD.\n");
    }

    return 0;
}