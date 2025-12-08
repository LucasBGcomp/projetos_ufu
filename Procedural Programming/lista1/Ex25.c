/*Dados três valores, A, B e C, verificar se eles podem ser valores dos lados de um triângulo e, se forem,
qual é o tipo do triângulo (equilátero, isósceles ou escaleno), considerando os seguintes conceitos:*/

#include <stdio.h>
#include <stdlib.h>

int main () {

    float A, B, C;

    printf("Digite o valor do lado A: ");
    scanf("%f", &A);
    printf("Digite o valor do lado B: ");
    scanf("%f", &B);
    printf("Digite o valor do lado C: ");
    scanf("%f", &C);

    if (A + B <= C || A + C <= B || B + C <= A) {

        printf("Os valores informados nao formam um triangulo. \n");
        system("pause");
        return 0;

    }

    if (A == B && B == C) {

        printf("O triangulo e equilatero. \n");

    }
    else if ( A == B || B == C || A == C) {

        printf("O triangulo e isosceles. \n");

    }
    else {

        printf("O triangulo e escaleno. \n");

    }

    system("pause");
    return 0;

}