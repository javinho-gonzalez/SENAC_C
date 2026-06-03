#include <unistd.h>

void sc_putchar(char c) {
    write(1, &c, 1);
}
//function lines

void sc_putnbr(int nbr) {
    if(nbr == -2147483648) {
        sc_putchar('-');
        sc_putchar('2');
        sc_putnbr(147483648);
    }
    else if (nbr < 0) {
        sc_putchar('-');
        sc_putnbr(-nbr);
    }
    else if (nbr >= 10){
        sc_putnbr(nbr / 10);
        sc_putchar((nbr % 10) + '0');
    }
    else sc_putchar(nbr + '0');
}
//Function lines
int main (void) {
    int i = 258;
    int x = 45687;
    int z = -4584893;
    int n = -2147483648;

    sc_putnbr(i);
    write(1, &"\n", 1);
    sc_putnbr(x);
    write(1, &"\n", 1);
    sc_putnbr(z);
    write(1, &"\n", 1);
    sc_putnbr(n);
    write(1, &"\n", 1);

    return 0;
    
    
}