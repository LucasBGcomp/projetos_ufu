#ifndef _BIB_H
#define _BIB_H

typedef struct aluno Aluno;
typedef struct no No;

void limpar_buffer();
No *criar_lista();
Aluno *criar_aluno();
No *inserir_aluno(No *lista, Aluno *a);
int pesquisar_notas(No *lista, char *nome);
No *remover_aluno(No *lista, char *nome);
No *media_70(No *lista);
int imprimir_lista(No *lista);
void liberar_lista(No *lista);

#endif