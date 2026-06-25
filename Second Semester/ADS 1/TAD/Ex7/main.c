#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "bib.h"

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    int op;
    srand(time(NULL));
    Descritor *lista;
    inicializarLista(&lista);
    if (lista == NULL)
    {
        return 1;
    }

    do
    {
        printf("\n=======MENU=======\n\n1. Inserir Pessoa\n2. Sortear Líder\n0. Sair\n\nEscolha uma opção: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
        {
            char nome[20];
            limparBuffer();
            printf("\nDigite o nome da pessoa: ");
            scanf(" %19[^\n]", nome);

            if (inserirInicio(lista, nome))
            {
                printf("\nInserção feita!\n");
            }
            else
            {
                printf("\nErro na inserção\n");
            }
            break;
        }
        case 2:
            lider(lista, rand());
            break;
        case 0:
            break;
        default:
            printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (op != 0);

    liberarLista(lista);
    printf("\nPressione Enter para sair...");
    getchar();
    return 0;
}