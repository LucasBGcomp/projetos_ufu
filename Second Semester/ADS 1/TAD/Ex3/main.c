#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "bib.h"

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    No* lista = criar_lista();
    int opcao;

    do{
        printf("\n=============MENU=============\n");
        printf("\n1. Inserir aluno\n");
        printf("2. Pesquisar aluno\n");
        printf("3. Remover aluno\n");
        printf("4. Listar alunos\n");
        printf("5. Alunos com média >= 70%%\n");
        printf("0. Sair\n\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1: {
                Aluno* a = criar_aluno();
                lista = inserir_aluno(lista, a);
                break;
            }
            case 2: {
                char nome[50];
                printf("\nDigite o nome do aluno a pesquisar: ");
                scanf(" %49[^\n]", nome);
                limpar_buffer();
                if (pesquisar_notas(lista, nome) == 0) {
                    printf("\nAluno não encontrado.\n\n");
                }
                break;
            }
            case 3: {
                char nome[50];
                printf("\nDigite o nome do aluno a remover: ");
                scanf(" %49[^\n]", nome);
                limpar_buffer();
                if (remover_aluno(lista, nome) == 0) {
                    printf("\nAluno não encontrado.\n\n");
                } else {
                    printf("\nAluno removido com sucesso.\n\n");
                }
                break;
            }
            case 4:
                imprimir_lista(lista);
                break;
            case 5: {
                No* media70 = media_70(lista);
                printf("\nAlunos com média >= 70:\n");
                imprimir_lista(media70);
                liberar_lista(media70);
                break;
            }
            case 0:
                printf("Saindo...\n");
                break;
        }
    } while (opcao != 0);

    liberar_lista(lista);
    system("pause");
    return 0;
}