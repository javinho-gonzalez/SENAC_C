#include <unistd.h>

void sc_putchar(char c)
{
write(1, &c, 1);
}

//--FUNCTION LINES:1--

int main (void)
{
 char x = 65;
while(x <= 90)
{
sc_putchar(x);
x++;
}
sc_putchar('\n');
return 0;
}

