#include <stdio.h>
#define MAX 1000


void intercala(int p, int q, int r, int v[MAX]) {

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

void mergesort(int p, int r, int v[MAX]) {

    int q;

    if (p < r - 1) {
        q = (p + r) / 2;
        mergesort(p, q, v);
        mergesort(q, r, v);
        intercala(p, q, r, v);
    }
}
int main() {

    int n, p, r;
    int cont = 0;

    while(scanf("%d", &n) != EOF) {
        int v[MAX];
        for (cont = 0; cont < n; cont ++) {
            scanf("%d", &v[cont]);
        }
        p = 0;
        r = cont;

        mergesort(p, r, v);

        for (int aux = 0; aux < n; aux++) {
            if (v[aux]/10 == 0) {
                printf("000%d\n", v[aux]);
            }
            else if (v[aux]/100 == 0) {
                printf("00%d\n", v[aux]);
            }
            else if (v[aux]/1000 == 0) {
                printf("0%d\n", v[aux]);
            }
            else {
                printf("%d\n", v[aux]);
            }
        }
    }

    return 0;
}
