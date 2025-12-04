/*Escreva um programa em Linguagem C que leia dois valores positivos (como float), a altura e o raio de um cilindro circular, e imprima o volume do cilindro. O volume de um cilindro circular é calculado por meio da seguinte fórmula: volume = pi * raio2 * altura. Considere pi = 3.141592. O resultado deve ser impresso no padrão float, com 6 casas decimais.*/

#include <stdio.h>

int main(void) {

    #define pi 3.141592

    float altura, raio, volume;

    scanf("%f %f", &altura, &raio);
    volume = pi * raio * raio * altura;

    printf("%f\n", volume);
    return 0;

}