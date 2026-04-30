public class ContaCorrente {
    String titular;
    float saldo;
    boolean isEspecial;

    public ContaCorrente(String titular, boolean isEspecial) {
        this.titular = titular;
        this.isEspecial = isEspecial;
        this.saldo = 1000.0f; // Saldo inicial da conta
        System.out.println("Conta aberta com sucesso para " + this.titular + ". Saldo inicial: " + this.saldo);
    }

    void exibirSaldo() {
        System.out.println("O saldo da conta de " + this.titular + " é: " + this.saldo);
    }

    void sacar(float valor) {
        if (valor > this.saldo) {
            if (this.isEspecial) {
                System.out.println("Saque autorizado. O valor sacado da conta de " + this.titular + " é: " + valor);
                this.saldo -= valor;
            } else {
                System.out.println("Saldo insuficiente para realizar o saque.");
            }
        } else {
            System.out.println("Saque autorizado. O valor sacado da conta de " + this.titular + " é: " + valor);
            this.saldo -= valor;
        }
    }

    void depositar(float valor) {
        this.saldo += valor;
        System.out.println("Depósito realizado. O valor depositado na conta de " + this.titular + " é: " + valor);
    }

    void transferir(float valor, ContaCorrente contaDestino) {
        if (valor > this.saldo) {
            if (this.isEspecial) {
                System.out.println("Transferência OK! O valor transferido da conta de " + this.titular
                        + " para a conta de " + contaDestino.titular + " é: " + valor);
                this.saldo -= valor;
                contaDestino.depositar(valor);
            } else {
                System.out.println(this.titular + ", Saldo insuficiente para realizar a transferência.");
            }
        } else {
            System.out.println("Transferência OK! O valor transferido da conta de " + this.titular + " para a conta de "
                    + contaDestino.titular + " é: " + valor);
            this.saldo -= valor;
            contaDestino.depositar(valor);
        }
    }
}
