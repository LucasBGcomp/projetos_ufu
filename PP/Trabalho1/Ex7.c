

#include <stdio.h>

int main(void) {

    int matriz[3][3], determinante;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){

            scanf("%d", &matriz[i][j]);

        }
        printf("\n");
    }

    determinante = matriz[0][0] * (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1]) -
                  matriz[0][1] * (matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0]) +
                  matriz[0][2] * (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]);

    printf("%d\n", determinante);
    return 0;
}