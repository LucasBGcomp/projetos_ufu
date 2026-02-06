#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


int main()
{

    setlocale(LC_ALL, "");

    typedef struct {
        char nome[16];
        float potencia;
        float tempopordia;
    }eletrodomesticos;

    eletrodomesticos ed[5];

    for (int i = 0; i < 5; i++){

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

    float consumoparcial[5], consumototal, consumorelativo;
    for (int i = 0; i < 5; i++){

        consumoparcial[i] = ed[i].potencia * ed[i].tempopordia * dias;
        consumototal += consumoparcial[i];
    }

    printf("\nO consumo total dos seus 5 eletrodomesticos é: %.2fkWh\n\n", consumototal);

    printf("O consumo relativo de cada eletrodoméstico é:\n\n");

    for (int i = 0; i < 5; i++){

        printf("%s:\t%.2f%%\n\n", ed[i].nome, (consumoparcial[i]/consumototal)*100);
        printf("-------------------------------------\n\n");

    }

    system("pause");
    return 0;
}
