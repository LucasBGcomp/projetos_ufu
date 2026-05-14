package teste;

import entidades.*;

public class TestesManuais {
    public void executarTestes() {
        System.out.println("Iniciando testes manuais do sistema de conta corrente...");

        // Teste de abertura de conta
        Banco banco = new Banco("Banco do Brasil");
        Cliente cliente1 = new Cliente("Joao Silva", "Rua A, 123");
        Cliente cliente2 = new Cliente("Maria Oliveira", "Rua B, 456");
        banco.abrirConta(cliente1, true);
        banco.abrirConta(cliente2, false);

        // Teste de deposito
        ContaCorrente conta1 = banco.contas.get(0);
        conta1.depositar(500);
        conta1.exibirSaldo();
        ContaCorrente conta2 = banco.contas.get(1);
        conta2.depositar(300);
        conta2.exibirSaldo();

        // Teste de saque
        conta1.sacar(500);
        conta1.exibirSaldo();
        conta2.sacar(300);
        conta2.exibirSaldo();

        // Teste de saque com saldo insuficiente
        if (conta1.sacar(1500)) {
            System.out.println("Saque realizado com sucesso.");
        } else {
            System.out.println("Nao foi possivel realizar o saque. Saldo insuficiente.");
        }
        conta1.exibirSaldo();
        if (conta2.sacar(1500)) {
            System.out.println("Saque realizado com sucesso.");
        } else {
            System.out.println("Nao foi possivel realizar o saque. Saldo insuficiente.");
        }
        conta2.exibirSaldo();

        // Teste de transferencia
        conta2.transferir(600, conta1);
        conta1.exibirSaldo();
        conta2.exibirSaldo();

        System.out.println("Testes manuais concluidos.");
    }

    public static void main(String[] args) {
        new TestesManuais().executarTestes();
    }
}
