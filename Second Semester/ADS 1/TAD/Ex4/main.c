#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "bib.h"

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    No *lista;
    No *primos;
    criarLV(&lista);
    criarLV(&primos);
    int opcao;

    do
    {
        printf("\n==================MENU==================\n");
        printf("\n1 - Inserir Elemento\n");
        printf("2 - Ler Elementos de Arquivo\n");
        printf("3 - Exibir Lista\n");
        printf("4 - Número de Elementos\n");
        printf("5 - Número de Elementos (recursivo)\n");
        printf("6 - Palavras de Tamanho Primo\n");
        printf("7 - Remover Palavra\n");
        printf("8 - Remover Repetidas\n");
        printf("0 - Sair\n\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {
            char *elem = (char *)malloc(200 * sizeof(char));
            if (elem == NULL)
            {
                printf("\nERRO\n");
                liberarLista(lista);
                liberarLista(primos);
                system("pause");
                return 6;
            }
            printf("\nDigite a palavra: ");
            scanf(" %199[^\n]", elem);
            char *temp = (char *)realloc(elem, (strlen(elem) + 1) * sizeof(char));
            if (temp == NULL)
            {
                printf("\nERRO\n");
                free(elem);
                liberarLista(lista);
                liberarLista(primos);
                system("pause");
                return 7;
            }
            elem = temp;

            if (inserirElemento(&lista, elem) == 0)
            {
                printf("\nElemento adicionado!\n");
            }
            else
            {
                printf("\nERRO\n");
                free(elem);
                liberarLista(lista);
                liberarLista(primos);
                system("pause");
                return 4;
            }

            free(elem);
            break;
        }
        case 2:
        {
            if (lerArquivo(&lista) == 0)
            {
                printf("\nElementos adicionados!\n");
            }
            else
            {
                printf("\nERRO\n");
                liberarLista(lista);
                liberarLista(primos);
                system("pause");
                return 4;
            }
            break;
        }
        case 3:
        {
            int op;
            printf("\nQual lista exibir?\n");
            printf("\n1 - Lista Principal\n");
            printf("\n2 - Lista de Palavras de Tamanho Primo\n\n");
            printf("Escolha um opção: ");
            scanf("%d", &op);

            if (op == 1)
            {
                if (lista == NULL)
                {
                    printf("\nA lista está vazia!\n");
                }
                else
                {
                    printf("\nElementos da lista:\n\n");
                    exibirLista(lista);
                }
            }
            else if (op == 2)
            {
                if (primos == NULL)
                {
                    printf("\nA lista está vazia!\n");
                }
                else
                {
                    printf("\nElementos da lista:\n\n");
                    exibirLista(primos);
                }
            }
            else
            {
                printf("\nOpção Inválida!!!\n");
            }
            break;
        }
        case 4:
        {
            int op;
            printf("\nQual lista examinar?\n");
            printf("\n1 - Lista Principal\n");
            printf("\n2 - Lista de Palavras de Tamanho Primo\n\n");
            printf("Escolha um opção: ");
            scanf("%d", &op);

            if (op == 1)
            {
                printf("\nA lista tem %d elementos\n", N_elem(lista));
            }
            else if (op == 2)
            {
                printf("\nA lista tem %d elementos\n", N_elem(primos));
            }
            else
            {
                printf("\nOpção Inválida!!!\n");
            }
            break;
        }
        case 5:
        {
            int op;
            printf("\nQual lista examinar?\n");
            printf("\n1 - Lista Principal\n");
            printf("\n2 - Lista de Palavras de Tamanho Primo\n\n");
            printf("Escolha um opção: ");
            scanf("%d", &op);

            if (op == 1)
            {
                printf("\nA lista tem %d elementos\n", N_elemRec(lista));
            }
            else if (op == 2)
            {
                printf("\nA lista tem %d elementos\n", N_elemRec(primos));
            }
            else
            {
                printf("\nOpção Inválida!!!\n");
            }
            break;
        }
        case 6:
            if (lista == NULL)
            {
                printf("\nA lista está vazia\n");
            }
            else
            {
                printf("\nLista de palavras de tamanho primo:\n\n");
                liberarLista(primos);
                criarLV(&primos);
                tamPrimo(lista, &primos);
                exibirLista(primos);
            }
            break;
        case 7:
        {
            char *elem = (char *)malloc(200 * sizeof(char));
            if (elem == NULL)
            {
                printf("\nERRO\n");
                liberarLista(lista);
                liberarLista(primos);
                system("pause");
                return 8;
            }
            printf("\nDigite a palavra a ser removida: ");
            scanf(" %199[^\n]", elem);
            char *temp = (char *)realloc(elem, (strlen(elem) + 1) * sizeof(char));
            if (temp == NULL)
            {
                printf("\nERRO\n");
                free(elem);
                liberarLista(lista);
                liberarLista(primos);
                system("pause");
                return 9;
            }
            elem = temp;

            if (removerElemento(&lista, elem) == 1)
            {
                printf("\nElemento removido!\n");
            }
            else
            {
                printf("\nElemento não encontrado\n");
            }

            free(elem);
            break;
        }
        case 8:
        {
            int op;
            printf("\nDe qual lista remover?\n");
            printf("\n1 - Lista Principal\n");
            printf("\n2 - Lista de Palavras de Tamanho Primo\n\n");
            printf("Escolha um opção: ");
            scanf("%d", &op);

            if (op == 1)
            {
                if (lista == NULL)
                {
                    printf("\nA lista está vazia!\n");
                }
                else
                {
                    removeRepetidas(&lista);
                }
            }
            else if (op == 2)
            {
                if (primos == NULL)
                {
                    printf("\nA lista está vazia!\n");
                }
                else
                {
                    removeRepetidas(&primos);
                }
            }
            else
            {
                printf("\nOpção Inválida!!!\n");
            }
            break;
        }
        case 0:
            printf("\nSaindo...\n");
            break;
        default:
            printf("Opção Inválida!");
        }
    } while (opcao != 0);

    liberarLista(lista);
    liberarLista(primos);
    system("pause");
    return 0;
}