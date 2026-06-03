//#include <unistd.h>
//#include <stdio.h>

//void sc_vector(int *nbr)
//{
    //*nbr = 42;
//}
//FUNCTION LINES

//int main (void)
//{
    //int nbr = 0;

    //printf("Before: %d\n", nbr);
    //sc_vector(&nbr);
    //printf("After: %d\n", nbr);
    //return 0;
//}

#include <unistd.h>
#include <stdio.h>

void sc_ult_vector(int*********nbr)
{
    *********nbr = 42;
}

//FUNCTION LINES

int main (void)
{
    int nbr = 0;
    int *ptr1 = &nbr;
    int **ptr2 = &ptr1;
    int ***ptr3 = &ptr2;
    int ****ptr4 = &ptr3;
    int *****ptr5 = &ptr4;
    int ******ptr6 = &ptr5;
    int *******ptr7 = &ptr6;
    int ********ptr8 = &ptr7;
    int *********ptr9 = &ptr8;

    printf("Before: %d\n", nbr);
    sc_ult_vector(ptr9);
    printf("After: %d\n",nbr);
    printf("Endereço de nbr: %p\n", (void *)&nbr);
    printf("Endereço de ptr9: %p\n", (void *)&ptr9);
    return 0;
}

