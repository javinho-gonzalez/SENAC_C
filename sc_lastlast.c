#include <stdio.h>
#include <stdlib.h>

// 1. Definição da estrutura do nó
typedef struct s_list {
    void          *content;
    struct s_list *next;
} t_list;

// 2. Função auxiliar para criar novos nós
t_list *sc_lstnew(void *content) {
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node) return NULL;
    new_node->content = content;
    new_node->next = NULL;
    return new_node;
}

// 3. A sua função sc_lstlast
t_list *sc_lstlast(t_list *lst) {
    // Se a lista estiver completamente vazia, não há último nó. Retorna NULL.
    if (!lst) 
        return NULL;
        
    // O laço avança enquanto houver um "próximo" nó na linha.
    // Quando lst->next for NULL, significa que chegamos ao último elo!
    while (lst->next != NULL) {
        lst = lst->next; // Avança o ponteiro para o próximo nó
    }
    
    // Retorna o ponteiro do nó onde o laço parou
    return lst;
}

// 4. Função principal de testes
int main() {
    printf("==================================================\n");
    printf("         EXECUTANDO TESTE C           \n");
    printf("==================================================\n\n");

    // Criamos 3 nós independentes
    t_list *no1 = sc_lstnew("Primeiro Elo");
    t_list *no2 = sc_lstnew("Elo do Meio");
    t_list *no3 = sc_lstnew("Ultimo Elo");

    // Conectamos manualmente um ao outro para formar a corrente da lista:
    // no1 -> no2 -> no3 -> NULL
    no1->next = no2;
    no2->next = no3;

    // --- TESTE: sc_lstlast ---
    // Passamos o início da lista (no1) e ela deve rastrear até o no3.
    t_list *resultado = sc_lstlast(no1);

    if (resultado != NULL) {
        printf("Sucesso! O ultimo no foi localizado.\n");
        printf("Conteudo guardado no ultimo no: \"%s\"\n", (char *)resultado->content);
    } else {
        printf("A lista informada esta vazia.\n");
    }

    // Limpeza da memória RAM
    free(no1);
    free(no2);
    free(no3);

    return 0;
}