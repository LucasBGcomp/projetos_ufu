/*Crie um programa que leia um vetor com os dados de 5 carros: modelo, marca (máximo 15 letras), ano e preço.
Leia um valor p e mostre as informações de todos os carros com preço menor que p. Repita este
processo até que seja lido um valor p = 0.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main(){

    setlocale(LC_ALL, "Portuguese_Brazil");

    typedef struct {

        char modelo[21];
        char marca[16];
        int ano;
        float preco;

    } carro;

    carro veiculo[5];

    for (int i = 0; i < 5; i++){

        printf("Digite o modelo do carro %d: ", i + 1);
        scanf(" %20[^\n]s", veiculo[i].modelo);
        setbuf(stdin, NULL);
        
        printf("Digite a marca do carro %d: ", i + 1);
        scanf(" %15[^\n]s", veiculo[i].marca);
        setbuf(stdin, NULL);
        
        printf("Digite o ano do carro %d: ", i + 1);
        scanf("%d", &veiculo[i].ano);
        setbuf(stdin, NULL);
        
        printf("Digite o preco do carro %d: ", i + 1);
        scanf("%f", &veiculo[i].preco);
        setbuf(stdin, NULL);
        printf("\n");
    }

    float verificarpreco;

    do{
        printf("Digite o preço limite (digite 0 para encerrar): ");
        scanf("%f", &verificarpreco);
        setbuf(stdin, NULL);
    

        if (verificarpreco == 0){

            printf("Pesquisa encerrada!\n");
            system("pause");
            return 0;

        } 
        else if (verificarpreco < 0) {
            continue;
        } 
        else {

            printf("\nCarros com preço abaixo de R$ %.2f:\n\n", verificarpreco);

            int n = 0;

            for (int i = 0; i < 5; i++){

                if (veiculo[i].preco < verificarpreco){

                    n++;
                    printf("Modelo: %s\n", veiculo[i].modelo);
                    printf("Marca: %s\n", veiculo[i].marca);
                    printf("Ano: %d\n", veiculo[i].ano);
                    printf("Preço: R$ %.2f\n\n", veiculo[i].preco);
                    printf("------------------------\n\n");

                }

            }

            if (n == 0){
                printf("Nenhum carro encontrado com preço abaixo de R$ %.2f.\n\n", verificarpreco);
            }

        }   
    } while (verificarpreco != 0);
}