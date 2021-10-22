#include <stdio.h>
#define MAX 101


int main(void) {

    double vetor[MAX], n;

    scanf("%lf", &n);

    vetor[0] = n;

    for(int cont = 1; cont < 100; cont++) {
        vetor[cont] = vetor[cont-1]/2.0;
    }
    for(int cont = 0; cont < 100; cont ++)
        printf("N[%d] = %.4f\n", cont, vetor[cont]);

    return 0;


}



