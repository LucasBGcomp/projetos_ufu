#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bib.h"

struct aluno {
    char nome[50];
    int nota_pratica;
    int nota_teorica;
};

struct no {
    Aluno aluno;
    No* prox;
};

void limpar_buffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

No* criar_lista() {
    return NULL;
}

Aluno* criar_aluno() {
    Aluno* a = (Aluno*) malloc(sizeof(Aluno));
    if (a == NULL) {
        printf("Erro ao alocar memória.\n\n");
        return NULL;
    }
    printf("\nDigite o nome do aluno: ");
    scanf(" %49[^\n]", a->nome);
    limpar_buffer();
    do{
        printf("Digite a nota prática do aluno (0-50): ");
        scanf("%d", &a->nota_pratica);
    } while (a->nota_pratica < 0 || a->nota_pratica > 50);
    
    do{
        printf("Digite a nota teórica do aluno (0-50): ");
        scanf("%d", &a->nota_teorica);
    } while (a->nota_teorica < 0 || a->nota_teorica > 50);

    return a;
}

No* inserir_aluno(No* lista, Aluno* a) {
    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro ao alocar memória.\n\n");
        return lista;
    }
    novo_no->aluno = *a;
    novo_no->prox = lista;
    return novo_no;
}

int pesquisar_notas(No* lista, char* nome) {
    No* atual = lista;
    while (atual != NULL) {
        if (strcmp(atual->aluno.nome, nome) == 0) {
            printf("\nAluno: %s\n", atual->aluno.nome);
            printf("Nota Prática: %d\n", atual->aluno.nota_pratica);
            printf("Nota Teórica: %d\n\n", atual->aluno.nota_teorica);
            return 1;
        }
        atual = atual->prox;
    }
    return 0;
}

No* remover_aluno(No* lista, char* nome) {
    No* atual, *ant;
    int achou = 0;
    if (lista == NULL) return lista;
    else {
        atual = lista;
        ant = NULL;
        while (atual != NULL) {
            if (strcmp(atual->aluno.nome, nome) == 0) {
                achou = 1;
                break;
            } else {
                ant = atual;
                atual = atual->prox;
            }
        }
        if (achou == 1) {
            if (atual == lista) {
                lista = atual->prox;
            } else {
                ant->prox = atual->prox;
            }
            free(atual);
        } else {
            printf("\nAluno não encontrado.\n\n");
        }
        return lista;
    }
}

No* media_70(No* lista) {
    No* lista_media = criar_lista();
    No* atual = lista;
    while (atual != NULL) {
        double media = (atual->aluno.nota_pratica + atual->aluno.nota_teorica) / 2.0;
        if (media >= 35) {
            lista_media = inserir_aluno(lista_media, &atual->aluno);
        }
        atual = atual->prox;
    }
    return lista_media;
}

int imprimir_lista(No* lista) {
    No* atual = lista;
    if (atual == NULL) {
        return 0;
    }
    while (atual != NULL) {
        printf("\nAluno: %s\n", atual->aluno.nome);
        printf("Nota Prática: %d\n", atual->aluno.nota_pratica);
        printf("Nota Teórica: %d\n", atual->aluno.nota_teorica);
        printf("---------------------------\n");
        atual = atual->prox;
    }
    return 1;
}

void liberar_lista (No* lista) {
    No* atual = lista;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
}