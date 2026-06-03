#include <unistd.h>

int sc_toupper(int c)
{
    if(c >= 97 && c <= 122)
        return (c - 32);
    return (c);
}
//------Function : 3 -----
int main (void)
{
    char str [] = "hello, world";
    int i = 0;

    while (str[i])
    {
        str [i] =  sc_toupper (str[i]);
        write(1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
    return 0;
}