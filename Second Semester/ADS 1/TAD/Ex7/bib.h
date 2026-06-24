#ifndef BIB_H
#define BIB_H

typedef struct no No;
typedef struct descritor Descritor;
void inicializarLista(Descritor **d);
int inserirInicio(Descritor *d, char *nome);
void lider(Descritor *d, int k);
void limparBuffer();
void liberarLista(Descritor *d);

#endif