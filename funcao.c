//#include <stdio.h>
//#include <ctype.h>
//int main () {
    //char lower = 'g';
    //char upper = toupper((unsigned char)lower);
    //printf("Original:%c,Uppercase:%c\n",lower,upper);
    //return 0;
//}

#include <stdio.h>
#include <ctype.h>
int main () {
    char str [] = "Hello World";

    for(int i = 0; str [i] != '\0'; i++){
        str [i] = toupper((unsigned char) str[i]);
    }
    printf("Upper: %s\n", str);  //Output: Hello World
    return 0;
}
//#include <unistd.h>

//int ex_tolower(int c)
//{
    //if(c >= 65 && c <= 90)
        //return (c + 32);
    //return (c);
//}
//------Function : 3 -----
//int main (void)
//{
    //char str [] = "HELLO, WORLD";
    //int i = 0;

    //while (str[i])
    //{
        //str [i] =  ex_tolower (str[i]);
        //write(1, &str[i], 1);
        //i++;
    //}
    //write(1, "\n", 1);
    //return 0;
//}

//#include <unistd.h>

//int sc_toupper(int c)
//{
   // if(c >= 97 && c <= 122)
        //return (c - 32);
    //return (c);
//}
//------Function : 3 -----
//int main (void)
//{
    //char str [] = "hello, world";
    //int i = 0;

    //while (str[i])
    //{
        //str [i] =  sc_toupper (str[i]);
        //write(1, &str[i], 1);
        //i++;
    //}
    //write(1, "\n", 1);
    //return 0;
//}