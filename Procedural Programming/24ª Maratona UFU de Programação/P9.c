#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese_Brazil");

    int n;

    do{
        printf("Digite o número de dias a serem analisados (entre 2 e 100000): ");
        scanf("%d", &n);
    }while(n < 2 || n > 100000);

    int PrecoAcoes[n];

    for(int i = 0; i < n; i++){
        printf("Digite o preço da ação no dia %d: ", i + 1);
        scanf("%d", &PrecoAcoes[i]);
    }

    int Lmax = 0;

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(PrecoAcoes[j] > PrecoAcoes[i]){
                int lucro = PrecoAcoes[j] - PrecoAcoes[i];
                if(lucro > Lmax){
                    Lmax = lucro;
                }
            }
        }
    }

    printf("\nO lucro máximo que pode ser obtido é: %d\n\n", Lmax);

    system("pause");
    return 0;
}