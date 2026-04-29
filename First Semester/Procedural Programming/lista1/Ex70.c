/*O código de César é uma das mais simples e conhecidas técnicas de criptografia. Trata-se de um tipo
de substituição na qual cada letra do texto é substituída por outra, que se apresenta no alfabeto acima
dela um certo número de vezes. Por exemplo, com uma troca de três posições, ?A? seria substituído por
?D?, ?B? se tornaria ?E?, e assim por diante. Implemente um programa que faça uso desse Código de
César, entre com uma string e retorne a string codificada.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{

    setlocale(LC_ALL, "Portuguese_Brazil");

    int ntrocas;

    do{
    printf("Insira o Nº de posições que deseja deslocar (1 - 25): ");
    scanf("%d", &ntrocas);
    setbuf(stdin, NULL);
    }while (ntrocas < 1 || ntrocas > 25);

    char stri[50], strf[50]; // inicial e final

    printf("\nInsira a frase a ser criptografada: ");
    scanf("%49[^\n]", stri);
    setbuf(stdin, NULL);

    int len = strlen(stri);
    
    for (int i = 0; i < (int)len; i++)
    {
        if (stri[i] >= 'a' && stri[i] <= 'z')
        {
            strf[i] = ((stri[i] - 'a' + ntrocas) % 26) + 'a';
        }
        else if (stri[i] >= 'A' && stri[i] <= 'Z')
        {
            strf[i] = ((stri[i] - 'A' + ntrocas) % 26) + 'A';
        }
        else
        {
            strf[i] = stri[i];
        }
    }

    strf[strlen(stri)] = '\0';

    printf("\nFrase original: %s\n\n", stri);
    printf("Frase criptografada: %s\n", strf);

    system("pause");
    return 0;
}