#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "bib.h"

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    int n;
    printf("Digite a ordem da matriz quadrada: ");
    scanf("%d", &n);

    int M[n][n];
    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &M[i][j]);
        }
    }

    printf("\n\nSoma de todos os elementos: %d\n", soma(n, M));
    printf("Soma da diagonal principal: %d\n", soma_dp(n, M));
    printf("Soma da diagonal secundária: %d\n", soma_ds(n, M));
    printf("A matriz é simétrica? %s\n", is_simetrica(n, M) ? "Sim" : "Não");
    printf("A matriz é um quadrado mágico? %s\n\n", is_qm(n, M) ? "Sim" : "Não");

    system("pause");
    return 0;
}