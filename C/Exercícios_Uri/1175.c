#include <stdio.h>
#define MAX 21


int main(void) {
    int vetor[MAX], n, aux = 19, aux_2;

    for(int cont = 0; cont < 20; cont++) {
        scanf("%d", &n);
        vetor[cont] = n;
    }

    for (int cont = 0; cont < 10; cont++) {
        aux_2 = vetor[cont];
        vetor[cont] = vetor[aux];
        vetor[aux] = aux_2;
        aux--;
    }
    for(int cont = 0; cont < 20; cont ++)
        printf("N[%d] = %d\n", cont, vetor[cont]);

    return 0;


}

