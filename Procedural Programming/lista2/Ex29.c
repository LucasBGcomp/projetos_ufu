/*Crie um programa que contenha um array de float contendo 10 elementos. Imprima o endereço de
cada posição desse array.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{

    setlocale(LC_ALL, "Portuguese_Brazil");

    float vet[10];
    float *p = vet;

    for (int i = 0; i < 10; i++)
    {
        printf("O endereço do %dº elemento do vetor é: %p\n", i + 1, p + i);
    }
    printf("\n");

    system("pause");
    return 0;
}