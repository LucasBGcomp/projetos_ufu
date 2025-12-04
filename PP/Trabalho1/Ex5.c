/*Faça um programa para verificar se um determinado ano lido é bissexto, imprimindo “SIM” em caso afirmativo ou “NAO”, caso contrário. Um ano é bissexto se for divisível por 400, ou se for divisível por 4 e não for divisível por 100.*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int ano;

    scanf("%d", &ano);

    if ((ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0)) {
        printf("SIM\n");
    } else {
        printf("NAO\n");
    }
    system("pause");
    return 0;

}