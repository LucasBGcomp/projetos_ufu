/*Faça um programa para ler as dimensões de um terreno (comprimento C e largura L), bem como o
preço do metro do arame, P. Calcule e imprima o custo para cercar o terreno com uma cerca de 5 fios.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

    float comprimento, largura, preco_metro, custo_total;
    float perimetro, quantidade_arame;

    printf("Digite o comprimento e a largura do terreno (metros):\n");
    scanf("%f %f", &comprimento, &largura);
    system("pause");

    printf("Digite o preco do metro do arame (R$):\n");
    scanf("%f", &preco_metro);

    perimetro = 2 * (comprimento + largura);
    quantidade_arame = perimetro * 5; // 5 fios
    custo_total = quantidade_arame * preco_metro;

    printf("O custo total para cercar o terreno com 5 fios de arame e de R$%.2f\n", custo_total);

    system("pause");
    return 0;
}