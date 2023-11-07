#include <stdio.h>
#include <time.h>
#include <pthread.h>
#define N 50000000
#define NUM_THREADS 4

typedef struct{
	int inicio;
	int fim;
	int cont;
}ThreadArgs;

void *conta_primos(void *args);

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
	pthread_t threads[NUM_THREADS];
	ThreadArgs thread_args[NUM_THREADS];
	int total_primos = 0;
	int tam_segmento = N / NUM_THREADS;
	int i;
    clock_t tempo_inicial, tempo_final;
    double tempo_usado;

    tempo_inicial = clock();

    for(i = 0 ; i < NUM_THREADS; i++){
    	thread_args[i].inicio = i * tam_segmento + 1;
    	thread_args[i].fim = (i == NUM_THREADS - 1) ? N : (i + 1) * tam_segmento;
    	pthread_create(&threads[i], NULL, conta_primos, &thread_args[i]);
	}
	
	for(i = 0 ; i < NUM_THREADS; i++){
		pthread_join(threads[i],NULL);
    	total_primos += thread_args[i].cont;
	}

    tempo_final = clock();
    tempo_usado = ((double)(tempo_final - tempo_inicial)) / CLOCKS_PER_SEC;

    printf("Numero total de numeros primos de 1 a %d: %d\n", N, total_primos);
    printf("Tempo de execucao: %f segundos\n", tempo_usado);

    return 0;
}

void *conta_primos(void *args){
	
	ThreadArgs *thread_args = (ThreadArgs *)args;
	int inicio = thread_args->inicio;
	int fim = thread_args->fim;
	int cont = 0;
	int i;
	for( i = inicio; i <= fim;i++){
		if(verificaPrimo(i)){
			cont++;
		}
	}	
	thread_args->cont = cont;
	pthread_exit(NULL);
	
}

