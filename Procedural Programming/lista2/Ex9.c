

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese_Brazil");

    typedef struct {
        char nome[50];
        char nmatricula[12];
        char curso[25];
    }aluno;

    int nalunos;
    printf("Digite o número de alunos da turma: ");
    scanf("%d", &nalunos);
    setbuf(stdin, NULL);
    printf("\n");
    aluno alunos[nalunos];

    for (int i = 0; i < nalunos; i++){

        printf("Digite o nome do aluno %d: ", i+1);
        scanf("%49[^\n]s", alunos[i].nome);
        setbuf(stdin, NULL);

        printf("Digite o número de matrícula do aluno %d: ", i+1);
        scanf("%11[^\n]s", alunos[i].nmatricula);
        setbuf(stdin, NULL);

        printf("Digite o curso do aluno %d: ", i+1);
        scanf("%24[^\n]s", alunos[i].curso);
        setbuf(stdin, NULL);

        printf("\n");
    }

    printf("Alunos cadastrados:\n\n");

    for (int i = 0; i < nalunos; i++){

        printf("Nome: %s\n", alunos[i].nome);
        printf("Número de Matrícula: %s\n", alunos[i].nmatricula);
        printf("Curso: %s\n\n", alunos[i].curso);

    }

    FILE *fp;
    fp = fopen("Ex9_arq.txt", "w");
    if (fp == NULL){
        printf("Erro ao abrir/criar o arquivo!!\n");
        exit(1);
    }

    for (int i = 0; i < nalunos; i++){

        fprintf(fp, "Nome: %s\n", alunos[i].nome);
        fprintf(fp, "Número de Matrícula: %s\n", alunos[i].nmatricula);
        fprintf(fp, "Curso: %s\n\n", alunos[i].curso);

    }

    fclose(fp);
    system("pause");
    return 0;
}