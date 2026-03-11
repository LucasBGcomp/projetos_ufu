/*Autores: Lucas Espíndula Borges, 
André Moraes Rodrigues, 
Gabriel dos Santos do Amaral, 
João Vitor de Queiroz Pereira.*/

#include <stdio.h>
#include <stdlib.h>

int f(int x, int n){
    if (n == 0){
        return 1;
    } else {
        return x * f(x, n - 1);
    }
}

int main(){
    int x, n, r;

    scanf("%d %d", &x, &n);

    if (x < 0 || n < 0){
        printf("Erro");
    } else {
        r = f(x, n);
        printf("%d", r);
    }
}