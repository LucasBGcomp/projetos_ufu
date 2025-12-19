/*Três amigos jogaram na loteria. O valor da aposta foi de R$40,00, sendo que o primeiro amigo
contribuiu com R$20,00 reais, o segundo com R$15,00 e o terceiro com R$5,00. Caso eles ganhem o
prêmio de R$27.000.000,00, concordaram em repartí-lo proporcionalmente ao valor da aposta pago
por cada um. Faça uma programa que calcule e imprima a parte do prêmio a que cada amigo tem
direito.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{

    setlocale(LC_ALL, "Portuguese_Brazil");

    float premio = 27000000.00;
    const float cont_a1 = 20.00;
    const float cont_a2 = 15.00;
    const float cont_a3 = 5.00;
    const float total_aposta = cont_a1 + cont_a2 + cont_a3;

    printf("Valor total do prêmio: R$%.2f\n", premio);
    printf("Caso eles ganhem o prÊmio, o valor será distribuído proporcionalmente à contribuição de cada amigo na aposta.\n");
    printf("Contribuição do amigo 1: R$%.2f\n", cont_a1);
    system("pause");
    printf("Contribuição do amigo 2: R$%.2f\n", cont_a2);
    system("pause");
    printf("Contribuição do amigo 3: R$%.2f\n", cont_a3);
    system("pause");

    printf("\nDistribuição do prêmio:\n\n");
    printf("Amigo 1 receberá: R$%.2f\n", (cont_a1 / total_aposta) * premio);
    printf("Amigo 2 receberá: R$%.2f\n", (cont_a2 / total_aposta) * premio);
    printf("Amigo 3 receberá: R$%.2f\n", (cont_a3 / total_aposta) * premio);

    system("pause");
    return 0;
}