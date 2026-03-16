#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    int n;
    do{
        printf("Digite o valor de n (1 a 10^5): ");
        scanf("%d", &n);
    }while(n < 1 || n > 100000);

    char *S = (char *) malloc(sizeof(char) * 1000000);
    if (S == NULL) {
        printf("Erro ao alocar memória para a string S.\n");
        exit(1); // Encerra o programa com código de erro
    }
    printf("\nDigite 0's e 1's sem espaços:\n\t(O tamanho deve ser múltiplo de n)\n\t(Os 0's repesentam cartas quaisque e os 1's representam cartas a serem compradas)\n");
    scanf(" %[^\n]", S);
    S = (char *) realloc(S, (strlen(S) + 1) * sizeof(char)); // Redimensiona a memória alocada para a string S
    S[strlen(S) + 1] = '\0'; // Garante que a string seja terminada com null

    int gasto = 0, natualizacoes = 0;
    for (int i = 0; i < strlen(S); i++) {
        if (S[i] == '1') {
            gasto += 2;
        }
        if (i > 0 && i % n == 0){
            natualizacoes++;
            gasto += natualizacoes;
        }
    }

    printf("\nGasto total: %d\n", gasto);

    system("pause");
    return 0;
}