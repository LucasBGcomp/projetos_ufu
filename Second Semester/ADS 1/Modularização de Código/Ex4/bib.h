#ifndef _BIB_H
#define _BIB_H
typedef struct {
    char nome[50];
    float media;
} TipoAluno;
void LimparBuffer();
float Calc_Media(float nota1, float nota2, float participacao);
void LerDados(TipoAluno alunos[], int n);
void ExibirDados(TipoAluno alunos[], int n);
#endif