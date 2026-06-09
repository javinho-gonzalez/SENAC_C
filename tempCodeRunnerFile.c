//#include <unistd.h>

//int main(void)
//{
//write(1, "Hello, World!\n", 14);
//return 0;
//}

//#include <unistd.h>

//int main(void)
//{
//char a = 65;
//write(1, &a, 1);
//write(1, "\n", 1);
//return 0;
//}

//#include <unistd.h>
//int main (void)
//{
//char x = 65;
//while(x <= 90)
//{
//write (1, &x, 1);
//x++;
//}
//write (1, "\n", 1);
//return 0;
//}

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

//int main (void)
//{
//char nome[] = "Hello, World!";
//int i = 0;

//while(nome[i])
//{
//sc_putchar(nome[i]);
//i++;
//}
//sc_putchar('\n');
//return 0;
//}

//#include <unistd.h>
//void sc_putchar(char c)
//{
 //write(1, &c, 1);
//}

//--FUNCTION LINES:1--

//int main (void)
//{
//char nome[] = "Hello, World!";
//int i = 0;

//while(nome[i])
//{
//sc_putchar(nome[i]);
//i++;

//sc_putchar('\n');
//return 0;
//}

//#include <stdio.h>
//#include <ctype.h>
//int main () {
    //char lower = 'g';
    //char upper = toupper((unsigned char)lower);
    //printf("Original:%c,Uppercase:%c\n",lower,upper);
    //return 0;
//}


