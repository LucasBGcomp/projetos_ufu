#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "Portuguese_Brazil");

    int n, q;
    do{
        printf("Digite o número de cafeterias na cidade (entre 1 e 200.000): ");
        scanf("%d", &n);
        printf("Digite o número de consultas que deseja realizar (entre 1 e 200.000): ");
        scanf("%d", &q);
    } while (n < 1 || n > 200000 || q < 1 || q > 200000);

    int *x = (int *) malloc(n * sizeof(int));
    int *y = (int *) malloc(n * sizeof(int));
    int *cidade = (int *) malloc(10001 * sizeof(int));
    int maiory = 0;

    for (int i = 0; i < n; i++){
        printf("Digite as coordenadas (x, y) da cafeteria %d: ", i + 1);
        scanf("%d %d", &x[i], &y[i]);
        if (y[i] > maiory){
            maiory = y[i];
        }
    }

    int *maiorx = malloc((maiory + 1) * sizeof(int));
    cidade = (int *) realloc(cidade, (maiory + 1) * sizeof(int));

    for (int i = 0; i < n; i++){
        if (x[i] > maiorx[y[i]]){
            maiorx[y[i]] = x[i];
        }
    }

    for (int i = 0; i < maiory+1; i++){
        cidade[i] = (int *) malloc((maiorx[i] + 1) * sizeof(int));
    }

    for (int i = 0; i < n; i++){
        cidade[y[i]][x[i]] = 1;
    }
    free(x);
    free(y);

    int *xp = (int *) malloc(q * sizeof(int));
    int *yp = (int *) malloc(q * sizeof(int));
    int *kp = (int *) malloc(q * sizeof(int));
    for (int i = 0; i < q; i++){
        printf("Digite as coordenadas iniciais (x, y) e o número mínimo de cafeterias que deseja alcançar na consulta %d: ", i + 1);
        scanf("%d %d %d", &xp[i], &yp[i], &kp[i]);
    }



    free(xp);
    free(yp);
    free(kp);
    for(int i = 0; i < maiory+1; i++){
        free(cidade[i]);
    }
    free(cidade);
    free(maiorx);
    system("pause");
    return 0;
}