#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "bib.h"

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    Lista l;
    int max;
    printf("Digite o número de produtos diferentes do estoque: ");
    scanf("%d", &max);

    criarLista(&l, max);

    int codP, qtdV;
    char nomeP[15];
    int k;
    do
    {
        printf("\n\n===================Menu===================\n\n1 - Inserir novo produto\n2 - Exibir produtos\n3 - Exibir produto com menor preço\n4 - Realizar venda pesquisando por código\n5 - Realizar venda pesquisando por nome\n6 - Sair\n\nDigite a opção desejada: ");
        scanf("%d", &k);
        printf("\n");

        switch (k)
        {
        case 1:
            if (l.qtd < max)
            {
                Produto p;
                printf("Digite o código do produto: ");
                scanf("%d", &p.codProd);
                printf("Digite o nome do produto: ");
                scanf(" %14[^\n]", p.nomeProd);
                limparBuffer();
                printf("Digite o preço do produto: ");
                scanf("%f", &p.preco);
                printf("Digite a quantidade em estoque: ");
                scanf("%d", &p.qtdeEstoque);
                inserirProduto(&l, p);
            }
            else
            {
                printf("Capacidade máxima de produtos atingida!\n");
                printf("Gostaria de aumentar a capacidade? (1 - Sim, 0 - Não): ");
                int op;
                scanf("%d", &op);
                if (op == 1)
                {
                    printf("Digite a nova capacidade: ");
                    scanf("%d", &max);
                    maisCapacidade(&l, max);
                }
                else
                {
                    printf("Operação cancelada.\n");
                }
            }
            break;
        case 2:
            exibirProdutos(&l);
            break;
        case 3:
            menorPreco(&l);
            break;
        case 4:
            printf("Digite o código do produto a ser vendido: ");
            scanf("%d", &codP);
            printf("Digite a quantidade a ser vendida: ");
            scanf("%d", &qtdV);
            venda_porCodigo(&l, qtdV, codP);
            break;
        case 5:
            printf("Digite o nome do produto a ser vendido: ");
            scanf(" %14[^\n]", nomeP);
            limparBuffer();
            printf("Digite a quantidade a ser vendida: ");
            scanf("%d", &qtdV);
            venda_porNome(&l, qtdV, nomeP);
            break;
        case 6:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (k != 6);

    free(l.dados);
    system("pause");
    return 0;
}