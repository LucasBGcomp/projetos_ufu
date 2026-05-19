#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "bib.h"

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    Lista *l = NULL;
    int max;
    printf("Digite o número de produtos diferentes do estoque: ");
    scanf("%d", &max);

    l = criarLista(max);
    if (l == NULL)
    {
        printf("Falha ao criar a lista de produtos.\n");
        liberarLista(l);
        return 1;
    }


    int codP, qtdV;
    char nomeP[15];
    int opcao;
    do
    {
        printf("\n\n===================Menu===================\n\n1 - Inserir novo produto\n2 - Exibir produtos\n3 - Exibir produto com menor preço\n4 - Realizar venda pesquisando por código\n5 - Realizar venda pesquisando por nome\n6 - Sair\n\nDigite a opção desejada: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao)
        {
        case 1:
        {
            Produto *p;
            p = criarProduto();
            if (p == NULL)
            {
                printf("Falha ao criar o produto.\n");
                free(p);
                liberarLista(l);
                return 1;
            }
            if (inserirProduto(l, p) == 0)
            {
                printf("\nCapacidade máxima atingida. Deseja aumentar a capacidade? (1 - Sim, 0 - Não): ");
                int op;
                scanf("%d", &op);
                if (op == 1)
                {
                    printf("Digite a nova capacidade: ");
                    scanf("%d", &max);
                    if (maisCapacidade(l, max) == 0)
                    {
                        printf("Falha ao aumentar a capacidade da lista de produtos.\n");
                        free(p);
                        liberarLista(l);
                        return 1;
                    } else {
                        if (inserirProduto(l, p) == 0)
                        {
                            printf("\nProduto não inserido mesmo após aumentar a capacidade.\n");
                        } else {
                            printf("\nProduto inserido com sucesso após aumentar a capacidade.\n");
                        }
                    }
                }
                else
                {
                    printf("\nProduto não inserido.\n");
                }
            } else {
                printf("\nProduto inserido com sucesso.\n");
            }
            free(p);
            break;
        }
        case 2:
            exibirProdutos(l);
            break;
        case 3:
            menorPreco(l);
            break;
        case 4:
            printf("Digite o código do produto a ser vendido: ");
            scanf("%d", &codP);
            printf("Digite a quantidade a ser vendida: ");
            scanf("%d", &qtdV);
            venda_porCodigo(l, qtdV, codP);
            break;
        case 5:
            printf("Digite o nome do produto a ser vendido: ");
            scanf(" %14[^\n]", nomeP);
            limparBuffer();
            printf("Digite a quantidade a ser vendida: ");
            scanf("%d", &qtdV);
            venda_porNome(l, qtdV, nomeP);
            break;
        case 6:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 6);

    liberarLista(l);
    system("pause");
    return 0;
}