#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib.h"

struct produto
{
    int codProd;
    char nomeProd[15];
    float preco;
    int qtdeEstoque;
};

struct lista
{
    Produto *dados;
    int qtd;
    int capacidade;
};

void liberarLista(Lista *l)
{
    free(l->dados);
    free(l);
}

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

Lista* criarLista(int tam)
{
    Lista *novaLista = (Lista *) malloc(sizeof(Lista));
    novaLista->dados = (Produto *) malloc(tam * sizeof(Produto));
    if (novaLista->dados == NULL)
    {
        free(novaLista);
        return NULL;
    }
    novaLista->qtd = 0;
    novaLista->capacidade = tam;
    return novaLista;
}

Produto* criarProduto(){
    Produto *novoProduto = (Produto *) malloc(sizeof(Produto));
    if (novoProduto == NULL)
        return NULL;
    
    int cod, qtde;
    float preco;
    char nome[15];
    printf("Digite o código do produto: ");
    scanf("%d", &cod);
    printf("Digite o nome do produto: ");
    scanf(" %14[^\n]", nome);
    limparBuffer();
    printf("Digite o preço do produto: ");
    scanf("%f", &preco);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &qtde);
    novoProduto->codProd = cod;
    novoProduto->preco = preco;
    novoProduto->qtdeEstoque = qtde;
    strcpy(novoProduto->nomeProd, nome);
    return novoProduto;
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

int inserirProduto(Lista *l, Produto *p)
{
    if (l->qtd < l->capacidade)
    {
        l->dados[l->qtd] = *p;
        l->qtd++;
        return 1; // Sucesso na inserção
    }
    else
    {
        return 0; // Falha na inserção, capacidade atingida
    }
}

int maisCapacidade(Lista *l, int n)
{
    Produto *temp;
    temp = (Produto *)realloc(l->dados, n * sizeof(Produto));
    if (temp == NULL)
        return 0; // Falha na realocação

    l->dados = temp;
    l->capacidade = n;
    return 1; // Sucesso na realocação
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
                printf("\nVenda realizada: %d unidades do produto %s\n", qtdV, l->dados[i].nomeProd);
            }
            else
            {
                printf("\nEstoque insuficiente para realizar a venda!\n");
            }
            return;
        }
    }
    printf("\nProduto com código %d não encontrado.\n", codP);
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
                printf("\nVenda realizada: %d unidades do produto %s\n", qtdV, l->dados[i].nomeProd);
            }
            else
            {
                printf("\nEstoque insuficiente para realizar a venda!\n");
            }
            return;
        }
    }
    printf("\nProduto não encontrado.\n");
}