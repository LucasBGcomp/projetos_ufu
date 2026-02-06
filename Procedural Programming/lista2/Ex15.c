/*Crie um programa que controla o consumo de energia dos eletrodomésticos de uma casa:
? Cadastre eletrodomésticos com nome (máximo 15 letras), potência (real, em kW) e tempo ativo
por dia (real, em horas).
? Leia um tempo t (em dias), calcule e mostre o consumo total na casa e o consumo relativo de cada
eletrodoméstico (consumo/consumo total) nesse período de tempo. Apresente este último dado em
porcentagem.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


int main()
{

    setlocale(LC_ALL, "Portuguese_Brazil");

    typedef struct {
        char nome[16];
        float potencia;
        float tempopordia;
    }eletrodomesticos;

    int n;
    printf("Quantos eletrodomésticos você deseja cadastrar? ");
    scanf("%d", &n);
    setbuf(stdin, NULL);
    eletrodomesticos ed[n];

    for (int i = 0; i < n; i++){

        printf("Digite o nome do eletrodoméstico %d: ", i+1);
        scanf("%15[^\n]s", ed[i].nome);
        setbuf(stdin, NULL);

        printf("Digite a potência do eletrodoméstico %d (em kW): ", i+1);
        scanf("%f", &ed[i].potencia);
        setbuf(stdin, NULL);

        printf("Digite o tempo ativo por dia do eletrodoméstico %d (em horas): ", i+1);
        scanf("%f", &ed[i].tempopordia);
        setbuf(stdin, NULL);

        printf("\n");
    }

    int dias;
    printf("Digite o número de dias para calcular o consumo dos eletrodomésticos: ");
    scanf("%d", &dias);
    setbuf(stdin, NULL);

    float consumoparcial[n], consumototal = 0;
    for (int i = 0; i < n; i++){

        consumoparcial[i] = ed[i].potencia * ed[i].tempopordia * dias;
        consumototal += consumoparcial[i];
    }

    printf("\nO consumo total dos seus %d eletrodomesticos em %d dias é: %.2fkWh\n\n", n, dias, consumototal);

    printf("O consumo relativo de cada eletrodoméstico é:\n\n");

    for (int i = 0; i < n; i++){

        printf("%s:\t%.2f%%\n\n", ed[i].nome, (consumoparcial[i]/consumototal)*100);
        printf("-------------------------------------\n\n");

    }

    system("pause");
    return 0;
}