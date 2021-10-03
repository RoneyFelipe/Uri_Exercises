#include <stdio.h>
#define MAX 1000

void troca(int *a, int *b) {

    int aux = *a;
    *a = *b;
    *b = aux;

}

/*Chamada na main: quicksort(0, tamanho do vetor - 1, vetor)*/
/*Crescente*/
int separa_crescente(int p, int r, int v[MAX]) {
    int x, i, j;
    x = v[p];
    i = p - 1;
    j = r + 1;

    while (1) {
        do {
            j--;
        } while (v[j] > x);

        do {
            i++;
        } while (v[i] < x);

        if (i < j)
            troca(&v[i], &v[j]);
        else
            return j;
    }
}

/* Recebe um vetor v[p..r] e o rearranja em ordem crescente */
void quicksort_crescente(int p, int r, int v[MAX]) {
    int q;
    if (p < r) {
        q = separa_crescente(p, r, v);
        quicksort_crescente(p, q, v);
        quicksort_crescente(q+1, r, v);
    }
}


/*Decrescente*/
int separa_decrescente(int p, int r, int v[MAX]) {
    int x, i, j;
    x = v[p];
    i = p - 1;
    j = r + 1;

    while (1) {
        do {
            j--;
        } while (v[j] < x);

        do {
            i++;
        } while (v[i] > x);

        if (i < j)
            troca(&v[i], &v[j]);
        else
            return j;
    }
}

/* Recebe um vetor v[p..r] e o rearranja em ordem crescente */
void quicksort_decrescente(int p, int r, int v[MAX]) {
    int q;
    if (p < r) {
        q = separa_decrescente(p, r, v);
        quicksort_decrescente(p, q, v);
        quicksort_decrescente(q+1, r, v);
    }
}


