/*Uma disciplina tem 3 provas ao longo do semestre, com pesos 2, 3 e 3, respectivamente. Escreva um
programa em Linguagem C que leia as 3 notas de um aluno e calcule sua média ponderada final na
disciplina, imprimindo o resultado com 2 casas decimais.*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    #define pesop1 2
    #define pesop2 3
    #define pesop3 3

    float np1, np2, np3, media;

    scanf("%f %f %f", &np1, &np2, &np3);
    media = (np1 * pesop1 + np2 * pesop2 + np3 * pesop3) / (pesop1 + pesop2 + pesop3);
    printf("%.2f\n", media);
    system("pause");
    return 0;

}