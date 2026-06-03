#include <unistd.h>
#include <stdio.h>

void sc_swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sc_countdown(int *tab, int size){
    int i = 0;
    int cont = size-1;
    printf("Contador: %d\n",tab[cont]);

    while (i < cont){
        sc_swap(&tab[i], &tab[cont]);
        i++;
        cont--;
    }
}
int main (void){
    int num[]={123456789};
    int size = 9;

    sc_countdown(num,size);
    printf("Numeros decerescentes: ");

    for (int i = 0; i < size; i++){
        printf("%d", num[i]);
    }
printf("\n");
return 0;
}