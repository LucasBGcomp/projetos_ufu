/*Crie um programa C que receba strings e as imprima em ordem alfabética.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{

    setlocale(LC_ALL, "Portuguese_Brazil");

    int nstrings;
    do{
    printf("Quantos nomes deseja inserir? (mín 2): ");
    scanf("%d", &nstrings);
    fflush(stdin);
    }while (nstrings < 2);

    char strings[nstrings][50];

    for (int i = 0; i < nstrings; i++)
    {
        printf("Insira o nome %d: ", i + 1);
        scanf("%49[^\n]", strings[i]);
        fflush(stdin);
    }

    char temp[50];
    for (int i = 0; i < nstrings - 1; i++)
    {
        for (int j = i + 1; j < nstrings; j++)
        {
            if (strcmp(strings[i], strings[j]) > 0)
            {
                strcpy(temp, strings[i]);
                strcpy(strings[i], strings[j]);
                strcpy(strings[j], temp);
            }
        }
    }

    printf("\nNomes em ordem alfabética:\n");
    printf("=============================\n\n");

    for (int i = 0; i < nstrings; i++)
    {
        printf("- %s\n", strings[i]);
    }

    printf("\n=============================\n");

    system("pause");
    return 0;

}