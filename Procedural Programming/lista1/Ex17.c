/*Três amigos jogaram na loteria. O valor da aposta foi de R$40,00, sendo que o primeiro amigo
contribuiu com R$20,00 reais, o segundo com R$15,00 e o terceiro com R$5,00. Caso eles ganhem o
prêmio de R$27.000.000,00, concordaram em repartí-lo proporcionalmente ao valor da aposta pago
por cada um. Faça uma programa que calcule e imprima a parte do prêmio a que cada amigo tem
direito.*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    float premio = 27000000.00;
    const float cont_a1 = 20.00;
    const float cont_a2 = 15.00;
    const float cont_a3 = 5.00;
    const float total_aposta = cont_a1 + cont_a2 + cont_a3;

    printf("Valor total do premio: R$%.2f\n", premio);
    printf("Caso eles ganhem o premio, o valor sera distribuido proporcionalmente a contribuicao de cada amigo na aposta.\n");
    printf("Contribuicao do amigo 1: R$%.2f\n", cont_a1);
    system("pause");
    printf("Contribuicao do amigo 2: R$%.2f\n", cont_a2);
    system("pause");
    printf("Contribuicao do amigo 3: R$%.2f\n", cont_a3);
    system("pause");

    printf("\nDistribuicao do premio:\n\n");
    printf("Amigo 1 recebera: R$%.2f\n", (cont_a1 / total_aposta) * premio);
    printf("Amigo 2 recebera: R$%.2f\n", (cont_a2 / total_aposta) * premio);
    printf("Amigo 3 recebera: R$%.2f\n", (cont_a3 / total_aposta) * premio);

    system("pause");
    return 0;

}