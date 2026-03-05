/*Autores: Lucas Espíndula Borges, André Moraes Rodrigues, Gabriel dos Santos do Amaral*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    typedef struct{
        float r;
        float a;
    } cpolar;

    typedef struct{
        float x;
        float y;
    } ccartesiana;

    cpolar p;
    ccartesiana c;

    scanf("%f", &p.r);
    scanf("%f", &p.a);

    c.x = p.r * cos(p.a);
    c.y = p.r * sin(p.a);

    printf("%.2f %.2f", c.x, c.y);
}