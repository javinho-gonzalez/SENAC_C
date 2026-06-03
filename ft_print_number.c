#include <unistd.h>

void ft_print_number (void){
    int i = 48;
    while (i<=57){
        write (1,&i,1);
        i++;
    }
}
int main (void){
    ft_print_number();
    return 0;
}

