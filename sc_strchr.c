#include <stdio.h>

// Sua função sc_strchr personalizada
char *sc_strchr(const char *s, int c) {
    int i = 0;

    // Percorre a string até encontrar o caractere nulo '\0' (fim do texto)
    while (s[i] != '\0') {
        // Se o caractere atual for igual ao que estamos procurando...
        if (s[i] == (char)c) {
            // ...retorna o endereço exato dessa posição na memória!
            // (s + i) calcula o endereço inicial mais o deslocamento atual 'i'
            return (char *)(s + i);
        }
        i++;
    }

    // ATENÇÃO para um detalhe clássico do C: se o caractere procurado for 
    // o próprio '\0', a função deve retornar o ponteiro para o fim da string.
    if ((char)c == '\0') {
        return (char *)(s + i);
    }

    // Se varreu a string inteira e não encontrou o caractere, retorna NULL
    return NULL;
}

int main() {
    char *email = "aluno_piscina@fortaleza.com";
    
    printf("E-mail completo: \"%s\"\n\n", email);

    // Procuramos a posição do caractere '@' para isolar o domínio
    char *local_arroba = sc_strchr(email, '@');

    if (local_arroba != NULL) {
        printf("Caractere '@' encontrado com sucesso!\n");
        printf("Endereco de inicio do e-mail: %p\n", (void *)email);
        printf("Endereco onde esta o '@':     %p\n\n", (void *)local_arroba);
        
        // Como local_arroba aponta exatamente para o '@', se mandarmos o printf 
        // imprimir a partir dali, ele mostrará o restante da string (o domínio)!
        printf("Dominio extraido:           \"%s\"\n", local_arroba);
    } else {
        printf("E-mail invalido! O caractere '@' nao foi encontrado.\n");
    }

    return 0;
}