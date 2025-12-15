/*Escreva o menu de opções, como no exemplo abaixo. Leia a opção do usuário, em seguida leia 2
números reais e execute a operação escolhida sobre eles. (Escreva uma mensagem de erro se a
opção for inválida.)
Escolha a opcao:
1- Soma de 2 numeros.
2- Diferenca entre 2 numeros.
3- Produto entre 2 numeros.
4- Divisao entre 2 numeros (detalhe: o denominador não pode ser zero).*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float nA, nB;
    int opcao;

    printf("Escolha uma das opcoes abaixo:\n1. Soma de dois numeros\n2. Diferenca de dois numeros\n3. Produto entre dois numeros\n4. Divisao entre dois numeros\nOpcao: ");
    scanf("%d", &opcao);

    while (opcao < 1 || opcao > 4)
    {
        printf("Opcao invalida! Escolha uma das opcoes abaixo:\n1. Soma de dois numeros\n2. Diferenca de dois numeros\n3. Produto entre dois numeros\n4. Divisao entre dois numeros\nOpcao: ");
        scanf("%d", &opcao);
    }

    switch (opcao)
    {
    case 1:
        printf("Digite dois numeros de sua escolha: ");
        scanf("%f %f", &nA, &nB);
        float soma = nA + nB;
        printf("A soma e %.2f\n", soma);
        break;
    case 2:
        printf("Digite dois numeros de sua escolha: ");
        scanf("%f %f", &nA, &nB);
        float dif = nA - nB;
        printf("A diferença e %.2f\n", dif);
        break;
    case 3:
        printf("Digite dois numeros de sua escolha: ");
        scanf("%f %f", &nA, &nB);
        float produto = nA * nB;
        printf("O produto e %.2f\n", produto);
        break;
    case 4:
        do
        {
            printf("Digite dois numeros de sua escolha (O segundo nao pode ser zero!): ");
            scanf("%f %f", &nA, &nB);
        } while (nB == 0);
        float div = nA / nB;
        printf("A razão e %.2f\n", div);
        break;
    }

    system("pause");
    return 0;
}
