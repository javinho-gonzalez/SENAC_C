#include <unistd.h>
#include <stdio.h>

void sc_swap(int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;

}
void sc_sort_int_tab(int *tab, int size){

    int i;

    while ((size-1) > 0){

        i=0;
        while(i < size-1){

             if (tab[i] > tab[i+1]){
                  sc_swap(&tab[i], &tab[i+1]);
             }
             i++;
        }
        size--;
    }
}
void sc_sort_int_tab_2(int *tab, int size){

    int i;

    i=0;
    while(i < size){
        if (tab[i] > tab[i+1])
            sc_swap(&tab[i], &tab[i+1]);
        i++;
    }
}
int main (void){
    int tab[] = {5,2,9,1,5,6};
    int size = 6;
    int i;

    for(i = 0; i < size; i++)
        printf("%d ", tab[i]);
    printf("\n");
    sc_sort_int_tab(tab,size);
    for (i = 0; i < size; i++)
         printf("%d ", tab[i]);
    printf("\n");

    return 0;
}