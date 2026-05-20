#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "livros.h"

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    Lista *lista;
    int capacidade;
    printf("Digite a capacidade da lista de livros: ");
    scanf("%d", &capacidade);

    lista = criarLista(capacidade);
    if (lista == NULL) {
        printf("Erro ao criar a lista de livros.\n");
        return 1;
    }

    int opcao;
    do {
        printf("\n==========MENU==========\n");
        printf("\n1. Adicionar livro\n");
        printf("2. Remover livro\n");
        printf("3. Exibir livros\n");
        printf("0. Sair\n\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: {
                Livro *novolivro = criarLivro();
                if (novolivro == NULL) {
                    printf("\nErro ao criar o livro.\n");
                    break;
                }

                if(inserirLivro(lista, novolivro) == 0) {
                    printf("\nLivro adicionado com sucesso!\n");
                } else {
                    printf("\nErro ao adicionar o livro.\n");
                }
                free(novolivro);
                break;
            }
            case 2: {
                char titulo[30];
                printf("\nDigite o título do livro a ser removido: ");
                scanf(" %29[^\n]", titulo);
                limparBuffer();

                if (removerLivro(lista, titulo) == 0) {
                    printf("\nLivro removido com sucesso!\n");
                } else {
                    printf("\nErro ao remover o livro. Livro não encontrado.\n");
                }
                break;
            }
            case 3: {
                exibirLivros(lista);
                break;
            }
            case 0: {
                printf("\nSaindo do programa...\n");
                break;
            }
            default: {
                printf("\nOpção inválida. Tente novamente.\n");
            }
        }
    } while (opcao != 0);

    liberarLista(lista);
    system("pause");
    return 0;
}