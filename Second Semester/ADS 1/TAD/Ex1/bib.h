#ifndef _BIB_H
#define _BIB_H
typedef struct
{
    int codProd;
    char nomeProd[15];
    float preco;
    int qtdeEstoque;
} Produto;

typedef struct
{
    Produto *dados;
    int qtd;
} Lista;

void limparBuffer();

void criarLista(Lista *l, int n); // Lista passada por referência e o número de produtos por valor

void exibirProdutos(Lista *l); // Lista passada por referência

void maisCapacidade(Lista *l, int n); // Lista passada por referência e o número de produtos por valor

void inserirProduto(Lista *l, Produto p); // Lista passada por referência e o produto a ser inserido por valor

void menorPreco(Lista *l); // Lista passada por referência

void venda_porCodigo(Lista *l, int qtdV, int codP); // Lista passada por referência, quantidade a ser vendida e código do produto por valor

void venda_porNome(Lista *l, int qtdV, char nomeP[15]); // Lista e string passadas por referência, quantidade a ser vendida por valor
#endif