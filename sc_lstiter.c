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

// A sua função sc_lstiter
void sc_lstiter(t_list *lst, void (*f)(void *)) {
    if (!lst || !f) 
        return;

    // Avança de elo em elo até chegar ao fim (NULL)
    while (lst != NULL) {
        // Executa a função passando o conteúdo do nó atual
        f(lst->content);
        // Pula para o próximo nó
        lst = lst->next;
    }
}

// Função de teste que será aplicada a cada nó
void imprimir_maiusculo(void *content) {
    char *str = (char *)content;
    printf("   -> Executando f(): ");
    int i = 0;
    while (str[i]) {
        // Transforma letras minúsculas em maiúsculas na hora de printar
        if (str[i] >= 'a' && str[i] <= 'z')
            printf("%c", str[i] - 32);
        else
            printf("%c", str[i]);
        i++;
    }
    printf("\n");
}

int main() {
    printf("==================================================\n");
    printf("         TESTANDO ISOLADO: sc_lstiter             \n");
    printf("==================================================\n\n");

    t_list *lista = sc_lstnew("primeiro");
    lista->next   = sc_lstnew("segundo");
    lista->next->next = sc_lstnew("terceiro");

    printf("Lista original criada. Aplicando sc_lstiter:\n");

    // --- TESTE: sc_lstiter ---
    sc_lstiter(lista, imprimir_maiusculo);

    // Limpeza rápida da memória
    free(lista->next->next);
    free(lista->next);
    free(lista);
    return 0;
}