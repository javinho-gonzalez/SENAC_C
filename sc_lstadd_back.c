#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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
t_list *sc_lstlast(t_list *lst) {
    if (!lst) return NULL;
    while (lst->next) {
        lst = lst->next;
    }
    return lst;
}

void sc_lstadd_back(t_list **lst, t_list *new) {
    if (!lst || !new) return;
    if (*lst == NULL) {
        *lst = new;
    } else {
        t_list *last = sc_lstlast(*lst);
        last->next = new;
    }
}
int main() {
    printf("==================================================\n");
    printf("         EXECUTANDO TESTE C           \n");
    printf("==================================================\n\n");

    // Criamos a lista começando com o "No_B"
    t_list *lista = sc_lstnew("No_B");
    
    // Criamos o nó que queremos colocar na frente
    t_list *no_C  = sc_lstnew("No_C");

    // Mostrando o estado inicial
    printf("Antes da insercao, o primeiro no contem: %s\n", (char *)sc_lstlast(lista)->content);

    sc_lstadd_back(&lista, no_C);

    // Mostrando o resultado final
    t_list *novo_ultimo = sc_lstlast(lista);
    printf("Depois da insercao, o novo ultimo no e: %s\n", (char *)novo_ultimo->content);

    // Limpeza rápida da memória alocada
    free(no_C);
    free(lista);
   
    return 0;
}