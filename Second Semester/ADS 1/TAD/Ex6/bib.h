#ifndef BIB_H
#define BIB_H

typedef struct nave Nave;

typedef struct descritor Descritor;

void inicializarLista(Descritor **d);

int adicionarNave(Descritor *d, int cap, int qtd, char *nome);

void exibirNaves(Descritor *d);

int realizarCiclo(Descritor *d, int n);

void liberarLista(Descritor *d);

void limparBuffer();

#endif