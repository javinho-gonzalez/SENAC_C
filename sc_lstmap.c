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

t_list *sc_lstlast(t_list *lst) {
    if (!lst) return NULL;
    while (lst->next) lst = lst->next;
    return lst;
}

void sc_lstadd_back(t_list **lst, t_list *new_node) {
    if (!lst || !new_node) return;
    if (*lst == NULL) *lst = new_node;
    else sc_lstlast(*lst)->next = new_node;
}

void sc_lstdelone(t_list *lst, void (*del)(void *)) {
    if (!lst || !del) return;
    del(lst->content);
    free(lst);
}

void sc_lstclear(t_list **lst, void (*del)(void *)) {
    if (!lst || !del) return;
    t_list *tmp;
    while (*lst) {
        tmp = (*lst)->next;
        sc_lstdelone(*lst, del);
        *lst = tmp;
    }
}

// A sua função sc_lstmap (Usa lstnew, lstadd_back e lstclear acima!)
t_list *sc_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *)) {
    if (!lst || !f || !del) 
        return NULL;
    
    t_list *nova_lista = NULL;
    t_list *novo_no;
    void   *novo_conteudo;

    while (lst != NULL) {
        // 1. Cria o novo conteúdo transformado pela função f
        novo_conteudo = f(lst->content);
        // 2. Cria uma nova caixinha de nó para guardar esse conteúdo
        novo_no = sc_lstnew(novo_conteudo);
        
        // SEGURANÇA: Se faltar memória RAM no computador para o novo nó
        if (!novo_no) {
            del(novo_conteudo);          // Limpa o conteúdo gerado agora
            sc_lstclear(&nova_lista, del); // Destrói tudo o que já tinha criado da nova lista
            return NULL;                 // Aborta
        }
        
        // 3. Adiciona o nó clonado e modificado no fim da nova lista
        sc_lstadd_back(&nova_lista, novo_no);
        lst = lst->next;
    }
    return nova_lista;
}

// Função mapeadora: recebe uma string e cria uma versão duplicada dela com "+"
void *transformar_adicionando_sinal(void *content) {
    char *velho = (char *)content;
    char *novo = (char *)malloc(sizeof(char) * 10);
    if (!novo) return NULL;
    
    int i = 0;
    while (velho[i]) { novo[i] = velho[i]; i++; }
    novo[i] = '+'; novo[i+1] = '\0'; // Ex: "A" vira "A+"
    return (void *)novo;
}

void deletar_conteudo_mapeado(void *content) {
    free(content); // Dá free nas strings com '+' criadas por malloc no mapeamento
}

int main() {
    printf("==================================================\n");
    printf("         TESTANDO ISOLADO: sc_lstmap              \n");
    printf("==================================================\n\n");

    // Lista de origem (estática)
    t_list *lista_original = sc_lstnew("A");
    lista_original->next   = sc_lstnew("B");

    printf("Lista Original:  [%s] -> [%s]\n", (char *)lista_original->content, (char *)lista_original->next->content);
    printf("Executando sc_lstmap para gerar uma copia modificada...\n");

    // --- TESTE: sc_lstmap ---
    t_list *lista_clonada = sc_lstmap(lista_original, transformar_adicionando_sinal, deletar_conteudo_mapeado);

    if (lista_clonada) {
        printf("Lista Mapeada:   [%s] -> [%s]\n", (char *)lista_clonada->content, (char *)lista_clonada->next->content);
    }

    // Limpeza das duas listas
    // Na original, os textos são fixos, então a função del não faz nada (pode ser um free vazio)
    t_list *tmp;
    while (lista_original) { tmp = lista_original->next; free(lista_original); lista_original = tmp; }
    
    // Na clonada, os textos foram criados dinamicamente, usamos sc_lstclear com free
    sc_lstclear(&lista_clonada, deletar_conteudo_mapeado);

    printf("\nMemorias limpas e teste concluido!\n");
    return 0;
}