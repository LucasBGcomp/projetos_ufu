/*Dados três valores, A, B e C, verificar se eles podem ser valores dos lados de um triângulo e, se forem,
qual é o tipo do triângulo (equilátero, isósceles ou escaleno), considerando os seguintes conceitos:*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main () {

    setlocale(LC_ALL, "pt_BR.UTF-8");

    float A, B, C;

    printf("Digite o valor do lado A: ");
    scanf("%f", &A);
    printf("Digite o valor do lado B: ");
    scanf("%f", &B);
    printf("Digite o valor do lado C: ");
    scanf("%f", &C);

    if (A + B <= C || A + C <= B || B + C <= A) {

        printf("Os valores informados não formam um triângulo. \n");
        system("pause");
        return 0;

    }

    if (A == B && B == C) {

        printf("O triângulo é equilátero. \n");

    }
    else if ( A == B || B == C || A == C) {

        printf("O triângulo é isósceles. \n");

    }
    else {

        printf("O triângulo é escaleno. \n");

    }

    system("pause");
    return 0;

}