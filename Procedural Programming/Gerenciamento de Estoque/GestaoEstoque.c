#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct{
    int id;
    char nome[25];
    int quantidade;
    float preco;
} produto;

void cadastrarProduto(produto p[], int *n) {
    if (*n >= 100) {
        printf("Limite de produtos atingido!\n");
        return;
    }
    printf("ID: ");
    scanf("%d", &p[*n].id);
    setbuf(stdin, NULL);
    
    printf("Nome: ");
    scanf("%24[^\n]s", p[*n].nome);
    setbuf(stdin, NULL);

    printf("Quantidade: ");
    scanf("%d", &p[*n].quantidade);
    setbuf(stdin, NULL);

    printf("Preço: ");
    scanf("%f", &p[*n].preco);
    setbuf(stdin, NULL);
    (*n)++;

    printf("Produto cadastrado com sucesso!\n\n");
}

void exibirEstoque(produto p[], int n){
    if (n == 0) {
        printf("O estoque está vazio!\n");
        return;
    }
    printf("Estoque atual:\n\n");
    for (int i = 0; i < n; i++){
        printf("ID: %.3d\n", p[i].id);
        printf("Nome: %s\n", p[i].nome);
        printf("Quantidade: %d\n", p[i].quantidade);
        printf("Preço: R$ %.2f\n", p[i].preco);
        printf("\n-----------------------------\n\n");
    }
}

void salvar(produto p[], int n){
    FILE *fp;
    fp = fopen("estoque.dat", "wb");
    if (fp == NULL){
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }
    fwrite(&n, sizeof(int), 1, fp);
    fwrite (p, sizeof(produto), n, fp);
    fclose(fp);
    printf("Estoque salvo com sucesso!\n\n");
}

int carregar(produto p[]){
    FILE *fp;
    fp = fopen("estoque.dat", "rb");
    if (fp == NULL){
        return 0;
    }
    int n;
    fread(&n, sizeof(int), 1, fp);
    fread(p, sizeof(produto), n, fp);
    fclose(fp);
    return n;
}

int main() {

    setlocale(LC_ALL, "Portuguese_Brazil");

    produto estoque[100];
    int n = carregar(estoque);
    int opcao;

    do {
        printf("1. Cadastrar produto\n");
        printf("2. Exibir estoque\n");
        printf("3. Salvar estoque\n");
        printf("4. Sair\n\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                cadastrarProduto(estoque, &n);
                break;
            case 2:
                exibirEstoque(estoque, n);
                break;
            case 3:
                salvar(estoque, n);
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida!\n\n");
        }
    } while (opcao != 4);

    system("pause");
    return 0;
}