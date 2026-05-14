package entidades;

import java.util.Vector;

public class Banco {
    public String nome;
    public Vector<ContaCorrente> contas;

    public Banco(String nome) {
        this.nome = nome;
        this.contas = new Vector<ContaCorrente>();
    }

    public boolean abrirConta(Cliente titular, boolean isEspecial) {
        ContaCorrente conta = new ContaCorrente(titular, isEspecial);
        if (conta != null) {
            contas.add(conta);
            return true;
        } else {
            return false;
        }
    }
}