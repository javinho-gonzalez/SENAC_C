#include <stdio.h>
#include <stdlib.h>

//Definição do nó
struct No {
    int valor;
    struct No* proximo;
};
int main () {
    //Criando os nós manualmente
    struct No* cabeca = malloc(sizeof(struct No));
    struct No* segundo = malloc(sizeof(struct No));

    cabeca->valor = 10;
    cabeca->proximo = segundo; // O primeiro aponta para o segundo

    segundo->valor = 20;
    segundo->proximo = NULL; //Fim da lista

    // Percorrendo a lista
    struct No* atual = cabeca;
    while (atual != NULL) {
        printf("Valor no No: %d\n", atual->valor);
        atual = atual->proximo;
    }

    //Importante em C: Liberar memoria alocada!
    free(cabeca);
    free(segundo);

    return 0;
}