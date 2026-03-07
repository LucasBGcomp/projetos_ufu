#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct
{
    char *nome;
    char endereco[50];
    char telefone[20]; // Alterado para string (char array) para evitar estouro de limite de int e permitir zeros à esquerda
    char email[30];
} contato;

// Função auxiliar segura para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Passamos **agenda e *NMAXcontatos para poder dar realloc na main se necessário
void addcontato(contato **agenda, int *Ncontatos, int *NMAXcontatos)
{
    if (*Ncontatos >= *NMAXcontatos)
    {
        (*NMAXcontatos) += 3;
        *agenda = (contato *)realloc(*agenda, (*NMAXcontatos) * sizeof(contato));
        if (*agenda == NULL)
        {
            printf("Erro: Memória insuficiente.\n");
            exit(1);
        }
    }

    char bufferNome[200]; // Buffer temporário para ler o nome
    
    printf("\nDigite o nome do contato: ");
    scanf(" %199[^\n]", bufferNome); // Lê até 199 caracteres ou até o Enter
    limparBuffer();

    // Aloca exatamente o espaço necessário para o nome
    (*agenda)[*Ncontatos].nome = (char *)malloc((strlen(bufferNome) + 1) * sizeof(char));
    if ((*agenda)[*Ncontatos].nome == NULL) {
        printf("Erro: Memória insuficiente.\n");
        exit(1);
    }
    strcpy((*agenda)[*Ncontatos].nome, bufferNome);

    printf("Digite o endereço do contato: ");
    scanf(" %49[^\n]", (*agenda)[*Ncontatos].endereco);
    limparBuffer();

    printf("Digite o telefone do contato: ");
    scanf(" %19[^\n]", (*agenda)[*Ncontatos].telefone);
    limparBuffer();

    printf("Digite o email do contato: ");
    scanf(" %29[^\n]", (*agenda)[*Ncontatos].email);
    limparBuffer();

    (*Ncontatos)++;
    printf("\nContato adicionado com sucesso!\n\n");
}

void exibircontatos(contato *agenda, int Ncontatos)
{
    if (Ncontatos == 0)
    {
        printf("\nA agenda está vazia!\n\n");
        return;
    }
    printf("\nContatos na agenda:\n\n");
    for (int i = 0; i < Ncontatos; i++)
    {
        printf("Nome: %s\n", agenda[i].nome);
        printf("Endereço: %s\n", agenda[i].endereco);
        printf("Telefone: %s\n", agenda[i].telefone); // %s porque agora é string
        printf("Email: %s\n", agenda[i].email);
        printf("-----------------------------\n");
    }
    printf("\n");
}

void salvarctt(contato *agenda, int Ncontatos)
{
    FILE *fp = fopen("agenda.dat", "wb");
    if (fp == NULL)
    {
        printf("Erro ao salvar os contatos!\n");
        return; // Melhor dar return do que exit(1) para não fechar o app bruscamente
    }
    
    fwrite(&Ncontatos, sizeof(int), 1, fp);
    
    for (int i = 0; i < Ncontatos; i++)
    {
        int nome_len = strlen(agenda[i].nome);
        fwrite(&nome_len, sizeof(int), 1, fp);
        fwrite(agenda[i].nome, sizeof(char), nome_len, fp);
        fwrite(agenda[i].endereco, sizeof(char), 50, fp);
        fwrite(agenda[i].telefone, sizeof(char), 20, fp); // Alterado para 20 chars
        fwrite(agenda[i].email, sizeof(char), 30, fp);
    }
    fclose(fp);
    printf("Contatos salvos com sucesso!\n\n");
}

