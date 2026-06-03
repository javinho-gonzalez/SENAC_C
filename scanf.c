#include <stdio.h>

int main() {
    int idade;
    float altura;
    char genero;
    double peso;
    char nome[50];

    printf("Digite a sua idade:");
    scanf("%d", &idade);
    printf("Digite a sua altura:");
    scanf("%f", &altura);
    printf("Digite o seu peso:");
    scanf("%lf", &peso);
    printf("Digite o seu genero (M/F):");
    scanf(" %c", &genero);
    printf("Digite o seu nome:");
    scanf("%s", &nome);

    printf("Sua idade é %i\n",idade);
    pintf("Seu peso é %lf\n",peso);
    printf("Sua altura é %f\n",altura);
    printf("Seu genero é %c\n",genero);
    printf("Seu nome é %s\n",nome);
    return 0;

}