#include <stdio.h>

void intercala_crescente(int p, int q, int r, int *v, int *vezes) {

    int i, j, k, w[r];
    i = p;
    j = q;
    k = 0;
    while (i < q && j < r) {

        if (v[i] <= v[j]) {
            w[k] = v[i];
            i++;
        }

        else {
            *vezes = q - (*vezes + i);
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

void mergesort_crescente(int p, int r, int *v, int *vezes) {

    int q;
    if (p < r - 1) {
        q = (p + r) / 2;
        mergesort_crescente(p, q, v, vezes);
        mergesort_crescente(q, r, v, vezes);
        intercala_crescente(p, q, r, v, vezes);
    }
}

int main(void) {

    int n, vezes;

    scanf("%d", &n);

    while(n != 0) {

        int sequencia[n];

        vezes = 0;

        for(int cont = 0; cont < n; cont++) {
            scanf("%d", &sequencia[cont]);

        }

        mergesort_crescente(0, n, sequencia, &vezes);

        if(vezes % 2 != 0) {
            printf("Marcelo\n", vezes);
        }
        else {
            printf("Carlos\n", vezes);
        }

        scanf("%d", &n);

    }

    return 0;


}
