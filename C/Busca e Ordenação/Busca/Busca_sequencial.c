#include <stdio.h>
#define MAX 1000

/* Recebe um número inteiro n >= 0, um vetor v[0..n-1] com n números inteiros e um número inteiro x e devolve k no intervalo
[0, n-1] tal que v[k] == x. Se tal k não existe, devolve -1. */

int busca_sequencial(int n, int v[MAX], int x) {
    int k;
    for (k = n - 1; k >= 0 && v[k] != x; k--)
    ;
    return k;
}

int busca_sequencial_R(int n, int v[MAX], int x) {
    if (n == 0)
        return -1;
    else
        if (x == v[n - 1])
            return n - 1;
        else
            return busca_sequencial_R(n - 1, v, x);
}

