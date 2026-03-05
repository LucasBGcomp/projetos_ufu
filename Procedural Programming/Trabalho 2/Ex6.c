/*Autores: Lucas Espíndula Borges, André Moraes Rodrigues, Gabriel dos Santos do Amaral*/

#include <stdio.h>
#include <stdlib.h>

void troca(int *x, int *y){
    if (*x < *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
    }
}


int main(){
    int x, y;

    scanf("%d %d", &x, &y);

    troca(&x, &y);

    printf("%d %d", x, y);
}