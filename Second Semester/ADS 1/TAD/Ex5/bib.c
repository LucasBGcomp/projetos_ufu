#include <stdio.h>
#include <stdlib.h>
#include "bib.h"

struct no
{
    int valor;
    struct no *prox;
};

struct descritor
{
    struct no *inicio;
    struct no *fim;
    int tamanho;
};

void inicializarLista(Descritor **l)
{
    *l = (Descritor *)malloc(sizeof(Descritor));
    if (*l == NULL)
    {
        return;
    }
    (*l)->inicio = NULL;
    (*l)->fim = NULL;
    (*l)->tamanho = 0;
}

int criarNo(No **novo)
{
    *novo = (No *)malloc(sizeof(No));
    if (*novo == NULL)
    {
        return 0; // Falha na alocação
    }
    return 1; // Sucesso
}

int adicionarNoInicio(Descritor *l, int valor)
{
    No *novo;
    if (criarNo(&novo))
    {
        novo->valor = valor;
        novo->prox = l->inicio;
        l->inicio = novo;
        if (l->fim == NULL)
        {
            l->fim = novo;
        }
        l->tamanho++;
        return 1; // Sucesso
    }
    return 0; // Falha
}

int adicionarNoFinal(Descritor *l, int valor)
{
    No *novo;
    if (criarNo(&novo))
    {
        novo->valor = valor;
        novo->prox = NULL;
        if (l->fim != NULL)
        {
            l->fim->prox = novo;
        }
        l->fim = novo;
        l->tamanho++;
        return 1; // Sucesso
    }
    return 0; // Falha
}

int removerDoInicio(Descritor *l)
{
    if (l->inicio == NULL)
        return 0; // Lista vazia
    No *temp = l->inicio;
    l->inicio = l->inicio->prox;
    free(temp);
    l->tamanho--;
    return 1; // Sucesso
}

int removerDoFinal(Descritor *l)
{
    if (l->fim == NULL)
        return 0; // Lista vazia
    No *temp = l->fim;
    if (l->inicio == l->fim)
    {
        l->inicio = NULL;
        l->fim = NULL;
    }
    else
    {
        No *atual = l->inicio;
        while (atual->prox != l->fim)
        {
            atual = atual->prox;
        }
        l->fim = atual;
        l->fim->prox = NULL;
    }
    free(temp);
    l->tamanho--;
    return 1; // Sucesso
}

int removerElemento(Descritor *l, int elemento)
{
    No *atual = l->inicio;
    No *anterior = NULL;

    while (atual != NULL && atual->valor != elemento)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL)
    {
        if (anterior == NULL)
        {
            l->inicio = atual->prox;
        }
        else
        {
            anterior->prox = atual->prox;
        }
    }
    else
    {
        return 0; // Elemento não encontrado
    }
    free(atual);
    l->tamanho--;
    return 1; // Elemento encontrado e removido
}

void exibirLista(Descritor *l)
{
    No *atual = l->inicio;
    if (atual == NULL)
    {
        printf("\nLista vazia.\n");
        return;
    }
    printf("\nLista: \n");
    while (atual != NULL)
    {
        printf("\n-> %d", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

void liberarLista(Descritor *l)
{
    No *atual = l->inicio;
    while (atual != NULL)
    {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(l);
}