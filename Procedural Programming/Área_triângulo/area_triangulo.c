#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{

    setlocale(LC_ALL, "pt_BR.UTF-8");

    float xa, ya, xb, yb, xc, yc;
    float xvet_u, yvet_u, xvet_v, yvet_v;

    printf("Digite as coordenadas do ponto A (x y): ");
    scanf("%f %f", &xa, &ya);
    printf("Digite as coordenadas do ponto B (x y): ");
    scanf("%f %f", &xb, &yb);
    printf("Digite as coordenadas do ponto C (x y): ");
    scanf("%f %f", &xc, &yc);

    xvet_u = xb - xa;
    yvet_u = yb - ya;
    xvet_v = xc - xa;
    yvet_v = yc - ya;

    float xproj_uv;
    xproj_uv = ((xvet_u * xvet_v + yvet_u * yvet_v) / (xvet_v * xvet_v + yvet_v * yvet_v)) * xvet_v;
    float yproj_uv;
    yproj_uv = ((xvet_u * xvet_v + yvet_u * yvet_v) / (xvet_v * xvet_v + yvet_v * yvet_v)) * yvet_v;

    float xh, yh;
    xh = xvet_u - xproj_uv;
    yh = yvet_u - yproj_uv;

    float comp_h;
    comp_h = sqrt((xh * xh) + (yh * yh));

    float comp_v;
    comp_v = sqrt((xvet_v * xvet_v) + (yvet_v * yvet_v));

    float area;
    area = (comp_h * comp_v) / 2;

    printf("A área do triângulo formado pelos pontos A, B e C é: %.2f u.a\n", area);

    system("pause");
    return 0;
}