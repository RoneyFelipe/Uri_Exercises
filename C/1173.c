#include <stdio.h>
#define MAX 100


int main(void) {
    int vetor[MAX];
    int n;
    scanf("%d", &n);
    vetor[0] = n;
    for(int cont = 1; cont < 10; cont ++)
        vetor[cont] = vetor[cont - 1] * 2;

     for(int cont = 0; cont < 10; cont ++)
        printf("N[%d] = %d\n", cont, vetor[cont]);

    return 0;

}

