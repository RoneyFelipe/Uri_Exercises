#include <stdio.h>

int main(void) {

    int n;

    printf("Digite o valor de n: ");

    scanf("%d", &n);

    int matriz_I[n][n];

    int *p;

    int *q;

    q = &matriz_I[0][0];

    for (p = &matriz_I[0][0]; p <= &matriz_I[n-1][n-1]; p++) {

        if (p == q) {
            *p = 1;
            q += n + 1;
        }
        else {
            *p = 0;
        }

    }

    printf("Segue a Matriz abaixo: \n\n");

    q = &matriz_I[0][n];

    for(p = &matriz_I[0][0]; p <= &matriz_I[n-1][n-1]; p++) {

        if (p < q) {
            printf("%d ", *p);

        }
        else {
            printf("\n");
            printf("%d ", *p);
            q += n;
        }

    }

    printf("\n");

    return 0;

}
