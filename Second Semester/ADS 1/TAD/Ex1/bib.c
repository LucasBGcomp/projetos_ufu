#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib.h"

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void criarLista(Lista *l, int n)
{
    l->dados = (Produto *) malloc(n * sizeof(Produto));
    l->qtd = 0;
}

void exibirProdutos(Lista *l)
{
    if (l->qtd == 0)
    {
        printf("Nenhum produto no estoque.\n");
    }
    else
    {
        printf("Produtos no estoque:\n");
        for (int i = 0; i < l->qtd; i++)
        {
            printf("> Código: %d, Nome: %s, Preço: %.2f, Quantidade em estoque: %d\n",
                   l->dados[i].codProd, l->dados[i].nomeProd, l->dados[i].preco, l->dados[i].qtdeEstoque);
        }
    }
}

void inserirProduto(Lista *l, Produto p)
{
    l->dados[l->qtd] = p;
    l->qtd++;
    printf("Produto inserido com sucesso!\n");
}

void maisCapacidade(Lista *l, int n)
{
    l->dados = (Produto *)realloc(l->dados, n * sizeof(Produto));
    printf("Capacidade aumentada para %d produtos.\n", n);
}

void menorPreco(Lista *l)
{
    if (l->qtd == 0)
    {
        printf("Nenhum produto no estoque.\n");
        return;
    }
    else
    {
        Produto menor = l->dados[0];
        for (int i = 1; i < l->qtd; i++)
        {
            if (l->dados[i].preco < menor.preco)
            {
                menor = l->dados[i];
            }
        }
        printf("Produto com menor preço: %s, Preço: %.2f\n", menor.nomeProd, menor.preco);
    }
}

void venda_porCodigo(Lista *l, int qtdV, int codP)
{
    for (int i = 0; i < l->qtd; i++)
    {
        if (l->dados[i].codProd == codP)
        {
            if (l->dados[i].qtdeEstoque >= qtdV)
            {
                l->dados[i].qtdeEstoque -= qtdV;
                printf("Venda realizada: %d unidades do produto %s\n", qtdV, l->dados[i].nomeProd);
            }
            else
            {
                printf("Estoque insuficiente para realizar a venda!");
            }
            return;
        }
    }
    printf("Produto com código %d não encontrado.\n", codP);
}

void venda_porNome(Lista *l, int qtdV, char nomeP[15])
{
    for (int i = 0; i < l->qtd; i++)
    {
        if (strcmp(l->dados[i].nomeProd, nomeP) == 0)
        {
            if (l->dados[i].qtdeEstoque >= qtdV)
            {
                l->dados[i].qtdeEstoque -= qtdV;
                printf("Venda realizada: %d unidades do produto %s\n", qtdV, l->dados[i].nomeProd);
            }
            else
            {
                printf("Estoque insuficiente para realizar a venda!");
            }
            return;
        }
    }
    printf("Produto não encontrado.\n");
}