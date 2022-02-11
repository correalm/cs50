#include <stdio.h>
#include <cs50.h>
#include <math.h>


int main(void)
{
    //Iniciando as variáveis
    int a = 25;
    int b = 10;
    int c = 5;
    int d = 1;
    int coins = 0;
    float entrada1;

    //pegando um valor positivo do usuário
    do
    {
        entrada1 = get_float("Troco: ");
    }
    while (entrada1 <= 0);

    //arredondando os valores
    int entrada = round(entrada1 * 100);

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
    printf("Moedas: %i\n", coins);
}   
