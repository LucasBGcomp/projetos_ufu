#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "bib.h"

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    Descritor *lista;
    inicializarLista(&lista);

    int opcao;

    do
    {
        printf("\n===============MENU===============\n\n");
        printf("1. Adicionar elemento no início\n");
        printf("2. Adicionar elemento no final\n");
        printf("3. Remover elemento do início\n");
        printf("4. Remover elemento do final\n");
        printf("5. Remover elemento específico\n");
        printf("6. Exibir lista\n");
        printf("0. Sair\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {
            int valor;
            printf("\nDigite o valor a ser adicionado: ");
            scanf("%d", &valor);
            if (adicionarNoInicio(lista, valor))
            {
                printf("\nElemento adicionado com sucesso!\n");
            }
            else
            {
                printf("\nFalha ao adicionar elemento.\n");
            }
            break;
        }
        case 2:
        {
            int valor;
            printf("\nDigite o valor a ser adicionado: ");
            scanf("%d", &valor);
            if (adicionarNoFinal(lista, valor))
            {
                printf("\nElemento adicionado com sucesso!\n");
            }
            else
            {
                printf("\nFalha ao adicionar elemento.\n");
            }
            break;
        }
        case 3:
            if (removerDoInicio(lista))
            {
                printf("\nElemento removido com sucesso!\n");
            }
            else
            {
                printf("\nFalha ao remover elemento.\n");
            }
            break;

        case 4:
            if (removerDoFinal(lista))
            {
                printf("\nElemento removido com sucesso!\n");
            }
            else
            {
                printf("\nFalha ao remover elemento.\n");
            }
            break;

        case 5:
        {
            int valor;
            printf("\nDigite o valor a ser removido: ");
            scanf("%d", &valor);
            if (removerElemento(lista, valor))
            {
                printf("\nElemento removido com sucesso!\n");
            }
            else
            {
                printf("\nFalha ao remover elemento. Elemento não encontrado.\n");
            }
            break;
        }
        case 6:
            exibirLista(lista);
            break;

        case 0:
            printf("\nSaindo do programa...\n");
            break;

        default:
            printf("\nOpção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    liberarLista(lista);
    system("pause");
    return 0;
}