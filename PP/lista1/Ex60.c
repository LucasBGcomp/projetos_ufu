/*Os incas ficaram conhecidos pela grande civilização que reinou na região dos Andes durante vários
séculos. O que pouca gente sabe é que os incas construíram pirâmides de base quadrada em que a
única forma de se atingir o topo era seguir em espiral pela borda, que acabava formando uma escada
em espiral. Estas pirâmides ainda se encontram escondidas na floresta amazônica e sua descoberta
trará uma aplicação para este exercício. Neste problema você deverá fazer um programa para verificar
se uma matriz quadrada de dimensão 4 com números inteiros é ou não inca. A matriz é inca quando,
partindo do canto superior esquerdo da matriz, no sentido horário, em espiral, for possível verificar que
a posição seguinte na ordem é o inteiro consecutivo da posição anterior.*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int m1[4][4];

    printf("Digite os elementos da matriz 4x4:\n");

    for (int i = 0; i < 4; i++){

        scanf("%d %d %d %d", &m1[i][0], &m1[i][1], &m1[i][2], &m1[i][3]);

    }

    int i = 0, j = 0;

    do{

        if (j < 3){
            if (m1[i][j] == m1[i][j+1] - 1){
                j++;
                continue;
            }else{
                printf("A matriz nao e inca!");
                return 0;
            }
        } else {
            if (i < 3){
                if (m1[i][j] == m1[i+1][j] - 1){
                    i++;
                    continue;
                } else {
                    printf("A matriz nao e inca!");
                    return 0;
                }
            } else {
                if (j > 0){
                    if (m1[i][j] == m1[i][j-1] - 1){
                        j--;
                        continue;
                    } else {
                        printf("A matriz nao e inca!");
                        return 0;
                    }
                } else {
                    if (i > 1){
                        if (m1[i][j] == m1[i-1][j] - 1){
                            i--;
                            continue;
                        } else {
                            printf("A matriz nao e inca!");
                            return 0;
                        }
                    } else {
                        if (j < 2){
                            if (m1[i][j] == m1[i][j+1] - 1){
                                j++;
                                continue;
                            } else {
                                printf("A matriz nao e inca!");
                                return 0;
                            }
                        } else {
                            if (i < 2){
                                if (m1[i][j] == m1[i+1][j] - 1){
                                    i++;
                                    continue;
                                } else {
                                    printf("A matriz nao e inca!");
                                    return 0;
                                }
                            } else {
                                if (m1[i][j] == m1[i][j-1] - 1){
                                    j--;
                                    continue;
                                } else {
                                    printf("A matriz nao e inca!");
                                    return 0;
                                }
                        }
                    }
                }
            }
        }
    }
        
    }while (i != 3 && j != 2);

    printf("A matriz e inca!");
    return 0;
    
}