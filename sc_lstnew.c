#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

//cria uma variavel que pode armazenar dados de qualquer tipo
typedef struct s_list{
    void *content;
    struct s_list *next;
}t_list;

t_list *sc_lstnew(void *content) {
    t_list *new_node;

    new_node = (t_list*)malloc(sizeof(t_list));
    if(new_node == NULL)
        return (NULL);
    new_node->content = content;
    new_node->next = NULL;
    return (new_node);
}
//Functio  lines

void sc_lstadd_front(t_list **lst, t_list *new) {
    if (lst == NULL || new == NULL)
        return;
    new->next = *lst;
    *lst = new;
}

int main(void) {
    t_list *minha_lista = NULL; //Crie uma lista
    t_list *no_b = sc_lstnew("Vagão B"); // Criei um NO
    sc_lstadd_front(&minha_lista: %s\n\n", (char *)minha_lista->content);
    t_list *no_a =sc_lstnew("Vagão A");
    sc_lstadd_front(&minha_lista, no_a);
    printf("Novo inicio da lista: %s\n", (char *)minha_lista->content);
    printf("Proximo elemento da lista(next): %s\n",(char *)minha_lista->next->content);
    free (no_a);
    free (no_b);
    return 0;
}






int main(void) {
    char *txt1 = "Primeiro No";
    char *txt2 = "Segundo No";
    char *txt3 = "Terceiro No";

    t_list *no1 = sc_lstnew(txt1);
    t_list *no2 = sc_lstnew(txt2);
    t_list *no3 = sc_lstnew(txt3);
    
    printf("Testando SC_LSTNEW\n");
    if(no1 != NULL) {
        printf("No 1 criado com sucesso.\n");
        printf("Endereço do No 1: %p\n", (void *)no1);
        printf("Conteudo (char):%s\n", (char *)no1->content);
        printf("Proximo No (next): %p (NULL)\n", (void *) no1->next);
    }
    if(no2 != NULL) {
        printf("No 2 criado com sucesso.\n");
        printf("Endereço do No 2: %p\n", (void *)no2);
        printf("Conteudo (char):%s\n", (char *)no2->content);
        printf("Proximo No (next): %p (NULL)\n", (void *) no2->next);
    }
    if(no3 != NULL) {
        printf("No 3 criado com sucesso.\n");
        printf("Endereço do No 3: %p\n", (void *)no3);
        printf("Conteudo (char):%s\n", (char *)no3->content);
        printf("Proximo No (next): %p (NULL)\n", (void *) no3->next);
    }

    free(no1);
    free(no2);
    free(no3);

    return (0);
}