#include <stdio.h>
#define MAX 1000


int main(void) {
    long long vetor[MAX], n, aux,  anterior = 0, proximo = 1;
    vetor[0] = 0;
    vetor[1] = 1;

    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {

        scanf("%lld", &aux);

        for(int cont = 2; cont <= aux; cont++) {

            vetor[cont] = anterior + proximo;
            anterior = proximo;
            proximo = vetor[cont];
        }

        printf("Fib(%lld) = %lld\n", aux, vetor[aux]);
        anterior = 0;
        proximo = 1;
        int vetor[MAX];
        vetor[0] = 0;
        vetor[1] = 1;
    }
    return 0;
}
