public class Transacao {
    String tipo;
    double valor;
    ContaCorrente contaOrigem;
    ContaCorrente contaDestino;

    public Transacao(String tipo, double valor, ContaCorrente contaOrigem, ContaCorrente contaDestino) {
        this.tipo = tipo;
        this.valor = valor;
        this.contaOrigem = contaOrigem;
        this.contaDestino = contaDestino;
    }
}
