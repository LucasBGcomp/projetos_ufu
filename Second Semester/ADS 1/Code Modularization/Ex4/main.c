/*Faça um programa modularizado para armazenar o nome e a média de cada um dos alunos de
uma turma. Para cada aluno devem ser informados o nome, a nota da primeira prova
(0 a 10), a nota da segunda prova (0 a 10) e os pontos extras de participação (0 a 5). A média
deve ser calculada sobre as duas primeiras notas e a participação será somada à média. Caso o
valor ultrapasse o limiar dos 10 pontos, o valor deve ser substituído por 10, que é o valor máximo
da nota. Após a entrada de dados deve-se exibir a relação de alunos com os seus nomes e médias.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "bib.h"

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    int n;
    printf("Digite o número de alunos: ");
    scanf("%d", &n);
    printf("\n");

    TipoAluno alunos[n];
    LerDados(alunos, n);
    ExibirDados(alunos, n);

    system("pause");
    return 0;
}