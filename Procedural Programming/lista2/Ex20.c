/*Escreva um programa C que crie um vetor de n inteiros, uma função que calcule a soma de seus
elementos e outra função que imprima o vetor.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void print(int vet[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n\n");
}

int somavet(int vet[], int n)
{
    int soma = 0;
    for (int i = 0; i < n; i++)
    {
        soma += vet[i];
    }
    return soma;
}

int main()
{

    setlocale(LC_ALL, "Portuguese_Brazil");

    int tam;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);
    setbuf(stdin, NULL);

    int vet[tam];

    for (int i = 0; i < tam; i++)
    {
        printf("Digite o %dº elemento: ", i + 1);
        scanf("%d", &vet[i]);
        setbuf(stdin, NULL);
    }
    printf("\nVetor digitado: ");
    print(vet, tam);
    printf("Soma dos elementos: %d\n", somavet(vet, tam));

    system("pause");
    return 0;
}