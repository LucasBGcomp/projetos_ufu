/*Construa um programa que calcule o determinante de uma matriz de inteiros, tamanho 3 x 3, usando a Regra de Sarrus. Você deve obrigatoriamente usar um arranjo bidimensional 3 x 3 para representar os dados e um laço duplo para fazer a leitura da matriz, manipulando apenas os índices para calcular o determinante. Assuma que os 9 elementos que compõem a matriz são dados sequencialmente, linha por linha (isto é, elemento da 1ª linha com a 1ª coluna; depois, elemento da 1ª linha com a 2ª coluna; depois, elemento da 1ª linha com a 3ª coluna; depois, elemento da 2ª linha com a 1ª coluna; e assim por diante).*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int matriz[3][3], determinante;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            scanf("%d", &matriz[i][j]);
        }
        printf("\n");
    }

    determinante = matriz[0][0] * (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1]) -
                   matriz[0][1] * (matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0]) +
                   matriz[0][2] * (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]);

    printf("%d\n", determinante);
    system("pause");
    return 0;
}