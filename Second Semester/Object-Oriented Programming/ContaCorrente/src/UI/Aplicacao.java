package UI;

import java.util.Scanner;

import entidades.*;

public class Aplicacao {
    public static void main(String[] args) {
        Banco b = new Banco("Banco do Brasil");

        int op;
        String nTitular1;
        String nTitular2;
        double valorTransacao;
        boolean contaEncontrada1;
        boolean contaEncontrada2;
        Scanner sc = new Scanner(System.in);
        do {
            System.out.println("=======MENU=======");
            System.out.println("1. Abrir conta");
            System.out.println("2. Exibir saldo");
            System.out.println("3. Exibir extrato");
            System.out.println("4. Sacar");
            System.out.println("5. Depositar");
            System.out.println("6. Transferir");
            System.out.println("0. Sair");
            System.out.println();
            System.out.print("Escolha uma opcao: ");
            op = sc.nextInt();

            switch (op) {
                case 1:
                    sc.nextLine();
                    System.out.println("Digite o nome do cliente: ");
                    String nome = sc.nextLine();
                    System.out.println("Digite o endereco do cliente: ");
                    String endereco = sc.nextLine();
                    System.out.println("A conta e especial? (true/false): ");
                    boolean isEspecial = sc.nextBoolean();
                    Cliente cliente = new Cliente(nome, endereco);
                    if (b.abrirConta(cliente, isEspecial)) {
                        System.out.println(
                                "Conta aberta com sucesso para " + cliente.nome + ". Saldo inicial: R$ 1000.0");
                    } else {
                        System.out.println("Erro ao abrir a conta.");
                    }
                    break;
                case 2:
                    sc.nextLine();
                    System.out.println("Digite o nome do titular da conta: ");
                    nTitular1 = sc.nextLine();
                    contaEncontrada1 = false;
                    for (ContaCorrente conta : b.contas) {
                        if (conta.titular.nome.equalsIgnoreCase(nTitular1)) {
                            System.out.println("Saldo da conta de " + conta.titular.nome + ": ");
                            conta.exibirSaldo();
                            contaEncontrada1 = true;
                            break;
                        }
                    }
                    if (!contaEncontrada1) {
                        System.out.println("Conta nao encontrada.");
                    }
                    break;
                case 3:
                    sc.nextLine();
                    System.out.println("Digite o nome do titular da conta: ");
                    nTitular1 = sc.nextLine();
                    contaEncontrada1 = false;
                    for (ContaCorrente conta : b.contas) {
                        if (conta.titular.nome.equalsIgnoreCase(nTitular1)) {
                            System.out.println("Extrato da conta de " + conta.titular.nome + ":");
                            System.out.println();
                            conta.exibirExtrato();
                            contaEncontrada1 = true;
                            break;
                        }
                    }
                    if(!contaEncontrada1) {
                        System.out.println("Conta nao encontrada.");
                    }
                    break;
                case 4:
                    sc.nextLine();
                    System.out.println("Digite o nome do titular da conta: ");
                    nTitular1 = sc.nextLine();
                    contaEncontrada1 = false;
                    System.out.println("Digite o valor a ser sacado: ");
                    valorTransacao = sc.nextDouble();
                    for (ContaCorrente conta : b.contas) {
                        if (conta.titular.nome.equalsIgnoreCase(nTitular1)) {
                            contaEncontrada1 = true;
                            if (conta.sacar(valorTransacao)) {
                                System.out.println("Saque realizado. O valor sacado da conta de " + conta.titular.nome
                                        + " e: R$ " + valorTransacao);
                            } else {
                                System.out.println(
                                        "Nao foi possivel realizar o saque. Verifique o saldo e tente novamente.");
                            }
                            break;
                        }
                    }
                    if(!contaEncontrada1) {
                        System.out.println("Conta nao encontrada.");
                    }
                    break;
                case 5:
                    sc.nextLine();
                    System.out.println("Digite o nome do titular da conta: ");
                    nTitular1 = sc.nextLine();
                    contaEncontrada1 = false;
                    System.out.println("Digite o valor a ser depositado: ");
                    valorTransacao = sc.nextDouble();
                    for (ContaCorrente conta : b.contas) {
                        if (conta.titular.nome.equalsIgnoreCase(nTitular1)) {
                            contaEncontrada1 = true;
                            if (conta.depositar(valorTransacao)) {
                                System.out.println("Deposito realizado. O valor depositado na conta de "
                                        + conta.titular.nome + " e: R$ " + valorTransacao);
                            } else {
                                System.out.println("Nao foi possivel realizar o deposito. Tente novamente.");
                            }
                            break;
                        }
                    }
                    if(!contaEncontrada1) {
                        System.out.println("Conta nao encontrada.");
                    }
                    break;
                case 6:
                    sc.nextLine();
                    System.out.println("Digite o nome do titular da conta de origem: ");
                    nTitular1 = sc.nextLine();
                    System.out.println("Digite o nome do titular da conta de destino: ");
                    nTitular2 = sc.nextLine();
                    System.out.println("Digite o valor a ser transferido: ");
                    valorTransacao = sc.nextDouble();
                    contaEncontrada1 = false;
                    contaEncontrada2 = false;
                    for (ContaCorrente contaOrigem : b.contas) {
                        if (contaOrigem.titular.nome.equalsIgnoreCase(nTitular1)) {
                            contaEncontrada1 = true;
                            for (ContaCorrente contaDestino : b.contas) {
                                if (contaDestino.titular.nome.equalsIgnoreCase(nTitular2)) {
                                    contaEncontrada2 = true;
                                    if (contaOrigem.transferir(valorTransacao, contaDestino)) {
                                        System.out.println("Transferencia realizada. O valor transferido da conta de "
                                                + contaOrigem.titular.nome + " para a conta de "
                                                + contaDestino.titular.nome + " e: R$ " + valorTransacao);
                                    } else {
                                        System.out.println(
                                                "Nao foi possivel realizar a transferencia. Verifique o saldo e tente novamente.");
                                    }
                                    break;
                                }
                            }
                        }
                    }
                    if (!contaEncontrada1) {
                        System.out.println("Conta de origem nao encontrada.");
                    } else if (!contaEncontrada2) {
                        System.out.println("Conta de destino nao encontrada.");
                    }
                    break;
                case 0:
                    System.out.println("Encerrando o programa...");
                    break;
                default:
                    System.out.println("Opcao invalida. Tente novamente.");
            }
        } while (op != 0);
        sc.close();
    }
}
