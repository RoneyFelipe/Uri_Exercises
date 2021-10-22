#include <stdio.h>
#define MAX 1001


int main(void) {
    int vetor[MAX], n, aux = 0;

    scanf("%d", &n);

    for(int cont = 0; cont < 1000; cont ++) {
        if( aux < n){
            vetor[cont] = aux;
            aux++;
        }
        else {
            aux = 0;
            vetor[cont] = aux;
            aux++;
        }
    }

    for(int cont = 0; cont < 1000; cont ++)
        printf("N[%d] = %d\n", cont, vetor[cont]);

    return 0;

}
