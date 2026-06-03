#include <stdio.h>

// Sua função sc_memcmp personalizada
int sc_memcmp(const void *s1, const void *s2, size_t n) {
    // 1. Converte ambos os ponteiros genéricos para ponteiros de bytes individuais
    const unsigned char *p1 = (const unsigned char *)s1;
    const unsigned char *p2 = (const unsigned char *)s2;
    size_t i = 0;

    // 2. Percorre a memória até o limite estipulado por 'n'
    while (i < n) {
        // Subtrai os valores dos bytes atuais. Se o resultado não for 0...
        if (p1[i] != p2[i]) {
            // ...as memórias são diferentes! Retorna a diferença exata entre as duas
            return (p1[i] - p2[i]);
        }
        i++;
    }

    // 3. Se passou por todas as posições e não achou diferenças, retorna 0 (são idênticas)
    return 0;
}

// Simulando uma estrutura simples de Configurações de Rede
typedef struct {
    int  porta;
    int  ip_final;
    char modo_seguro; 
} t_config;

int main() {
    // 1. Criando três blocos de configurações para testar
    t_config config_atual   = {8080, 255, 'S'};
    t_config config_backup  = {8080, 255, 'S'}; // Totalmente idêntica à atual
    t_config config_alterada = {8080, 100, 'S'}; // Diferente no campo 'ip_final'

    printf("--- Iniciando Comparacoes de Configuracoes ---\n\n");

    // TESTE 1: Comparando Atual com Backup (Devem ser idênticas)
    int resultado1 = sc_memcmp(&config_atual, &config_backup, sizeof(t_config));
    printf("Comparando Atual com Backup: ");
    if (resultado1 == 0) {
        printf("IDÊNTICAS! O sistema está sincronizado.\n");
    } else {
        printf("DIFERENTES! Código de erro: %d\n", resultado1);
    }

    // TESTE 2: Comparando Atual com Alterada (Deve detectar a diferença)
    int resultado2 = sc_memcmp(&config_atual, &config_alterada, sizeof(t_config));
    printf("Comparando Atual com Alterada: ");
    if (resultado2 == 0) {
        printf("IDÊNTICAS!\n");
    } else {
        printf("DIFERENTES! Sentinela detectou desvio de dados.\n");
    }

    return 0;
}