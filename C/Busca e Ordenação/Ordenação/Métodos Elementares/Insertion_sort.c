#include <stdio.h>
#define MAX 1000

/* Recebe um número inteiro n >= 0 e um vetor v de números inteiros
com n elementos e rearranja o vetor v de modo que fique crescente */

/*Crescente*/
void insertion_crescente(int n, int v[MAX]) {
    int i, j, x;
        for (i = 1; i < n; i++) {
            x = v[i];
            for (j = i - 1; j >= 0 && v[j] > x; j--)
                v[j+1] = v[j];
            v[j+1] = x;
    }
}

/*Decrescente*/
void insertion_decrescente(int n, int v[MAX]) {
    int i, j, x;
        for (i = 1; i < n; i++) {
            x = v[i];
            for (j = i - 1; j >= 0 && v[j] < x; j--)
                v[j+1] = v[j];
            v[j+1] = x;
    }
}

