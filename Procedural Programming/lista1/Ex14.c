/*Uma empresa contrata um encanador a R$ 30,00 por dia. Crie um programa que solicite o número de
dias trabalhados pelo encanador e imprima a quantia líquida que deverá ser paga, sabendo-se que são
descontados 7.5% para imposto de renda.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main()
{

    setlocale(LC_ALL, "Portuguese_Brazil");

    int dias;
    const float valorDia = 30.0;
    float gastoLiquido;
    const float impostoRenda = 0.075;

    printf("Digite o número de dias de trabalho contratados: ");
    scanf("%d", &dias);

    gastoLiquido = (dias * valorDia) - (dias * valorDia * impostoRenda);

    printf("O valor líquido a ser pago para o encanador é de R$%.2f\n", gastoLiquido);

    system("pause");
    return 0;
}