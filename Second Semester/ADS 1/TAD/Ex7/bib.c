#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib.h"

struct no
{
    char nome[20];
    struct no *prox;
    struct no *ant;
};

struct descritor
{
    No *inicio;
    int quantidade;
};

void inicializarLista(Descritor **d)
{
    *d = (Descritor *)malloc(sizeof(Descritor));
    if (*d == NULL)
        return;
    (*d)->inicio = NULL;
    (*d)->quantidade = 0;
}

int criarNo(No **novo)
{
    *novo = (No *)malloc(sizeof(No));
    if (*novo == NULL)
        return 0; // Falha na alocação
    return 1;     // Sucesso
}

int inserirInicio(Descritor *d, char *nome)
{
    No *novo;
    if (!criarNo(&novo))
        return 0; // falha

    strcpy(novo->nome, nome);

    if (d->quantidade == 0)
    {
        d->inicio = novo;
        novo->prox = novo;
        novo->ant = novo;
    }
    else
    {
        novo->prox = d->inicio;
        novo->ant = d->inicio->ant;
        novo->ant->prox = novo;
        d->inicio->ant = novo;
        d->inicio = novo;
    }
    d->quantidade++;
    return 1; // sucesso
}

void moverParaFrente(Descritor *d, int k, No **atual)
{
    if (d->quantidade == 0)
        return;
    int p = 0;

    while (p < (k % d->quantidade))
    {
        *atual = (*atual)->prox;
        p++;
    }
}

void moverParaTras(Descritor *d, int k, No **atual)
{
    if (d->quantidade == 0)
        return;
    int p = 0;

    while (p < (k % d->quantidade))
    {
        *atual = (*atual)->ant;
        p++;
    }
}

int removerAtual(Descritor *d, No **atual)
{
    if (d->quantidade == 0)
        return 0; // falha

    if (d->quantidade == 1)
    {
        d->inicio = NULL;
    }
    else
    {
        if (*atual == d->inicio)
        {
            d->inicio = (*atual)->prox;
        }
        (*atual)->ant->prox = (*atual)->prox;
        (*atual)->prox->ant = (*atual)->ant;
    }

    free(*atual);
    *atual = NULL;
    d->quantidade--;
    return 1; // sucesso
}

void lider(Descritor *d, int k)
{
    No *atual = d->inicio;
    int c = 0;
    if (d->quantidade == 0)
    {
        printf("\nA lista está vazia!\n");
        return;
    }

    while (d->quantidade > 1)
    {
        if (c == 0)
        {
            moverParaFrente(d, k, &atual);
            No *temp = atual;
            No *proxNo = atual->prox;
            removerAtual(d, &temp);
            atual = proxNo;
            c = 1;
            continue;
        }

        if (c == 1)
        {
            moverParaTras(d, k, &atual);
            No *temp = atual;
            No *antNo = atual->ant;
            removerAtual(d, &temp);
            atual = antNo;
            c = 0;
            continue;
        }
    }
    printf("\nO líder sorteado é: %s\n", d->inicio->nome);
}

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void liberarLista(Descritor *d)
{
    if (d == NULL)
        return;

    if (d->quantidade > 0)
    {
        No *atual = d->inicio;
        No *temp;
        for (int i = 0; i < d->quantidade; i++)
        {
            temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(d);
}