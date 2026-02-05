/*Crie uma estrutura para representar um vetor no R3, implemente um programa que calcule a soma de
dois vetores.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "Portuguese_Brazil");

    int n;

    do{
    printf("Quantos vetores deseja inserir? (mín 2) ");
    scanf("%d", &n);
    setbuf(stdin, NULL);
    } while (n < 2);

    typedef struct{
        float x, y, z;
    } vetor;

    vetor v[n];
    vetor resultante;

    for (int i = 0; i < n; i++){

        printf("Digite as coordenadas do vetor %d (x y z): ", i + 1);
        scanf("%f %f %f", &v[i].x, &v[i].y, &v[i].z);
        setbuf(stdin, NULL);

    }

    for (int i = 0; i < n; i++){

        resultante.x += v[i].x;
        resultante.y += v[i].y;
        resultante.z += v[i].z;

    }

    printf("\nO vetor resultante da soma dos %d vetores é: (%.2f ; %.2f ; %.2f)\n\n", n, resultante.x, resultante.y, resultante.z);

    system("pause");
    return 0;

}