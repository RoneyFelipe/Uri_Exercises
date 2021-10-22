#include <stdio.h>
#define MAX 100


int main(void) {
    int vetor[MAX];
    int n;

    for(int cont = 0; cont < 10; cont ++) {
        scanf("%d", &n);

        if (n<= 0) {
            vetor[cont] = 1;
        }
        else {
            vetor[cont] = n;
        }
    }
    for(int cont = 0; cont < 10; cont ++)
        printf("X[%d] = %d\n", cont, vetor[cont]);

    return 0;
}
