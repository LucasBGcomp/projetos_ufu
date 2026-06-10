#ifndef BIB_H
#define BIB_H

typedef struct no No;
typedef struct descritor Descritor;

void inicializarLista(Descritor **l);
int criarNo(No **novo);
int adicionarNoInicio(Descritor *l, int valor);
int adicionarNoFinal(Descritor *l, int valor);
int removerDoInicio(Descritor *l);
int removerDoFinal(Descritor *l);
int removerElemento(Descritor *l, int elemento);
void exibirLista(Descritor *l);
void liberarLista(Descritor *l);

#endif