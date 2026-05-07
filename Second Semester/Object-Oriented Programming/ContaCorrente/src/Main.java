public class Main {
    public static void main(String[] args) {
        Cliente cliente1 = new Cliente("Lucas", "Rua A, 123");
        Cliente cliente2 = new Cliente("Maria", "Rua B, 456");
        System.out.println();
        ContaCorrente conta1 = new ContaCorrente(cliente1, true);
        ContaCorrente conta2 = new ContaCorrente(cliente2, false);

        System.out.println();

        conta1.exibirSaldo();
        conta2.exibirSaldo();

        System.out.println();

        conta1.depositar(500.0);
        conta1.exibirSaldo();

        System.out.println();

        conta1.sacar(200.0);
        conta1.exibirSaldo();

        System.out.println();

        conta2.depositar(200.0);
        conta2.exibirSaldo();

        System.out.println();

        conta2.sacar(300.0);
        conta2.exibirSaldo();

        System.out.println();

        conta1.transferir(300.0, conta2);
        conta1.exibirSaldo();
        conta2.exibirSaldo();

        System.out.println();

        conta1.transferir(1200.0, conta2);
        conta1.exibirSaldo();
        conta2.exibirSaldo();

        System.out.println();

        conta2.transferir(500.0, conta1);
        conta2.exibirSaldo();
        conta1.exibirSaldo();

        System.out.println();

        conta2.transferir(2500.0, conta1);
        conta2.exibirSaldo();
        conta1.exibirSaldo();

        System.out.println();

        conta1.exibirExtrato();

        System.out.println();

        conta2.exibirExtrato();
    }
}
