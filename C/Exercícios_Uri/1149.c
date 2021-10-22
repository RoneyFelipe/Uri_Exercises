#include <stdio.h>



int main(void) {

    int A, soma = 0, N = 0;

    scanf("%d %d", &A, &N);

    for (int cont = 0; N <= 0; cont++) {
        scanf("%d", &N);
    }

    for (int cont = 0; cont <= N -1; cont ++) {
        soma = A + cont + soma;
    }

    printf("%d\n", soma);

}
