#ifndef _BIB_H
#define _BIB_H

#if defined(_WIN32) || defined(_WIN64)
#include <string.h>
#else
#include <strings.h>
#define _stricmp strcasecmp
#endif

typedef struct no No;

void LimparBuffer();
void criarLV(No **l);
No *criarNo();
int buscar(No *l, char *elem);
int ehPrimo(int n);
int inserirElemento(No **l, char *elem);
int lerArquivo(No **l);
int removerElemento(No **l, char *elem);
void removeRepetidas(No **l);
void exibirLista(No *l);
void tamPrimo(No *l, No **p);
int N_elem(No *l);
int N_elemRec(No *l);
void liberarLista(No *l);

#endif