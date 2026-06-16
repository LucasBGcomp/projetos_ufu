package entidades;

import java.util.Vector;

public class ContaCorrente {
    private Cliente titular;
    private double saldo;
    private boolean isEspecial;
    private Vector<Transacao> extrato;

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
            if (transacao.getTipo().equals("Saque")) {
                System.out.println("Saque:");
                System.out.println("  Valor: " + transacao.getValor());
                System.out.println();
            } else if (transacao.getTipo().equals("Deposito")) {
                System.out.println("Deposito:");
                System.out.println("  Valor: " + transacao.getValor());
                System.out.println();
            } else if (transacao.getTipo().equals("Transferencia")) {
                System.out.println("Transferencia:");
                System.out.println("  Valor: " + transacao.getValor());
                System.out.println("  De: " + transacao.getContaOrigem().titular.getNome());
                System.out.println("  Para: " + transacao.getContaDestino().titular.getNome());
                System.out.println();
            }
        }
    }

    public boolean sacar(double valor) {
        if (valor > this.saldo) {
            if (this.isEspecial) {
                this.saldo -= valor;
                Transacao transacao = new Transacao("Saque", valor, this, null);
                if (transacao == null) return false;
                extrato.add(transacao);
                return true;
            } else {
                return false;
            }
        } else {
            this.saldo -= valor;
            Transacao transacao = new Transacao("Saque", valor, this, null);
            if (transacao == null) return false;
            extrato.add(transacao);
            return true;
        }
    }

    public boolean depositar(double valor) {
        this.saldo += valor;
        Transacao transacao = new Transacao("Deposito", valor, null, this);
        if (transacao == null) return false;
        extrato.add(transacao);
        return true;
    }

    public boolean transferir(double valor, ContaCorrente contaDestino) {
        if (valor > this.saldo) {
            if (this.isEspecial) {
                this.saldo -= valor;
                contaDestino.saldo += valor;
                Transacao transacao = new Transacao("Transferencia", valor, this, contaDestino);
                if (transacao == null) return false;
                extrato.add(transacao);
                return true;
            } else {
                return false;
            }
        } else {
            this.saldo -= valor;
            contaDestino.saldo += valor;
            Transacao transacao = new Transacao("Transferencia", valor, this, contaDestino);
            if (transacao == null) return false;
            extrato.add(transacao);
            return true;
        }
    }

    public Cliente getTitular() {
        return titular;
    }

    public double getSaldo() {
        return saldo;
    }

    public boolean getTipo() {
        return isEspecial;
    }
}
