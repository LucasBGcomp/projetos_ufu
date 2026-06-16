package entidades;

public class Transacao {
    private String tipo;
    private double valor;
    private ContaCorrente contaOrigem;
    private ContaCorrente contaDestino;

    public Transacao(String tipo, double valor, ContaCorrente contaOrigem, ContaCorrente contaDestino) {
        this.tipo = tipo;
        this.valor = valor;
        this.contaOrigem = contaOrigem;
        this.contaDestino = contaDestino;
    }

    public String getTipo() {
        return tipo;
    }

    public double getValor() {
        return valor;
    }

    public ContaCorrente getContaOrigem() {
        return contaOrigem;
    }

    public ContaCorrente getContaDestino() {
        return contaDestino;
    }
}
