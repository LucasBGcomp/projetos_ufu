/*Crie um programa, em linguagem C, que calcula o máximo divisor comum MDC de dois números
seguindo os passos:
- criar a função mdc em um arquivo separado (mdc.c) e definir o protótipo em um header (mdc.h)
- criar um arquivo main.c que utiliza a função mdc para calcular o resultado e exibir ao usuário.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "mdc.h"

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    int num1, num2;
    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    printf("O MDC de %d e %d é: %d\n", num1, num2, mdc(num1, num2));

    system("pause");
    return 0;
}