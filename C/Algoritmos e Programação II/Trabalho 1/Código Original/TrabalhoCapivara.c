#include <stdio.h>
#define MAX 1000

/**************************************************
*
* Nome do(a) estudante: Roney Felipe de Oliveira Miranda
* Trabalho 1
* Professor(a): Diego Rubert
*
*/

/* Armazena informações de uma capivara */
typedef struct {
    int numero; /* Número da capivara = posição na largada */
    int ultrapass; /* Quantidade de ultrapassagens feitas */
} capivara;

void troca(capivara *a, capivara *b){
    capivara temp = *a;
    *a = *b;
    *b = temp;
}

void intercala(int p, int q, int r, capivara v[MAX]) {

    int i, j, k;
    capivara w[MAX];
    i = p;
    j = q;
    k = 0;
    while (i < q && j < r) {

        if (v[i].ultrapass > v[j].ultrapass) {
            w[k] = v[i];
            i++;
        }

        else if (v[i].ultrapass == v[j].ultrapass) {
            if(v[i].numero > v[j].numero) {
                w[k] = v[j];
                j++;
            }
            else {
                w[k] = v[i];
                i++;
            }
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

void mergesort(int p, int r, capivara v[MAX]) {

    int q;
    if (p < r - 1) {
        q = (p + r) / 2;
        mergesort(p, q, v);
        mergesort(q, r, v);
        intercala(p, q, r, v);
    }
}

int main(void) {

    int n, ultrapassagem;

    int p, r;

    scanf("%d", &n);

    capivara capivaras[n];

    for(int cont = 0; cont < n; cont++) {
        capivaras[cont].numero = cont + 1;
        capivaras[cont].ultrapass = 0;
    }
    /*for(int cont = 0; cont < n; cont++) {
        printf("%d\n", capivaras[cont].numero);
    }*/

    while(scanf("%d", &ultrapassagem) != EOF) {

        for(int cont = 0; cont < n; cont++) {
            if(capivaras[cont].numero == ultrapassagem) {
                capivaras[cont].ultrapass++;
                troca(&capivaras[cont], &capivaras[cont - 1]);
            }
        }
        /*for(int cont = 0; cont < n; cont++) {
            printf("%d\n", capivaras[cont].numero);
        }*/

    }

    p = 0;
    r = n - 1;

    for(int cont = 0; cont < n; cont++) {
        if (cont + 1 < n) {
            printf("%d ", capivaras[cont].numero);
        }
        else {
            printf("%d", capivaras[cont].numero);
        }

    }
    printf("\n");

    mergesort(p, r, capivaras);

    for(int cont = 0; cont < n; cont++) {
        if (cont + 1 < n) {
            printf("%d ", capivaras[cont].numero);
        }
        else {
            printf("%d", capivaras[cont].numero);
        }

    }

}


