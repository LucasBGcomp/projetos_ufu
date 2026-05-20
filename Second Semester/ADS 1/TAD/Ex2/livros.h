#ifndef _LIVROS_H
#define _LIVROS_H

typedef struct livro Livro;
typedef struct lista Lista;

void limparBuffer();
Lista *criarLista(int tam);
Livro *criarLivro();
void liberarLista(Lista *l);
void exibirLivros(Lista *l);
int inserirLivro(Lista *l, Livro *novoLivro);
int removerLivro(Lista *l, char *titulo);

#endif