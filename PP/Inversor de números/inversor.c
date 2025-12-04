#include <stdio.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "pt_BR.UTF-8");

    int x, y;

    printf("Seja bem-vindo ao Inversor de Números!\n");
    system("pause");
    printf("Escolha um número que satisfaça as seguintes condições:\n");
    printf("Número inteiro;\nPositivo;\nCom pelo menos dois dígitos.\n");
    system("pause");
    printf("Digite o número escolhido:");
    scanf("%i", &x);

    while (x < 10 || x < 0 || x % 1 != 0) {

        printf("Número inválido. Por favor, escolha um número que satisfaça as condições mencionadas:\n");
        printf("Digite o número escolhido:");
        scanf("%i", &x);

    }

    printf("Agora vamos escrever seu número ao contrário!\n");
    system("pause");

    while (x > 0) {

        y = x % 10;
        printf("%i", y);
        x = x / 10;

    }

    printf("\n");
    system("pause");
    return 0;

}