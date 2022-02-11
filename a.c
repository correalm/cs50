#include <stdio.h>
#include <cs50.h>
#include <string.h>


int main(int argc,string argv[])
{
    
    if (argc != 2) 
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (argv[1][0] < '0' || argv[1][0] > '9')
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    printf("Success\n");
    int key = argv[1][0] - 48;
    printf("%i\n", key);

    
}
