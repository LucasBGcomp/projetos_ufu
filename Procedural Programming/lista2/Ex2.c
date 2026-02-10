/*Abra e leia o arquivo criado no exercício anterior, caractere por caractere, escreva na tela todos os
caracteres e mostre na tela quantas letras são vogais e quantas são consoantes.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{

    setlocale(LC_ALL, "Portuguese_Brazil");

    FILE *fp;
    fp = fopen("Ex1_arq.txt", "r");
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    char c;
    int vogais = 0, consoantes = 0;
    printf("Conteúdo do arquivo: ");
    while ((c = fgetc(fp)) != EOF)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            {
                vogais++;
            }
            else
            {
                consoantes++;
            }
        }
        printf("%c", c);
    }

    printf("\nQuantidade de vogais: %d\n", vogais);
    printf("\nQuantidade de consoantes: %d\n\n", consoantes);

    fclose(fp);
    system("pause");
    return 0;
}