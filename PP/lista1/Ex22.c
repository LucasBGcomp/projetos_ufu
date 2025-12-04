/*Determine se um determinado ano lido é bissexto. Um ano é bissexto se for divisível por 400, ou se for
divisível por 4 e não for divisível por 100.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main () {

    setlocale(LC_ALL, "pt_BR.UTF-8");

    int ano;
    
    printf("Digite um ano: ");
    scanf("%d", &ano);

    if ((ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0))) {

        printf("O ano %d é bissexto.\n", ano);

    }
    else {

        printf("O ano %d não é bissexto.\n", ano);

    }

    system("pause");
    return 0;

}