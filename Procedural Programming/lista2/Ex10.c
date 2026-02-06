

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