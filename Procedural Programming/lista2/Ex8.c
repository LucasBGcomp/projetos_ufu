/*Escreva um programa que armazene em um registro de dados (estrutura composta) os dados de um
funcionário de uma empresa, compostos de: Nome, Idade, Sexo (M/F), CPF, Data de Nascimento,
Código do Setor onde trabalha (0-99), Cargo que ocupa (string de até 30 caracteres) e Salário. Os
dados devem ser digitados pelo usuário, armazenados na estrutura e exibidos na tela.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "Portuguese_Brazil");

    typedef struct {
        char nome[50];
        int idade;
        char sexo;
        char cpf[16];
        char dataNascimento[12];
        int codigoSetor;
        char cargo[31];
        float salario;
    } funcionario;

    funcionario fcn;

    setbuf(stdin, NULL);

    printf("Digite o nome do funcionário: ");
    scanf("%49[^\n]", fcn.nome);
    setbuf(stdin, NULL);
    printf("Digite a idade do funcionário: ");
    scanf("%d", &fcn.idade);
    setbuf(stdin, NULL);
    printf("Digite o sexo do funcionário (M/F): ");
    scanf("%c", &fcn.sexo);
    setbuf(stdin, NULL);
    printf("Digite o CPF do funcionário: ");
    scanf("%15[^\n]", fcn.cpf);
    setbuf(stdin, NULL);
    printf("Digite a data de nascimento do funcionário (DD/MM/AAAA): ");
    scanf("%11[^\n]", fcn.dataNascimento);
    setbuf(stdin, NULL);
    do {
        printf("Digite o código do setor onde o funcionário trabalha (0-99): ");
        scanf("%d", &fcn.codigoSetor);
        setbuf(stdin, NULL);
    } while (fcn.codigoSetor < 0 || fcn.codigoSetor > 99);
    printf("Digite o cargo do funcionário: ");
    scanf("%30[^\n]", fcn.cargo);
    setbuf(stdin, NULL);
    printf("Digite o salário do funcionário: ");
    scanf("%f", &fcn.salario);
    setbuf(stdin, NULL);

    printf("\n=====Funcionário cadastrado com sucesso!=====\n\n");
    printf("Nome: %s\nIdade: %d\nSexo: %c\nCPF: %s\nData de Nascimento: %s\nCódigo do Setor: %d\nCargo: %s\nSalário: R$%.2f\n\n", fcn.nome, fcn.idade, fcn.sexo, fcn.cpf, fcn.dataNascimento, fcn.codigoSetor, fcn.cargo, fcn.salario);
    printf("=============================================\n\n");

    system("pause");
    return 0;

}