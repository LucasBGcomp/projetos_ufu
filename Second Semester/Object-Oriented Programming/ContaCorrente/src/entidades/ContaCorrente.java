package entidades;

import java.util.Vector;

public class ContaCorrente {
    public Cliente titular;
    public double saldo;
    public boolean isEspecial;
    public Vector<Transacao> extrato;

    public ContaCorrente(Cliente titular, boolean isEspecial) {
        this.titular = titular;
        this.isEspecial = isEspecial;
        this.saldo = 1000.0; // Saldo inicial da conta
        this.extrato = new Vector<Transacao>();
    }

    public void exibirSaldo() {
        System.out.println("R$ " + String.format("%.2f", this.saldo));
    }

    public void exibirExtrato() {
        for (Transacao transacao : extrato) {
            if (transacao.tipo.equals("Saque")) {
                System.out.println("Saque:");
                System.out.println("  Valor: " + transacao.valor);
                System.out.println();
            } else if (transacao.tipo.equals("Deposito")) {
                System.out.println("Deposito:");
                System.out.println("  Valor: " + transacao.valor);
                System.out.println();
            } else if (transacao.tipo.equals("Transferencia")) {
                System.out.println("Transferencia:");
                System.out.println("  Valor: " + transacao.valor);
                System.out.println("  De: " + transacao.contaOrigem.titular.nome);
                System.out.println("  Para: " + transacao.contaDestino.titular.nome);
                System.out.println();
            }
        }
    }

    public boolean sacar(double valor) {
        if (valor > this.saldo) {
            if (this.isEspecial) {
                this.saldo -= valor;
                Transacao transacao = new Transacao("Saque", valor, this, null);
                extrato.add(transacao);
                return true;
            } else {
                return false;
            }
        } else {
            this.saldo -= valor;
            Transacao transacao = new Transacao("Saque", valor, this, null);
            extrato.add(transacao);
            return true;
        }
    }

    public boolean depositar(double valor) {
        this.saldo += valor;
        Transacao transacao = new Transacao("Deposito", valor, null, this);
        extrato.add(transacao);
        return true;
    }

    public boolean transferir(double valor, ContaCorrente contaDestino) {
        if (valor > this.saldo) {
            if (this.isEspecial) {
                this.saldo -= valor;
                contaDestino.saldo += valor;
                Transacao transacao = new Transacao("Transferencia", valor, this, contaDestino);
                extrato.add(transacao);
                return true;
            } else {
                return false;
            }
        } else {
            this.saldo -= valor;
            contaDestino.saldo += valor;
            Transacao transacao = new Transacao("Transferencia", valor, this, contaDestino);
            extrato.add(transacao);
            return true;
        }
    }
}
