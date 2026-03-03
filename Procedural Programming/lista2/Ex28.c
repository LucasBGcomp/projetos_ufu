/*Faça um programa que leia três valores inteiros e chame uma função que receba estes 3 valores de
entrada e os retorne ordenados, ou seja, o menor valor na primeira variável, o segundo menor valor na
variável do meio, e o maior valor na última variável. A função deve retornar o valor 1 se os três valores
forem iguais e 0 se existirem valores diferentes. Exibir os valores ordenados na tela.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int ordenar(int *x, int *y, int *z)
{
    int temp;
    if (*x == *y && *y == *z)
    {
        return 1;
    }
    else
    {
        if (*x > *y)
        {
            temp = *x;
            *x = *y;
            *y = temp;
        }
        if (*y > *z)
        {
            temp = *y;
            *y = *z;
            *z = temp;
        }
        if (*x > *y)
        {
            temp = *x;
            *x = *y;
            *y = temp;
        }
        return 0;
    }
}

int main()
{

    setlocale(LC_ALL, "Portuguese_Brazil");

    int x, y, z;
    printf("Digite o valor de x: ");
    scanf("%d", &x);
    setbuf(stdin, NULL);

    printf("\nDigite o valor de y: ");
    scanf("%d", &y);
    setbuf(stdin, NULL);

    printf("\nDigite o valor de z: ");
    scanf("%d", &z);
    setbuf(stdin, NULL);

    if (ordenar(&x, &y, &z))
    {
        printf("\nOs números são iguais!\n\n");
    }
    else
    {
        printf("\nNúmeros ordenados: %d, %d, %d\n\n", x, y, z);
    }

    system("pause");
    return 0;
}