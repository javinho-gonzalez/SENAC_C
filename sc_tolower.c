#include <unistd.h>

int sc_tolower(int c)
{
    if(c >= 65 && c <= 90)
        return (c + 32);
    return (c);
}
//------Function : 3 -----
int main (void)
{
    char str [] = "HELLO, WORLD";
    int i = 0;

    while (str[i])
    {
        str [i] =  sc_tolower (str[i]);
        write(1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
    return 0;
}