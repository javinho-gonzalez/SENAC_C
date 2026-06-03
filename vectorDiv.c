/*#include <unistd.h>
#include <stdio.h>

void sc_div_mod (int a, int b,  int *div, int *mod)
{
    if (b==0)
    {
        *div = 0;
        *mod = 0;
        return;
    }
    *div = a / b;
    *mod = a % b;
}
//Function Lines
int main (void)
{
    int a = 10;
    int b = 3;
    int div,mod;

    sc_div_mod(a,b,&div,&mod);
    printf("Numeros: %d %d,Div: %d, Mod: %d \n",a,b,div,mod);
    return 0;
}*/