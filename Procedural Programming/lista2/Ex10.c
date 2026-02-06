/*Escreva um programa que converta coordenadas polares para cartesianas:
? Crie e leia um ponto em coordenada polar, composto por raio (r) e argumento (a) em radianos.
? Crie outro ponto, agora em coordenada cartesiana, composto por x e y, sabendo que x = r * cos(a)
e y = r * sin(a).
Implemente os pontos em cada tipo de coordenada como duas estruturas. No programa principal, leia
um ponto em coordenada polar e mostre as coordenadas do ponto gerado no plano cartesiano.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese_Brazil");

    typedef struct {

        float r, a;

    } cpolar;

    typedef struct {

        float x, y;

    } ccartesiana;

    typedef struct {

        cpolar cpolar;
        ccartesiana ccartesiana;

    } ponto;

    ponto p;
    printf("Insira as coordenadas polares do ponto (raio e ângulo em radianos): ");
    scanf("%f %f", &p.cpolar.r, &p.cpolar.a);
    setbuf(stdin, NULL);

    p.ccartesiana.x = p.cpolar.r * cos(p.cpolar.a);
    p.ccartesiana.y = p.cpolar.r * sin(p.cpolar.a);

    printf("\nAs coordenadas cartesianas correspondentes do ponto são:\n\n");
    printf("x: \t%.2f\n\n", p.ccartesiana.x);
    printf("y: \t%.2f\n\n", p.ccartesiana.y);

    system("pause");
    return 0;
}