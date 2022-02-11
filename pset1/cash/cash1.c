#include <stdio.h>
#include <math.h>


int main(void)
{
    //Iniciando as variáveis
    int a = 25;
    int b = 10;
    int c = 5;
    int d = 1;
    int coins = 0;
    
    int entrada = 30;

    //se houver entrada
    if (entrada > 0)
    {
        coins += (entrada / a);
        entrada = round((entrada % a));
    }

    //se o resto da divisão for maior que b
    if (entrada >= b)
    {
        coins += (entrada / b);
        entrada = round((entrada % b));
    }

    //se for maior que c
    if (entrada >= c)
    {
        coins += (entrada / c);
        entrada = round((entrada % c));
    }

    //se for maior que d
    if (entrada >= d)
    {
        coins += (entrada / d);   
    }

    //exibindo o n° de moedas ao usuário
    printf("Moedas: %i\n", coins );
}