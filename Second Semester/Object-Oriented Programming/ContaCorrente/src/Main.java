public class Main {
    public static void main(String[] args) {
        ContaCorrente c1 = new ContaCorrente("Lucas", true);
        ContaCorrente c2 = new ContaCorrente("Leonardo", false);
        System.out.println();

        c1.exibirSaldo();
        c2.exibirSaldo();
        System.out.println();

        c1.sacar(100.0f);
        c1.exibirSaldo();
        System.out.println();

        c2.sacar(250.0f);
        c2.exibirSaldo();
        System.out.println();

        c1.depositar(200.0f);
        c1.exibirSaldo();
        System.out.println();

        c2.depositar(150.0f);
        c2.exibirSaldo();
        System.out.println();

        c1.transferir(1200.0f, c2);
        c1.exibirSaldo();
        c2.exibirSaldo();
        System.out.println();

        c2.transferir(100.0f, c1);
        c1.exibirSaldo();
        c2.exibirSaldo();
        System.out.println();

        c2.transferir(2100.0f, c2);
        c1.exibirSaldo();
        c2.exibirSaldo();
    }
}
