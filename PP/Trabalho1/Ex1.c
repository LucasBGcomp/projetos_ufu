/*Sabendo que 1Km correponde a 0,621371 milha, escreva um programa em Linguagem C que leia uma distância dada em Km e a converta para milhas.*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    float km, milhas;
    scanf("%f", &km);
    milhas = km * 0.621371;
    printf("%f\n", milhas);
    system("pause");
    return 0;

}