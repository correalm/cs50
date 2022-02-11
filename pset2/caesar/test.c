#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc > 2)
    {
        printf("ERRO\n");
    }
    printf("OLA %s\n", argv[1]);

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        for (int j = 0, o = strlen(argv[1]))
        {
            
        }
    }


    string word = get_string("Word: ");

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        word[i] += key;
    }
    printf("%s\n", word);
}