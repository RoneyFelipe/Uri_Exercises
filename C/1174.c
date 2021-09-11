#include <stdio.h>
#define MAX 100


int main(void) {
    float vetor[MAX], n;

    for(int cont = 0; cont < 100; cont ++) {
        scanf("%f", &n);
        vetor[cont] = n;
    }

    for(int cont = 0; cont < 100; cont ++) {
        if (vetor[cont] <= 10) {
            printf("A[%d] = %.1f\n", cont, vetor[cont]);
        }
    }

    return 0;

}



