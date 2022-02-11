
#include <stdio.h>


int main(void)
{
	//declarar a variável  altura
	int altura = 8;


	//inicia o contador linha
	for (int i = 1; i <= altura; i++)
	{
		//inicia o contador da coluna
		//aqui considera um bloco e o diminui para a direita
		for (int j = altura; j >= i; j--)
		{
			printf(" ");
		}

		//inicia o contador das #
		for (int k = 1; k <= i; k++)
		{
			printf("#");
		}

		//para cada linha pronta, adicione um espaço entre as pirâmides
		printf(" ");

		//inicia o contador da pirâmiede oposta
		//para cada coluna, enquanto a coluna for menor ou igual a linha, adicione uma #
		for (int g = 1; g <= i; g++)
		{
			printf("#");
		}
		
		//quebra a linha a cada ciclo
		printf("\n");


	}

}

