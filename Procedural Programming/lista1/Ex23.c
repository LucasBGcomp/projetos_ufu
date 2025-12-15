/*Receba o valor do salário de um trabalhador e o valor da prestação de um empréstimo. Se a prestação for maior que 30% do salário, imprima “Emprestimo nao concedido”. Caso contrário, imprima         “Emprestimo concedido”.*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    float salario, prestacao;

    printf("Digite o valor do salario do trabalhador (em reais): ");
    scanf("%f", &salario);

    printf("Digite o valor da prestacao do emprestimo (em reais): ");
    scanf("%f", &prestacao);

    if (prestacao > (0.3 * salario))
    {

        printf("Emprestimo nao concedido.\n");
    }
    else
    {

        printf("Emprestimo concedido.\n");
    }

    system("pause");
    return 0;
}