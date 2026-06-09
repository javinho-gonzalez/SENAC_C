#include <stdio.h>
#include <stdlib.h>

typedef struct s_list {
    void          *content;
    struct s_list *next;
} t_list;

t_list *sc_lstnew(void *content) {
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node) return NULL;
    new_node->content = content;
    new_node->next = NULL;
    return new_node;
}

void sc_lstdelone(t_list *lst, void (*del)(void *)) {
    if (!lst || !del) return;
    del(lst->content);
    free(lst);
}

// A sua função sc_lstclear (Precisa da lstdelone acima!)
void sc_lstclear(t_list **lst, void (*del)(void *)) {
    if (!lst || !del) 
        return;
    t_list *proximo_no;

    // Enquanto o ponteiro apontar para um nó válido
    while (*lst != NULL) {
        // 1. Salva a referência do próximo nó para não perder a lista
        proximo_no = (*lst)->next;
        // 2. Deleta o nó atual de forma segura
        sc_lstdelone(*lst, del);
        // 3. Faz o ponteiro atual pular para o próximo da fila
        *lst = proximo_no;
    }
    // Garante que a variável original na main passe a valer NULL
    *lst = NULL;
}

void dummy_free(void *content) {
    // Como usamos strings literais fixas ("No X"), não precisamos dar free no texto
    printf("   [clear] Apagando estrutura do no que guardava: %s\n", (char *)content);
}

int main() {
    printf("==================================================\n");
    printf("         TESTANDO ISOLADO: sc_lstclear            \n");
    printf("==================================================\n\n");

    // Montando uma corrente de 3 nós
    t_list *lista = sc_lstnew("No 1");
    lista->next   = sc_lstnew("No 2");
    lista->next->next = sc_lstnew("No 3");

    printf("Lista criada com 3 elementos. Endereco inicial: %p\n", (void *)lista);
    printf("Disparando sc_lstclear...\n\n");

    // --- TESTE: sc_lstclear ---
    sc_lstclear(&lista, dummy_free);

    printf("\nDepois do clear, o ponteiro da lista agora vale: %p\n", (void *)lista);
    return 0;
}