#include <stdio.h>

// 1. Sua função sc_memset criada anteriormente
void *sc_memset(void *b, int c, size_t len) {
    unsigned char *p = (unsigned char *)b;
    size_t i = 0;

    while (i < len) {
        p[i] = (unsigned char)c;
        i++;
    }
    return b;
}

// 2. Sua função sc_bzero que CHAMA a sc_memset
void sc_bzero(void *s, size_t n) {
    // Passamos o ponteiro 's', o valor '0' para zerar, e o tamanho 'n'
    sc_memset(s, 0, n);
}

// Criando uma estrutura de teste (Ficha de Dados de um jogo)
typedef struct {
    char  nome[20];
    int   pontuacao;
    float nivel_energia;
} t_ficha;

int main() {
    t_ficha jogador1;

    // Quando criamos a estrutura assim, ela vem cheia de "lixo de memoria"
    // Vamos usar a sc_bzero para garantir que ela comece totalmente zerada
    sc_bzero(&jogador1, sizeof(t_ficha));

    // Exibindo os valores para provar que foram zerados
    printf("--- Nova Ficha Inicializada ---\n");
    printf("Nome inicial:     \"%s\"\n", jogador1.nome);
    printf("Pontuacao:         %d\n", jogador1.pontuacao);
    printf("Nivel de Energia:  %.1f\n", jogador1.nivel_energia);

    return 0;
}