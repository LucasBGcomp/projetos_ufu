#include <stdio.h>
#include "bib.h"

void LimparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

float Calc_Media(float nota1, float nota2, float participacao)
{
    float media = (nota1 + nota2) / 2 + participacao;
    if (media > 10)
    {
        media = 10;
    }
    return media;
}

void LerDados(TipoAluno alunos[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf(" %49[^\n]", alunos[i].nome);
        LimparBuffer();
        float nota1, nota2, participacao;
        printf("Digite a nota da primeira prova (0 a 10): ");
        scanf("%f", &nota1);
        printf("Digite a nota da segunda prova (0 a 10): ");
        scanf("%f", &nota2);
        printf("Digite os pontos extras de participação (0 a 5): ");
        scanf("%f", &participacao);
        alunos[i].media = Calc_Media(nota1, nota2, participacao);
        printf("\n");
    }
}

void ExibirDados(TipoAluno alunos[], int n)
{
    printf("\nRelação de alunos e suas médias:\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nAluno: %s\nMédia: %.2f\n", alunos[i].nome, alunos[i].media);
    }
    printf("\n");
}