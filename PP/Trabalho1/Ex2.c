/*Escreva um programa em Linguagem C para calcular o valor de y a partir de x dado pelo usuário, segundo a
função y(x) = 3x - 2, num domínio de números inteiros.*/

#include <stdio.h>

int main() {

    int x, y;
    scanf("%d", &x);
    y = 3 * x - 2;
    printf("%d\n", y);
    return 0;

}