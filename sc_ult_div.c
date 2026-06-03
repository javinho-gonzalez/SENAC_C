/*#include <unistd.h>
#include <stdio.h>
void sc_ult_div(int *a, int *b)
{
    int div,mod;
    if (*b == 0)
    {
        *a = 0;
        *b = 0;
        return;
    }
    div = *a / *b;
    mod = *a % *b;
    *a = div;
    *b = mod;
}
//Function Lines
int main (void)
{
    int a = 10;
    int b = 3;
    sc_ult_div (&a,&b);
    printf("Div: %d, Mod: %d \n",a,b);
    return 0;
}*/