#include <stdio.h>
#include <stdlib.h> // Necessário para usar malloc e free

// 1. Sua função sc_strlen para medir o texto
size_t sc_strlen(const char *s) {
    size_t i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

// 2. Sua função sc_memcpy para copiar blocos de memória brutos
void *sc_memcpy(void *dst, const void *src, size_t n) {
    unsigned char *d = (unsigned char *)dst;
    const unsigned char *s = (const unsigned char *)src;
    size_t i = 0;

    while (i < n) {
        d[i] = s[i];
        i++;
    }
    return dst;
}

// 3. Sua função sc_strdup personalizada
char *sc_strdup(const char *s1) {
    char *new_str;
    size_t len;

    // Segurança básica: se a string de origem for nula, retorna NULL
    if (!s1)
        return NULL;

    // Calcula o tamanho da string original
    len = sc_strlen(s1);

    // Aloca memória para a nova string (tamanho das letras + 1 para o '\0')
    new_str = (char *)malloc(sizeof(char) * (len + 1));

    // Se o computador estiver sem memória RAM disponível, aborta
    if (!new_str)
        return NULL;

    // Copia todos os caracteres (incluindo o '\0', por isso passamos len + 1)
    sc_memcpy(new_str, s1, len + 1);

    // Retorna o ponteiro da nova string clonada!
    return new_str;
}

int main() {
    // String original gravada na memória de leitura do programa
    char *original = "Piscina de Code";
    char *clone;

    printf("--- Iniciando Duplicacao de String ---\n");
    printf("Original: \"%s\" (Endereco: %p)\n\n", original, (void *)original);

    // Criando uma cópia idêntica em outro lugar da memória
    clone = sc_strdup(original);

    if (clone != NULL) {
        printf("Clone:    \"%s\" (Endereco: %p)\n\n", clone, (void *)clone);
        
        // PROVA DE INDEPENDÊNCIA:
        // Como o clone está em um local de memória liberado para escrita,
        // nós podemos alterar uma letra dele sem modificar o original!
        clone[0] = 'M'; 
        
        printf("--- Apos modificar a primeira letra do clone ---\n");
        printf("Original continua sendo: \"%s\"\n", original);
        printf("O clone modificado virou: \"%s\"\n", clone);

        // Sempre libere a memória criada pelo malloc depois de usar!
        free(clone);
    } else {
        printf("Erro ao duplicar a string por falta de memória.\n");
    }

    return 0;
}