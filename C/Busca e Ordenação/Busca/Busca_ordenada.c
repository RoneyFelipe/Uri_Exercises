#include <stdio.h>
#define MAX 1000

/* Recebe um n�mero inteiro n > 0, um vetor de n�meros inteiros crescente v[0..n-1] e um n�mero inteiro x e devolve um �ndice k em [0, n] tal que v[k-1] < x <= v[k] */
int busca_ordenada(int n, int v[MAX], int x) {
    int k;

    for (k = 0; k < n && v[k] < x; k++);

    return k;
}

