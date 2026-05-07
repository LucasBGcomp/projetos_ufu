/*Implemente uma funçao que calcule as raizes de uma equaçao do segundo grau do tipo Ax2 + Bx + C = 0. 
Lembrando que:
X = (-B ± ??)/2A
Onde
? = B^2 - 4AC
A variavel A tem que ser diferente de zero. ´
Se ? < 0 nao existe real.
Se ? = 0 existe uma raiz real.
Se ? > 0 existem duas raizes reais.
Essa func¸ao deve obedecer ao seguinte prototipo: ´
int raizes(float A,float B,float C,float * X1,float * X2);
Essa funçao deve ter como valor de retorno o numero de raizes reais e distintas da
equaçao. Se existirem raizes reais, seus valores devem ser armazenados nas variaveis
apontadas por X1 e X2.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "roots.h"

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    float A, B, C, X1, X2;
    do
    {
        printf("Digite os coeficientes A, B e C da equação do segundo grau (A != 0): ");
        scanf("%f %f %f", &A, &B, &C);
    } while (A == 0);

    int num_raizes = raizes(A, B, C, &X1, &X2);

    switch (num_raizes)
    {
    case 0:
        printf("\nNão existem raízes reais.\n\n");
        break;
    case 1:
        printf("\nExiste uma raiz real: X = %.2f\n\n", X1);
        break;
    case 2:
        printf("\nExistem duas raízes reais: X1 = %.2f e X2 = %.2f\n\n", X1, X2);
        break;
    }

    system("pause");
    return 0;
}