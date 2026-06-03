#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv) {
    int idade;
    float peso;
    char nome [10];
    // Numero de argumentos 
    printf("Quantidade de argumentos: %i\n", argc);
    if (argc != 4) {
        printf("Erro ! Numero de argumentos invalido");
        return 0;
    }
    else{
        int i = 0;
        while(i<4) {
            printf("Argumento %i: %s\n", i, argv[i]);
            i++;
        }

    }
    return 0;
}