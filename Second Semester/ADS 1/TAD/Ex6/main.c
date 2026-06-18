#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "bib.h"

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    Descritor *lista;
    inicializarLista(&lista);
    if (lista == NULL)
    {
        printf("Erro ao criar lista!!");
        return 1;
    }

    int opcao;

    do
    {
        printf("\n=========MENU=========\n\n1. Adicionar nave\n2. Exibir naves\n3. Iniciar ciclo\n0. Sair\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {
            int cap = 1;
            int qtd = 0;
            char nome[6];
            printf("\nDigite o nome da nave (máximo 5 caracteres): ");
            limparBuffer();
            scanf(" %5[^\n]", nome);
            do
            {
                if (cap <= 0)
                {
                    printf("\nCapacidade máxima de combustível deve ser maior que 0. Tente novamente.\n");
                }
                printf("\nDigite a capacidade máxima de combustível da nave (maior que 0): ");
                limparBuffer();
                scanf("%d", &cap);
            } while (cap <= 0);
            
            do
            {
                if (qtd > cap)
                {
                    printf("\nQuantidade atual de combustível não pode ser maior que a capacidade máxima. Tente novamente.\n");
                }
                printf("\nDigite a quantidade atual de combustível da nave (Menor ou igual a %d): ", cap);
                limparBuffer();
                scanf("%d", &qtd);
            } while (qtd > cap);

            if (adicionarNave(lista, cap, qtd, nome))
            {
                printf("\nNave adicionada com sucesso!\n");
            }
            else
            {
                printf("\nFalha ao adicionar nave.\n");
            }
            break;
        }
        case 2:
            exibirNaves(lista);
            break;
        case 3:
        {
            int n;
            printf("\nDigite a quantidade de combustível a ser adicionada por ciclo: ");
            limparBuffer();
            scanf("%d", &n);

            if (realizarCiclo(lista, n))
            {
                printf("\nCiclo realizado com sucesso!\n");
            }
            else
            {
                printf("\nFalha ao realizar ciclo.\n");
            }
            break;
        }
        case 0:
            limparBuffer();
            break;
        default:
            printf("\nOpção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    liberarLista(lista);
    printf("\nPressione Enter para sair...");
    getchar();
    return 0;
}