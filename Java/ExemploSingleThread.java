import java.util.ArrayList;
import java.util.Collection;

public class ExemploSingleThread {

    public static void main(String[] args) {
        System.out.println("Inicio de processamento...");
        // armazena o tempo inicial
        long ti = System.currentTimeMillis();

        int valorInicial = 1;
        int valorFinal = 1000000;

        // lista para armazenar os numeros primos encontrados pelas threads
        Collection<Long> primos = new ArrayList<>();

        // percorre o intervalo buscano os numeros primos
        for (long ate = valorInicial; ate <= valorFinal; ate++) {
            int primo = 0;
            for (int i = 2; i < ate; i++) {
                if ((ate % i) == 0) {
                    primo++;
                    break;
                }
            }
            if (primo == 0) {
                synchronized (primos) {
                    primos.add(ate);
                }
            }
        }

        // imprime os numeros primos encontrados por todas as threads
        /*
         * for (Long primo : primos) {
         * System.out.println(primo);
         * }
         */

        System.out.println("Quantidade de numeros primos: " + (primos.size()));

        // calcula e imprime o tempo total gasto
        System.out.println("Tempo de procesamento: " + (System.currentTimeMillis() - ti));

        System.out.println("Fim de processamento.");
    }
}
