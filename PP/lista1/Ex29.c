/*Uma empresa vende o mesmo produto para quatro diferentes estados. Cada estado possui uma taxa
diferente de imposto sobre o produto (MG 7%; SP 12%; RJ 15%; MS 8%). Faça um programa em que
o usuário entre com o valor e o estado destino do produto e o programa retorne o preço final do
produto acrescido do imposto do estado em que ele será vendido. Se o estado digitado não for válido,
mostrar uma mensagem de erro.*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {

    setlocale(LC_ALL, "pt_BR.UTF-8");

    float vprod, vfprod;
    int estado;

    printf("Digite o valor do produto: R$");
    scanf("%f", &vprod);
    printf("Digite o estado de destino:\n1 - MG\n2 - SP\n3 - RJ\n4 - MS\nOpção: ");
    scanf("%d", &estado);

    while (estado < 1 || estado > 4) {
        printf("Estado inválido! Digite novamente:\n");
        printf("1 - MG\n2 - SP\n3 - RJ\n4 - MS\nOpção: ");
        scanf("%d", &estado);
    }

    switch (estado) {
        case 1:
            vfprod = vprod * 1.07;
            printf("O valor final do produto para entrega em MG é: R$%.2f\n", vfprod);
            break;
        case 2:
            vfprod = vprod * 1.12;
            printf("O valor final do produto para entrega em SP é: R$%.2f\n", vfprod);
            break;
        case 3:
            vfprod = vprod * 1.15;
            printf("O valor final do produto para entrega em RJ é: R$%.2f\n", vfprod);
            break;
        case 4:
            vfprod = vprod * 1.08;
            printf("O valor final do produto para entrega em MS é: R$%.2f\n", vfprod);
            break; 
    }

    system("pause");
    return 0;

}