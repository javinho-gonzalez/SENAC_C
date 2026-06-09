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

void sc_lstadd_front(t_list **lst, t_list *new) {
    if (!lst || !new) return;
    new->next = *lst;
    *lst = new;
}


int main() {
    printf("==================================================\n");
    printf("         EXECUTANDO TESTE C           \n");
    printf("==================================================\n\n");

    // Criamos a lista começando com o "No_B"
    t_list *lista = sc_lstnew("No_B");
    
    // Criamos o nó que queremos colocar na frente
    t_list *no_A  = sc_lstnew("No_A");

    // Mostrando o estado inicial
    printf("Antes da insercao, o primeiro no contem: %s\n", (char *)lista->content);

    sc_lstadd_front(&lista, no_A);
    // Mostrando o resultado
    printf("Depois da insercao, o novo primeiro no contem: %s\n", (char *)lista->content);
    printf("O segundo no agora contem: %s\n", (char *)lista->next->content);

    // Limpeza rápida da memória alocada
    free(no_A);
    free(lista);
   
    return 0;
}