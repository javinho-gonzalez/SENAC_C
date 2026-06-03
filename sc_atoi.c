#include <stdio.h>

int sc_atoi (const char *str){
    int resultado = 0;
    int sinal = 1;
    int i = 0;
    //ignora espaços em branco no inicio
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'){
        i++;
    }
    //verifica se existe sinal de mais ou menos
    if (str[i] == '-' || str[i] == '+'){
        if (str[i] == '-'){
            sinal = -1;
        }
        i++;
    }

    //converte os caracteres numericos
    while (str[i] >= '0' && str[i] <= '9'){
        //Multiplicação do resultado anterior por 10 e adição do novo digito
        resultado = (resultado*10) + (str[i] - '0');
        i++;
    }
    //Retorna o valor final com o sinal correto
    return resultado*sinal;
}
int main (){
    //Testes da função
    const char str[] = "  -2458";
    printf("Resultado: %d\n", sc_atoi(str));
    return 0;
}
