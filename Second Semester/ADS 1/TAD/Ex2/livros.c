#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livros.h"

struct livro {
    char titulo[30], autor[30];
    int ano;
    double preco;
};

struct lista {
    Livro *livros;
    int qtd;
    int capacidade;
};

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

Lista *criarLista(int tam) {
    Lista *novalista = (Lista *) malloc(sizeof(Lista));
    if (novalista == NULL)
        return NULL;
    
    novalista->livros = (Livro *) malloc(tam * sizeof(Livro));
    if (novalista->livros == NULL) {
        free(novalista);
        return NULL;
    }

    novalista->qtd = 0;
    novalista->capacidade = tam;
    return novalista;
}

Livro *criarLivro() {
    Livro *novolivro = (Livro *) malloc(sizeof(Livro));
    if (novolivro == NULL)
        return NULL;

    printf("\nDigite o título do livro: ");
    scanf(" %29[^\n]", novolivro->titulo);
    limparBuffer();
    printf("Digite o autor do livro: ");
    scanf(" %29[^\n]", novolivro->autor);
    limparBuffer();
    printf("Digite o ano de publicação: ");
    scanf("%d", &novolivro->ano);
    printf("Digite o preço do livro: ");
    scanf("%lf", &novolivro->preco);
    return novolivro;
}

void liberarLista(Lista *l) {
    free(l->livros);
    free(l);
}

void exibirLivros(Lista *l){
    if (l->qtd == 0){
        printf("\nNenhum livro cadastrado.\n");
        return;
    }

    printf("\nLivros cadastrados:\n\n");
    for (int i = 0; i < l->qtd; i++) {
        printf("Título: %s\n", l->livros[i].titulo);
        printf("Autor: %s\n", l->livros[i].autor);
        printf("Ano: %d\n", l->livros[i].ano);
        printf("Preço: R$ %.2lf\n", l->livros[i].preco);
        printf("------------------------------\n");
    }
    return;
}

int inserirLivro(Lista *l, Livro *novolivro) {
    if (l->qtd < l->capacidade) {
        l->livros[l->qtd] = *novolivro;
        l->qtd++;
        return 0; // Sucesso
    } else {
        Livro *temp = (Livro *) realloc(l->livros, (l->capacidade + 3) * sizeof(Livro));
        if (temp == NULL) {
            printf("\nErro ao alocar memória para a lista de livros.\n");
            return 1; // Falha
        }
        l->livros = temp;
        l->capacidade += 3;
        l->livros[l->qtd] = *novolivro;
        l->qtd++;
        return 0; // Sucesso
    }
}

int removerLivro(Lista *l, char *titulo) {
    int idex = -1;
    for (int i = 0; i < l->qtd; i++) {
        if (strcmp(l->livros[i].titulo, titulo) == 0) {
            idex = i;
            break;
        }
    }

    if (idex != -1) {
        l->livros[idex] = l->livros[l->qtd - 1]; // Substitui o livro a ser removido pelo último livro da lista
        l->qtd--;
        return 0; // Sucesso
    }
    return 1; // Falha
}