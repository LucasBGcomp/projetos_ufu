import java.util.Vector;
public class ContaCorrente {
    Cliente titular;
    double saldo;
    boolean isEspecial;
    Vector<Transacao> extrato;

    public ContaCorrente(Cliente titular, boolean isEspecial) {
        this.titular = titular;
        this.isEspecial = isEspecial;
        this.saldo = 1000.0; // Saldo inicial da conta
        this.extrato = new Vector<Transacao>();
        System.out.println("Conta aberta com sucesso para " + this.titular.nome + ". Saldo inicial: " + this.saldo);
    }

    void exibirSaldo() {
        System.out.println("O saldo da conta de " + this.titular.nome + " é: " + this.saldo);
    }

    void exibirExtrato() {
        System.out.println("Extrato da conta de " + this.titular.nome + ":");
        System.out.println();
        for (Transacao transacao : extrato) {
            if (transacao.tipo.equals("Saque")) {
                System.out.println("Saque:");
                System.out.println("  Valor: " + transacao.valor);
            } else if (transacao.tipo.equals("Depósito")) {
                System.out.println("Depósito:");
                System.out.println("  Valor: " + transacao.valor);
            } else if (transacao.tipo.equals("Transferência")) {
                System.out.println("Transferência:");
                System.out.println("  Valor: " + transacao.valor);
                System.out.println("  De: " + transacao.contaOrigem.titular.nome);
                System.out.println("  Para: " + transacao.contaDestino.titular.nome);
            }
        }
    }

    void sacar(double valor) {
        if (valor > this.saldo) {
            if (this.isEspecial) {
                System.out.println("Saque autorizado. O valor sacado da conta de " + this.titular.nome + " é: " + valor);
                this.saldo -= valor;
                Transacao transacao = new Transacao("Saque", valor, this, null);
                extrato.add(transacao);
            } else {
                System.out.println("Saldo insuficiente para realizar o saque.");
            }
        } else {
            System.out.println("Saque autorizado. O valor sacado da conta de " + this.titular.nome + " é: " + valor);
            this.saldo -= valor;
            Transacao transacao = new Transacao("Saque", valor, this, null);
            extrato.add(transacao);
        }
    }

    void depositar(double valor) {
        this.saldo += valor;
        System.out.println("Depósito realizado. O valor depositado na conta de " + this.titular.nome + " é: " + valor);
        Transacao transacao = new Transacao("Depósito", valor, null, this);
        extrato.add(transacao);
    }

    void transferir(double valor, ContaCorrente contaDestino) {
        if (valor > this.saldo) {
            if (this.isEspecial) {
                System.out.println("Transferência OK! O valor transferido da conta de " + this.titular.nome
                        + " para a conta de " + contaDestino.titular.nome + " é: " + valor);
                this.saldo -= valor;
                contaDestino.saldo += valor;
                Transacao transacao = new Transacao("Transferência", valor, this, contaDestino);
                extrato.add(transacao);
            } else {
                System.out.println(this.titular.nome + ", Saldo insuficiente para realizar a transferência.");
            }
        } else {
            System.out.println("Transferência OK! O valor transferido da conta de " + this.titular.nome + " para a conta de "
                    + contaDestino.titular.nome + " é: " + valor);
            this.saldo -= valor;
            contaDestino.saldo += valor;
            Transacao transacao = new Transacao("Transferência", valor, this, contaDestino);
            extrato.add(transacao);
        }
    }
}
