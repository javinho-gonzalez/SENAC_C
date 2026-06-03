#include <unistd.h>
#include <stdio.h>

void sc_swap(int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;

}
void sc_rev_int_tab(int *tab, int size){
    int i = 0;
    int j = size -1;

    printf("Array:%d\n", tab[j]);

    while (i < j){
        sc_swap(&tab[i], &tab[j]);
        i++;
        j--;
    }
}
int main(void){

    int arr[] = {1,2,3,4,5};
    int size = 5;

    printf("orignal array: ");
    for (int i=0; i < size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    sc_rev_int_tab(arr,size);
    printf("Reverse array: ");
    for (int i=0; i < size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}