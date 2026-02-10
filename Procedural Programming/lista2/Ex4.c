/*Escreva um programa C para gerar em um arquivo as tabuadas de 1 a 10.*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *fp;
    fp = fopen("Ex4_arq.txt", "w");
    if (fp == NULL){
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    for (int i = 1; i <= 10; i++){
        for (int j = 1; j <= 10; j++){
            fprintf(fp, "%d x %d = %d\n", i, j, i * j);
        }
        fprintf(fp, "\n");
    }

    printf("Arquivo com tabuada de 1 a 10 criado com sucesso!\n\n");

    fclose(fp);
    system("pause");
    return 0;
}