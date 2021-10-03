#include <stdio.h>
#define MAX 1000

/* Recebe um número inteiro n >= 0 e um vetor v de números inteiros
com n elementos e rearranja o vetor v de modo que fique crescente */

/*Crescente:*/
void trocas_sucessivas_Crescente(int n, int v[MAX]) {
    int i, j;
    for (i = n - 1; i > 0; i--)
        for (j = 0; j < i; j++)
            if (v[j] > v[j+1])
            troca(&v[j], &v[j+1]);
}

/*Decrescente:*/
void trocas_sucessivas_decrescente(int n, int v[MAX]) {
    int i, j;
    for (i = n - 1; i > 0; i--)
        for (j = 0; j < i; j++)
            if (v[j] > v[j+1])
            troca(&v[j], &v[j+1]);
}

