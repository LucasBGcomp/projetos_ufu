#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    int n;
    int pista[100][100];

    do
    {
        printf("Digite o número de buracos na pista (de 0 a 1000): ");
        scanf("%d", &n);
    } while (n < 0 || n > 1000);

    int x, y;
    printf("\nAgora digite as coordenadas dos buracos (exceto (0,0)):\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("Digite as coordenadas do buraco %d (x y): ", i + 1);
        scanf("%d %d", &x, &y);
        pista[y][x] = 1; // Marca a posição do buraco na pista
    }

    char *caminho;
    caminho = (char *)malloc(10000 * sizeof(char)); 
    printf("\nDigite, sem espaços, o caminho a ser percorrido (direita = D, esquerda = E, frente = F, trás = T):\n");
    scanf(" %[^\n]", caminho);
    caminho = (char *)realloc(caminho, (strlen(caminho) + 1) * sizeof(char)); 

    int posX = 0, posY = 0; // Posição inicial do carrinho

    for (int i = 0; i < strlen(caminho); i++)
    {
        char direcao = caminho[i];
        if (direcao == 'D' && posX + 1 <= 99 && pista[posY][posX + 1] != 1)
        {
            posX++;
            continue;
        }
        else if (direcao == 'E' && posX - 1 >= 0 && pista[posY][posX - 1] != 1)
        {
            posX--;
            continue;
        }
        else if (direcao == 'F' && posY + 1 >= 0 && pista[posY + 1][posX] != 1)
        {
            posY++;
            continue;
        }
        else if (direcao == 'T' && posY - 1 >= 0 && pista[posY - 1][posX] != 1)
        {
            posY--;
            continue;
        }
        else
        {
            continue;
        }
    }

    printf("\n\nPosição final do carrinho: (%d, %d)\n\n", posX, posY);

    free(caminho);
    system("pause");
    return 0;
}