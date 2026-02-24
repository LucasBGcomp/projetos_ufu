/*O número de controle de um CPF (seus 2 últimos dígitos verificadores, DV1 e DV2), são calculados da
seguinte forma (considerando os primeiros 9 dígitos do CPF):

a. Etapa 1: cálculo de DV1
    i. Soma1: soma dos produtos de cada dígito por um peso de 2 a 10, na ordem inversa
(do nono para o primeiro dígito).
    ii. Multiplique a Soma1 por 10 e calcule o resto da divisão do resultado por 11. Se der
10, DV1 é zero; caso contrário, o DV1 é o próprio resto.

b. Etapa 2: cálculo de DV2
    i. Soma2: soma dos produtos de cada dígito por um peso de 3 a 11, também na ordem
inversa.
    ii. Adicione a Soma2 ao dobro do DV1, multiplique por 10 e calcule o resto da divisão
do resultado por 11. Se der 10, DV2, é zero; caso contrário o DV2 é o próprio resto.

c. Etapa 3: Multiplique DV1 por 10, some com DV2 e você terá o número de controle do CPF.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int n_controle(int *cpf, int tam)
{
    int peso1 = 10, peso2 = 11;
    int soma1 = 0, soma2 = 0;
    int dv1, dv2;
    int i;
    // Cálculo do dv1
    for (i = 0; i < tam - 1; i++)
    {
        soma1 += cpf[i] * peso1;
        peso1--;
    }

    int resto1 = (soma1) % 11;
    if (resto1 < 2)
    {
        dv1 = 0;
    }
    else
    {
        dv1 = 11 - resto1;
    }

    // Cálculo do dv2
    for (i = 0; i < tam - 1; i++)
    {
        soma2 += cpf[i] * peso2;
        peso2--;
    }

    int resto2 = (soma2) % 11;
    if (resto2 < 2)
    {
        dv2 = 0;
    }
    else
    {
        dv2 = 11 - resto2;
    }

    int ncontrole = dv1 * 10 + dv2;
    return ncontrole;
}

int main()
{

    setlocale(LC_ALL, "Portuguese_Brazil");

    char cpf[10];
    printf("Digite os 9 primeiros dígitos do seu CPF: ");
    scanf("%9[^\n]s", cpf);
    setbuf(stdin, NULL);

    int vcpf[9];
    for (int i = 0; i < 9; i++)
    {
        vcpf[i] = cpf[i] - '0';
    }

    int ncontrole = n_controle(vcpf, 9);
    printf("\nO número de controle do seu CPF é: %d\n\n", ncontrole);

    system("pause");
    return 0;
}