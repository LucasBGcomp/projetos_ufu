/*Escreva uma função que calcule a Sequência de Fibonacci, F, para um parâmetro n fornecido pelo
usuário.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int fib(int n)
{

    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}

int main()
{

    setlocale(LC_ALL, "Portuguese_Brazil");

    int n;
    do
    {
        printf("Digite um número inteiro e maior que zero: ");
        scanf("%d", &n);
        setbuf(stdin, NULL);
    } while (n <= 0);

    printf("\nO %dº termo da sequência de Fibonacci é: %d\n\n", n, fib(n));

    system("pause");
    return 0;
}