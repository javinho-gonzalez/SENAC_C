#include <stdio.h>

// Sua função sc_memchr personalizada
void *sc_memchr(const void *s, int c, size_t n) {
    // 1. Converte o ponteiro genérico para ponteiro de byte (unsigned char)
    const unsigned char *p = (const unsigned char *)s;
    size_t i = 0;

    // 2. Percorre a memória até o limite estipulado por 'n'
    while (i < n) {
        // Se o valor do byte atual for igual ao que estamos procurando...
        if (p[i] == (unsigned char)c) {
            // ...retorna o endereço exato dessa caixinha de memória!
            // Fazemos o cast de volta para (void *) para combinar com o retorno da função
            return (void *)(p + i); 
        }
        i++;
    }

    // 3. Se o loop terminou e não achou nada, retorna NULL
    return NULL;
}

int main() {
    // Criamos um array de inteiros (cada int ocupa 4 bytes, mas vamos ler como bytes individuais)
    // O número 42 está escondido na terceira posição do array
    int dados_sensor[5] = {10, 255, 42, 99, 7};
    
    printf("--- Iniciando Busca na Memoria ---\n");
    printf("Buscando o primeiro byte com valor 42...\n\n");

    // Chamamos a função passando o array, o valor 42 e o tamanho total do array em bytes
    void *endereco_encontrado = sc_memchr(dados_sensor, 42, sizeof(dados_sensor));

    if (endereco_encontrado != NULL) {
        printf("Sucesso! O valor 42 foi encontrado na memoria.\n");
        printf("Endereco de Origem do Array:  %p\n", (void *)dados_sensor);
        printf("Endereco do Byte Encontrado:  %p\n", endereco_encontrado);
        
        // Curiosidade: calculando a distância em bytes do início do array
        size_t distancia = (unsigned char *)endereco_encontrado - (unsigned char *)dados_sensor;
        printf("Ele estava exatamente no byte deslocado: %zu\n", distancia);
    } else {
        printf("O valor 42 nao foi encontrado no bloco de dados.\n");
    }

    return 0;
}