#include <stdio.h>
#include <stdlib.h>

// Definição do nó
typedef struct s_list {
    void          *content;
    struct s_list *next;
} t_list;

// Função para criar nós
t_list *sc_lstnew(void *content) {
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node) return NULL;
    new_node->content = content;
    new_node->next = NULL;
    return new_node;
}

// A sua função sc_lstdelone
void sc_lstdelone(t_list *lst, void (*del)(void *)) {
    if (!lst || !del) 
        return;
    // 1. Limpa o conteúdo guardado dentro do nó usando a função recebida
    del(lst->content);
    // 2. Libera a caixinha do nó em si
    free(lst);
}

// Função de limpeza customizada para o teste (limpa strings alocadas dinamicamente)
void simular_deletar_conteudo(void *content) {
    printf("   [del] Liberando a string interna: \"%s\"\n", (char *)content);
    free(content); // Como alocamos a string com malloc na main, damos free nela aqui
}

int main() {
    printf("==================================================\n");
    printf("         TESTANDO ISOLADO: sc_lstdelone           \n");
    printf("==================================================\n\n");

    // Criamos uma string dinâmica usando malloc para simular um cenário real
    char *texto = (char *)malloc(sizeof(char) * 20);
    // Copiamos um texto para dentro dela de forma simples
    int i = 0; char *origem = "Dado Secreto";
    while (origem[i]) { texto[i] = origem[i]; i++; } texto[i] = '\0';

    // Criamos o nó guardando essa string dinâmica
    t_list *no_isolado = sc_lstnew(texto);

    printf("No criado com sucesso contendo: %s\n", (char *)no_isolado->content);
    printf("Chamando sc_lstdelone para destruir o no...\n");

    // --- TESTE: sc_lstdelone ---
    sc_lstdelone(no_isolado, simular_deletar_conteudo);

    printf("\nNo destruido com sucesso e memoria totalmente limpa!\n");
    return 0;
}