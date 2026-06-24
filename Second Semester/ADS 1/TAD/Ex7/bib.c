#include <stdio.h>
#include <stdlib.h>
#include "bib.h"

struct no {
    char nome[20];
    struct no *prox;
    struct no *ant;
};

struct descritor {
    No *inicio;
    int quantidade;
};

void inicializarLista (Descritor **d) {
    *d = (Descritor *)malloc(sizeof(Descritor));
    if (*d == NULL)
        return;
    (*d)->inicio = NULL;
    (*d)->qtd_naves = 0;
}

int criarNo (No **novo)
{
    *novo = (Nave *)malloc(sizeof(Nave));
    if (*novo == NULL)
        return 0; // Falha na alocação
    return 1;     // Sucesso
}

int inserirInicio (Descritor *d, char *nome) {
    No *novo;
    if (!criarNo(&novo))
        return 0; //falha
    
    strcpy(novo->nome,nome);

    if (d->quantidade == 0) {
        d->inicio = novo;
        novo->prox = novo;
        novo->ant = novo;
    } else {
        novo->prox = d->inicio;
        novo->ant = d->inicio->ant;
        novo->ant->prox = novo;
        d->inicio->ant = novo;
        d->inicio = novo;
    }
    d->quantidade++;
    return 1; //sucesso
}

void moverParaFrente (Descritor *d, int k, No **atual) { 
    *atual = d->inicio;
    int p = 0;

    while (p < k) {
        *atual = (*atual)->prox;
        p++;
    }
}

void moverParaTras (Descritor *d, int k, No **atual) {
    *atual = d->inicio;
    int p = 0;

    while (p < k) {
        *atual = (*atual)->ant;
        p++;
    }
}

int removerAtual (Descritor *d, No **atual) {
    if (d->quantidade == 0)
        return 0; //falha

    if ((*atual) == d->inicio) {
        d->inicio = (*atual)->prox;
        (*atual)->ant->prox = (*atual)->prox;
        (*atual)->prox->ant = (*atual)->ant;
    } else {
        (*atual)->ant->prox = (*atual)->prox;
        (*atual)->prox->ant = (*atual)->ant;
    }
    
    free((*atual));
    d->quantidade--;
    return 1; //sucesso
}

void lider (Descritor *d, int k) {
    No *atual = d->inicio;
    int op = 0;

    while (d->quantidade > 1) {
        if (op == 0) {
            moverParaFrente (d, k, &atual);
            No *temp = atual;
            atual = atual->prox;
            removerAtual (d, &temp);
            op = 1;
            continue;
        }

        if (op == 1) {
            moverParaTras (d, k, &atual);
            No *temp = atual;
            atual = atual->ant;
            removerAtual (d, &temp);
            op = 0;
            continue;
        }
    }
}

void limparBuffer () {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void liberarLista (Descritor *d) {
    if (d == NULL)
        return;

    if (d->qtd_naves > 0)
    {
        Nave *atual = d->inicio;
        Nave *temp;
        for (int i = 0; i < d->qtd_naves; i++)
        {
            temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(d);
}