// Agora recebe ponteiro para ponteiro de agenda e o NMAXcontatos
int carregarctt(contato **agenda, int *NMAXcontatos)
{
    FILE *fp = fopen("agenda.dat", "rb");
    if (fp == NULL)
    {
        printf("Nenhum contato salvo encontrado. Iniciando uma nova agenda.\n\n");
        return 0;
    }
    
    int Ncontatos;
    fread(&Ncontatos, sizeof(int), 1, fp);

    // Se houver contatos no arquivo, precisamos garantir que a agenda tenha tamanho para eles!
    if (Ncontatos > 0) {
        *NMAXcontatos = Ncontatos + 2; // Dá um folga na memória
        *agenda = (contato *)realloc(*agenda, (*NMAXcontatos) * sizeof(contato));
    }

    for (int i = 0; i < Ncontatos; i++)
    {
        int nome_len;
        fread(&nome_len, sizeof(int), 1, fp);
        
        (*agenda)[i].nome = (char *)malloc((nome_len + 1) * sizeof(char));
        if ((*agenda)[i].nome == NULL) {
            printf("Erro: Memória insuficiente.\n");
            exit(1);
        }
        
        fread((*agenda)[i].nome, sizeof(char), nome_len, fp);
        (*agenda)[i].nome[nome_len] = '\0';
        fread((*agenda)[i].endereco, sizeof(char), 50, fp);
        fread((*agenda)[i].telefone, sizeof(char), 20, fp);
        fread((*agenda)[i].email, sizeof(char), 30, fp);
    }
    fclose(fp);
    return Ncontatos;
}

void PesquisarNome(contato *agenda, int Ncontatos)
{
    char nome_pesquisado[200];
    printf("\nDigite o nome do contato que deseja pesquisar: ");
    scanf(" %199[^\n]", nome_pesquisado);
    limparBuffer();

    int encontrado = 0;
    for (int i = 0; i < Ncontatos; i++)
    {
        // strcasecmp ignoraria maiúsculas e minúsculas, mas strcmp resolve o básico.
        if (strcmp(agenda[i].nome, nome_pesquisado) == 0)
        {
            printf("\n--- Contato Encontrado ---\n");
            printf("Nome: %s\n", agenda[i].nome);
            printf("Endereço: %s\n", agenda[i].endereco);
            printf("Telefone: %s\n", agenda[i].telefone);
            printf("Email: %s\n", agenda[i].email);
            printf("-----------------------------\n\n");
            encontrado = 1;
        }
    }
    if (encontrado == 0)
    {
        printf("Contato não encontrado!\n\n");
    }
}

void PesquisarTelefone(contato *agenda, int Ncontatos)
{
    char telefone_pesquisado[20];
    printf("\nDigite o telefone do contato que deseja pesquisar: ");
    scanf(" %19[^\n]", telefone_pesquisado);
    limparBuffer();

    int encontrado = 0;
    for (int i = 0; i < Ncontatos; i++)
    {
        if (strcmp(agenda[i].telefone, telefone_pesquisado) == 0)
        {
            printf("\n--- Contato Encontrado ---\n");
            printf("Nome: %s\n", agenda[i].nome);
            printf("Endereço: %s\n", agenda[i].endereco);
            printf("Telefone: %s\n", agenda[i].telefone);
            printf("Email: %s\n", agenda[i].email);
            printf("-----------------------------\n\n");
            encontrado = 1;
        }
    }
    if (encontrado == 0)
    {
        printf("Contato não encontrado!\n\n");
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    contato *agenda;
    int NMAXcontatos = 1; 
    agenda = (contato *)malloc(NMAXcontatos * sizeof(contato));
    if (agenda == NULL)
    {
        printf("Erro: Memória insuficiente.\n");
        exit(1);
    }

    // Passa o endereço de agenda e NMAXcontatos para atualizar a memória principal
    int Ncontatos = carregarctt(&agenda, &NMAXcontatos); 

    int opcao;
    do
    {
        printf("========== MENU ==========\n");
        printf("1 - Cadastrar contato\n");
        printf("2 - Listar contatos\n");
        printf("3 - Buscar contato por nome\n");
        printf("4 - Buscar contato por telefone\n");
        printf("5 - Salvar contatos\n");
        printf("6 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBuffer(); // Limpa o "Enter" que sobra após digitar a opção numérico

        switch (opcao)
        {
        case 1:
            addcontato(&agenda, &Ncontatos, &NMAXcontatos);
            break;
        case 2:
            exibircontatos(agenda, Ncontatos);
            break;
        case 3:
            PesquisarNome(agenda, Ncontatos);
            break;
        case 4:
            PesquisarTelefone(agenda, Ncontatos);
            break;
        case 5:
            salvarctt(agenda, Ncontatos);
            break;
        case 6:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n\n");
            break;
        }

    } while (opcao != 6);

    // IMPORTANTE: Liberar a memória de cada 'nome' ANTES de liberar a 'agenda'
    for (int i = 0; i < Ncontatos; i++) {
        free(agenda[i].nome);
    }
    free(agenda); 
    
    return 0;
}