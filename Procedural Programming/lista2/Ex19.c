/*Escreva uma função que receba, como parâmetro, três valores, X, Y e Z, e verifique se seguimentos
de reta com essas medidas podem formar um triângulo (o comprimento de cada lado de um triângulo é
menor do que a soma dos outros dois lados) e, em caso afirmativo, qual o tipo de triângulo. A função
deve retornar:
? 0: se não for triângulo.
? 1: se for triângulo escaleno (3 lados diferentes).
? 2: se for triângulo isósceles (2 lados iguais).
? 3: se for triângulo equilátero (3 lados iguais).*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int forma_triangulo(float x, float y, float z)
{
    if (x < (y + z) && y < (x + z) && z < (x + y))
    {
        if (x == y && y == z)
        {
            return 3; // equilátero
        }
        else if (x == y || y == z || x == z)
        {
            return 2; // isósceles
        }
        else
        {
            return 1; // escaleno
        }
    }
    else
    {
        return 0; // não forma um triângulo
    }
}

int main()
{

    setlocale(LC_ALL, "Portuguese_Brazil");

    float x, y, z;
    printf("Digite o valor do lado 1: ");
    scanf("%f", &x);
    setbuf(stdin, NULL);

    printf("\nDigite o valor do lado 2: ");
    scanf("%f", &y);
    setbuf(stdin, NULL);

    printf("\nDigite o valor do lado 3: ");
    scanf("%f", &z);

    int resultado = forma_triangulo(x, y, z);

    switch (resultado)
    {

    case 0:
        printf("\nOs lados não formam um triângulo!\n\n");
        break;
    case 1:
        printf("\nOs lados formam um triângulo escaleno!\n\n");
        break;
    case 2:
        printf("\nOs lados formam um triângulo isósceles!\n\n");
        break;
    case 3:
        printf("\nOs lados formam um triângulo equilátero!\n\n");
        break;
    }

    system("pause");
    return 0;
}