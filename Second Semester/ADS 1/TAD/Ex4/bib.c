#include <stdio.h>
#include <stdlib.h>
#include "bib.h"

struct no
{
    char *palavra;
    struct no *prox;
};

void LimparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void criarLV(No **l)
{
    *l = NULL;
}

No *criarNo()
{
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL)
        exit(2);
    novoNo->palavra = NULL;
    return novoNo;
}

int buscar(No *l, char *elem)
{
    No *atual = l;

    while (atual != NULL)
    {
        if (_stricmp(atual->palavra, elem) == 0)
        {
            return 1;
        }
        atual = atual->prox;
    }
    return 0;
}

int ehPrimo(int n)
{
    if (n < 2)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;

    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int inserirElemento(No **l, char *elem)
{
    No *novoNo = criarNo();
    novoNo->palavra = (char *)malloc((strlen(elem) + 1) * sizeof(char));
    if (novoNo->palavra == NULL)
    {
        free(novoNo);
        return 4;
    }
    strcpy(novoNo->palavra, elem);

    novoNo->prox = *l;
    *l = novoNo;
    return 0;
}

int lerArquivo(No **l)
{
    FILE *fp;
    fp = fopen("Ex4_TAD.txt", "r");
    if (fp == NULL)
    {
        return 5;
    }
    char elem[200];
    while (fscanf(fp, " %199[^\n]", elem) != EOF)
    {
        if (inserirElemento(l, elem) == 4)
            return 4;
    }

    fclose(fp);
    return 0;
}

int removerElemento(No **l, char *elem)
{
    No *atual = *l;
    No *ant = NULL;
    int achou = 0;

    while (atual != NULL)
    {
        if (_stricmp(atual->palavra, elem) == 0)
        {
            achou = 1;
            break;
        }
        else
        {
            ant = atual;
            atual = atual->prox;
        }
    }

    if (achou == 1)
    {
        if (atual == *l)
        {
            *l = atual->prox;
        }
        else
        {
            ant->prox = atual->prox;
        }
        free(atual->palavra);
        free(atual);
        return achou;
    }
    else
    {
        return achou;
    }
}

void removeRepetidas(No **l)
{
    if (l == NULL || *l == NULL)
        return; // Lista vazia ou inexistente

    No *atual = *l;

    while (atual != NULL)
    {
        No *anteriorV = atual;
        No *verif = atual->prox;

        while (verif != NULL)
        {
            if (strcmp(atual->palavra, verif->palavra) == 0)
            {
                No *temp = verif;
                anteriorV->prox = verif->prox;
                verif = verif->prox;
                free(temp->palavra);
                free(temp);
            }
            else
            {
                anteriorV = verif;
                verif = verif->prox;
            }
        }
        atual = atual->prox;
    }
}

void exibirLista(No *l)
{
    No *atual = l;

    while (atual != NULL)
    {
        printf("%s\n", atual->palavra);
        atual = atual->prox;
    }
    printf("\n");
}

void tamPrimo(No *l, No **p)
{
    No *atual = l;

    while (atual != NULL)
    {
        if (ehPrimo(strlen(atual->palavra)) == 1)
        {
            No *temp = criarNo();
            temp->palavra = (char *)malloc((strlen(atual->palavra) + 1) * sizeof(char));
            strcpy(temp->palavra, atual->palavra);
            temp->prox = *p;
            *p = temp;
        }
        atual = atual->prox;
    }
}

int N_elem(No *l)
{
    No *atual = l;
    int c = 0;

    while (atual != NULL)
    {
        c++;
        atual = atual->prox;
    }

    return c;
}

int N_elemRec(No *l)
{
    if (l != NULL)
    {
        return (1 + N_elemRec(l->prox));
    }
    else
    {
        return 0;
    }
}

void liberarLista(No *l)
{
    No *atual = l;

    while (atual != NULL)
    {
        No *temp = atual;
        atual = atual->prox;
        free(temp->palavra);
        free(temp);
    }
}