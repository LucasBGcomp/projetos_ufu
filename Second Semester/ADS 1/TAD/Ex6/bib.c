#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib.h"

struct nave {
    char nome[6];
    int capacidade;
    int qtd_atual;
    struct nave *prox;
};

struct descritor {
    Nave *inicio;
    int qtd_naves;
};

void inicializarLista(Descritor **d) {
    *d = (Descritor *) malloc(sizeof(Descritor));
    if (*d == NULL) return;
    (*d)->inicio = NULL;
    (*d)->qtd_naves = 0;
}

int criarNave(Nave **nova) {
    *nova = (Nave *) malloc(sizeof(Nave));
    if (*nova == NULL) return 0; // Falha na alocação
    return 1; // Sucesso
}

int adicionarNave(Descritor *d, int cap, int qtd, char *nome) {
    Nave *nova;
    if (!criarNave(&nova)) return 0; // Falha na criação da nave
    if (d->qtd_naves == 0) {
        nova->capacidade = cap;
        nova->qtd_atual = qtd;
        strcpy(nova->nome, nome);
        d->inicio = nova;
        nova->prox = nova;
        d->qtd_naves++;
        return 1; // Sucesso
    }
    nova->capacidade = cap;
    nova->qtd_atual = qtd;
    strcpy(nova->nome, nome);
    nova->prox = d->inicio->prox;
    d->inicio->prox = nova;
    d->qtd_naves++;
    return 1; // Sucesso
}

void exibirNaves(Descritor *d) {
    if (d->qtd_naves == 0) {
        printf("\nNenhuma nave cadastrada.\n");
        return;
    }

    Nave *atual = d->inicio;
    printf("\nNaves cadastradas:\n");
    do{
        printf("\nNome: %s\nCapacidade Máxima de Combustível: %d\nQuantidade Atual de Combustível: %d\n", atual->nome, atual->capacidade, atual->qtd_atual);
        atual = atual->prox;
    } while (atual != d->inicio);
}

int realizarCiclo(Descritor *d, int n) {
    if (d->qtd_naves == 0) return 0; // Falha: nenhuma nave cadastrada
    int c = 0;
    Nave *atual = d->inicio;
    while (c != d->qtd_naves) {
        if (atual->qtd_atual == atual->capacidade) {
            c++;
        } else {
            if ((atual->qtd_atual + n) > atual->capacidade) {
                atual->qtd_atual = atual->capacidade;
                c++;
            } else {
                atual->qtd_atual += n;
            }
        }
        atual = atual->prox;
    }
    return 1; // Sucesso
}

void liberarLista(Descritor *d) {
    if (d->qtd_naves == 0) {
        free(d);
        return;
    }
    Nave *atual = d->inicio;
    Nave *temp;
    do {
        temp = atual;
        atual = atual->prox;
        free(temp);
    } while (atual != d->inicio);
    free(d);
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}