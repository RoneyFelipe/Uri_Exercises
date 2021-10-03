#include <stdio.h>
#define MAX 1000

/*Crescente*/
void intercala_crescente(int p, int q, int r, int v[MAX])
{
    int i, j, k, w[MAX];
    i = p;
    j = q;
    k = 0;
    while (i < q && j < r) {

        if (v[i] <= v[j]) {
            w[k] = v[i];
            i++;
        }

        else {
            w[k] = v[j];
            j++;
        }
        k++;
    }

    while (i < q) {
        w[k] = v[i];
        i++;
        k++;
    }
    while (j < r) {
        w[k] = v[j];
        j++;
        k++;
    }
    for (i = p; i < r; i++)
        v[i] = w[i-p];

}

void mergesort_crescente(int p, int r, int v[MAX])
{
    int q;
    if (p < r - 1) {
        q = (p + r) / 2;
        mergesort_crescente(p, q, v);
        mergesort_crescente(q, r, v);
        intercala_crescente(p, q, r, v);
    }
}

/*Decrescente*/
void intercala_decrescente(int p, int q, int r, int v[MAX])
{
    int i, j, k, w[MAX];
    i = p;
    j = q;
    k = 0;
    while (i < q && j < r) {

        if (v[i] >= v[j]) {
            w[k] = v[i];
            i++;
        }

        else {
            w[k] = v[j];
            j++;
        }
        k++;
    }

    while (i < q) {
        w[k] = v[i];
        i++;
        k++;
    }
    while (j < r) {
        w[k] = v[j];
        j++;
        k++;
    }
    for (i = p; i < r; i++)
        v[i] = w[i-p];

}

void mergesort_decrescente(int p, int r, int v[MAX])
{
    int q;
    if (p < r - 1) {
        q = (p + r) / 2;
        mergesort_decrescente(p, q, v);
        mergesort_decrescente(q, r, v);
        intercala_decrescente(p, q, r, v);
    }
}
