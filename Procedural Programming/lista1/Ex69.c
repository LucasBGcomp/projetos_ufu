/*Crie um programa C que leia uma string do teclado e diga se ela é palíndromo. Uma string é
palíndromo quando pode ser lida tanto de trás pra frente quanto de frente para trás e possui
exatamente a mesma sequência de caracteres.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese_Brazil");

    char str[50];
    char ivt[50];

    printf("Digite uma palavra ou frase: ");
    fflush(stdin);
    scanf("%49[^\n]", str);

    for (int i = strlen(str) - 1; i >= 0 ; i--)
    {

        ivt[strlen(str) - 1 - i] = str[i];

    }

    ivt[strlen(str)] = '\0';

    if (strcmp(str, ivt) == 0)
    {

        printf("A string é um palíndromo.\n");
    }
    else
    {
        printf("A string não é um palíndromo.\n");

    }

    return 0;
}