#include <stdio.h>
#include <string.h>

int main () {
    //Array de enteiros (estatico)
    int notas[3] = {85,90,78};

    //String em C(Array de char)
    char curso[] = "Algoritmos";

    printf("Segunda nota: %d\n", notas [1]);
    printf("Curso: %s\n", curso);
    printf("Tamanho da string: %lu\n", strlen(curso));

    return 0;
}