#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct
{
    char *nome;
    char endereço[50];
    int telefone;
    char email[30];
} contato;

void addcontato(contato *agenda, int *Ncontatos, int *NMAXcontatos){
    if (*Ncontatos >= *NMAXcontatos){
        *NMAXcontatos += 1;
        agenda = (contato *) realloc(agenda, *NMAXcontatos * sizeof(contato));
        if (agenda == NULL){
            printf("Erro: Memória insuficiente.\n");
            exit(1);
        }
    }
    int j = 10;
    int i = 1;
    printf("Digite o nome do contato: ");
    agenda[*Ncontatos].nome = (char *)malloc(j * sizeof(char));
    while (agenda[*Ncontatos].nome[i-1] != '\n'){
        scanf("%c", &agenda[*Ncontatos].nome[i-1]);
        setbuf(stdin, NULL);
        i++;
        if (i >= j){
            j += 1;
            agenda[*Ncontatos].nome = (char *)realloc(agenda[*Ncontatos].nome, j * sizeof(char));
            if (agenda[*Ncontatos].nome == NULL){
                printf("Erro: Memória insuficiente.\n");
                exit(1);
            }
        }
    }
    agenda[*Ncontatos].nome[i-1] = '\0';
    printf("\nDigite o endereço do contato: ");
    scanf("%49[^\n]s", agenda[*Ncontatos].endereço);
    setbuf(stdin, NULL);
    printf("\nDigite o telefone do contato: ");
    scanf("%d", &agenda[*Ncontatos].telefone);
    setbuf(stdin, NULL);
    printf("\nDigite o email do contato: ");
    scanf("%29[^\n]s", agenda[*Ncontatos].email);
    setbuf(stdin, NULL);
    (*Ncontatos)++;

    printf("\nContato adicionado com sucesso!\n");
}

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    contato *agenda;
    int NMAXcontatos = 1, Ncontatos = 0; //número máximo de contatos e número atual de contatos
    agenda = (contato *)malloc(NMAXcontatos * sizeof(contato));
    if (agenda == NULL)
    {
        printf("Erro: Memória insuficiente.\n");
        exit(1);
    }

    int k;
    do
    {
        printf("1 - Cadastrar contato\n");
        printf("2 - Listar contatos\n");
        printf("3 - Buscar contato por nome\n");
        printf("4 - Buscar contato por telefone\n");
        printf("5 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &k);
        setbuf(stdin, NULL);

    } while (k != 5);
} //terminar funções e fazer switch case.