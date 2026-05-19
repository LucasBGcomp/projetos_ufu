#ifndef _BIB_H
#define _BIB_H

typedef struct produto Produto;

typedef struct lista Lista;

void liberarLista(Lista *l);

void limparBuffer();

Lista* criarLista(int n); // Número de produtos por valor

Produto* criarProduto();

void exibirProdutos(Lista *l); // Lista passada por valor

int maisCapacidade(Lista *l, int n); // Lista passada por referência e o número de produtos por valor

int inserirProduto(Lista *l, Produto *p); // Lista e produto passados por referência

void menorPreco(Lista *l); // Lista passada por valor

void venda_porCodigo(Lista *l, int qtdV, int codP); // Lista passada por referência, quantidade a ser vendida e código do produto por valor

void venda_porNome(Lista *l, int qtdV, char nomeP[15]); // Lista e string passadas por referência, quantidade a ser vendida por valor
#endif