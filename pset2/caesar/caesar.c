#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    //Testando os inputs do programa
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (argv[1][i] < 48 || argv[1][i] > 57)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }  
    }
    

    //Definindo a variável key com o n° disponibilizado no input
    string k = argv[1];
    int key = atoi(k);

    //Aceitando o texto/palavra do usuário
    string word = get_string("plaintext: ");

    //Cipher
    printf("ciphertext: ");
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
        {
        	//Rotacionando o cipher apenas dentro do alfabeto
            char c = (((word[i] - 97) + key) % 26);
            printf("%c", c + 97);
        }
        else if (word[i] >= 'A' && word[i] <= 'Z')
        {
            char c1 = (((word[i] - 65) + key) % 26);
            printf("%c", c1 + 65);
        }
        else
        {
            printf("%c", word[i]);
        }
    }
    printf("\n");
    return 0;
}
