#include <stdio.h>
#define MAX 1000
/* Recebe um número inteiro n >= 0 e um vetor v de números inteiros
com n elementos e rearranja o vetor v de modo que fique crescente */

/*Crescente*/
void selection_sort_crescente(int n, int v[MAX]) {
    int i, j, min;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i+1; j < n; j++)
            if (v[j] < v[min])
                min = j;
        troca(&v[i], &v[min]);
    }
}

/*Decrescente*/
void selection_sort_decrescente(int n, int v[MAX]) {
    int i, j, min;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i+1; j < n; j++)
            if (v[j] > v[min])
                min = j;
        troca(&v[i], &v[min]);
    }
}
