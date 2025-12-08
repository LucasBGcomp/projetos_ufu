/*Leia um valor inteiro em segundos e imprima-o em horas, minutos e segundos.*/

#include <stdio.h>
#include <stdlib.h>

int main(){

int segundos, horas, minutos, segs_restantes;

printf("Digite um valor inteiro em segundos: ");
scanf("%i", &segundos);

horas = segundos / 3600;
minutos = (segundos % 3600)/60;
segs_restantes = (segundos % 3600) % 60;

printf("%i segundos corresponde a: %i horas, %i minutos e %i segundos.\n", segundos, horas, minutos, segs_restantes);

system("pause");
return 0;

}