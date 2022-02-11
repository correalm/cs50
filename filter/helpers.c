#include "helpers.h"
#include <stdio.h>
#include <math.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Para cada cor há uma fórmula específica
            // se o valor da fórmula for superior ao máximo de bits, então o valor deve ser igual ao máximo
            int sepiaRed = round((.393 * image[i][j].rgbtRed) + (.769 * image[i][j].rgbtGreen) + (.189 * image[i][j].rgbtBlue));
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            int sepiaGreen = round((.349 * image[i][j].rgbtRed) + (.686 * image[i][j].rgbtGreen) + (.168 * image[i][j].rgbtBlue));
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            int sepiaBlue = round((.272 * image[i][j].rgbtRed) + (.534 * image[i][j].rgbtGreen) + (.131 * image[i][j].rgbtBlue));
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            //Passando os novos valores para a imagem
            //Nesse caso não é necessária uma imagem temporária
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //Preciso da imagem tmp pois, se não, só conseguiria fazer meia imagem
    RGBTRIPLE tmp[height][width];
    //Interando as colunas com as linhas
    for (int i = 0; i < height; i++)
    {
        for (int j = 1; j < width; j++)
        {
            //tmp armazena as linhas ao contrário, mantendo as colunas
            //Por isso width - j
            tmp[i][j] = image[i][width - j];
        }
    }
    //Interando novamente
    for (int i = 0; i < height; i++)
    {
        for (int j = 0;j < width; j++)
        {
            //Copiando a temporária para a imagem final
            image[i][j] = tmp[i][j];
        }
    }
    return;
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Dentro de cada pixel
            float blue = 0;
            float red = 0;
            float green = 0;
            int count = 0;
            for (int c = -1; c < 2; c++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if (i + c < height && j + l < width && i + c >= 0 && j + l>= 0 )
                    {
                        blue += image[i + c][j + l].rgbtBlue;
                        red += image[i + c][j + l].rgbtRed;
                        green += image[i + c][j + l].rgbtGreen;
                        count++;
                    }
                }
                    
            }
            tmp[i][j].rgbtBlue = round(blue / count);
            tmp[i][j].rgbtRed = round(red/ count);
            tmp[i][j].rgbtGreen = round(green / count);
            image[i][j].rgbtBlue = tmp[i][j].rgbtBlue;
            image[i][j].rgbtRed = tmp[i][j].rgbtRed;
            image[i][j].rgbtGreen = tmp[i][j].rgbtGreen;
        }
    }
    return;
}
