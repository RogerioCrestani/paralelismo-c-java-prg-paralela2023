#include <stdio.h>
#include <time.h>
//50000000
#define N 50000000

int verificaPrimo(int num) {
	int i;
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;
    for (i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }
    return 1;
}

int main() {
	int i;
    clock_t tempo_inicial, tempo_final;
    double tempo_usado;

    tempo_inicial = clock();

    int cont = 0;
    for (i = 1; i <= N; i++) {
        if (verificaPrimo(i)) {
            cont++;
        }
    }

    tempo_final = clock();
    tempo_usado = ((double)(tempo_final - tempo_inicial)) / CLOCKS_PER_SEC;

    printf("Numero total de numeros primos de 1 a %d: %d\n", N, cont);
    printf("Tempo de execucao: %f segundos\n", tempo_usado);

    return 0;
}

