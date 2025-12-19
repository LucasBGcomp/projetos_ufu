/*Leia duas matrizes, M1 e M2, de dimens√µes 3 x 3. Crie uma nova matriz M3, tamb√©m de dimens√£o 3x3
e a preencha com os maiores elementos de M1 e M2 na posi√ß√£o correspondente.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{

    setlocale(LC_ALL, "Portuguese_Brazil");

    int m1[3][3], m2[3][3], m3[3][3];

    printf("Digite a matriz M1 (3x3):\n");

    for (int i = 0; i < 3; i++)
    {

        scanf("%i %i %i", &m1[i][0], &m1[i][1], &m1[i][2]);
    }

    printf("\nDigite a matriz M2 (3x3):\n");

    for (int i = 0; i < 3; i++)
    {

        scanf("%i %i %i", &m2[i][0], &m2[i][1], &m2[i][2]);
    }

    printf("A matriz M3 (3x3) ser· formada pelos maiores valores de cada posiÁ„o das matrizes M1 e M2:\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            if (m1[i][j] > m2[i][j])
            {

                m3[i][j] = m1[i][j];
            }
            else
            {

                m3[i][j] = m2[i][j];
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {

        printf("%.2i %.2i %.2i", m3[i][0], m3[i][1], m3[i][2]);
        printf("\n");
        
    }

    system("pause");
    return 0;
}