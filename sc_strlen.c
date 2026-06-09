#include <unistd.h>
#include <stdio.h>

int sc_strlen (char *str)
{
    int len = 0;
    while(str[len]!='\0')
    len++;
return len;
}
//Function Lines
int main ()
{
    char *str = "hello, world";
    int length = sc_strlen(str);
    printf("Length of the string: %d \n",length);
    return 0;
} 