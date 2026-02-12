/*Escreva um programa C que:
a. Crie um arquivo texto de nome ?arq.txt?.
b. Permita que o usuário entre com diversos caracteres nesse arquivo, até que seja digitado
ENTER.
c. Feche o arquivo.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{

    setlocale(LC_ALL, "Portuguese_Brazil");

    FILE *fp;
    fp = fopen("Ex1_arq.txt", "w");
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo!!\n");
        exit(1);
    }

    char c;
    printf("Digite os caracteres para o arquivo (pressione ENTER para finalizar):\n");
    while ((c = fgetc(stdin)) != '\n')
    {

        fputc(c, fp);
    }

    fclose(fp);
    system("pause");
    return 0;
}