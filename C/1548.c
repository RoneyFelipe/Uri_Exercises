#include <stdio.h>

void intercala_decrescente(int p, int q, int r, int *v) {
    int i, j, k;
    int w[r];
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

void mergesort_decrescente(int p, int r, int *v) {
    int q;
    if (p < r - 1) {
        q = (p + r) / 2;
        mergesort_decrescente(p, q, v);
        mergesort_decrescente(q, r, v);
        intercala_decrescente(p, q, r, v);
    }
}

int main(void) {

    int n, numero_aluno, nota_aluno, movimentos_fila;

    int p, r;

    scanf("%d", &n);

    for (int aux = 0; aux < n; aux ++) {

        scanf("%d", &numero_aluno);

        int alunos_original[numero_aluno];
        int alunos_ordenado[numero_aluno];

        movimentos_fila =  numero_aluno;

        for(int cont = 0; cont < numero_aluno; cont ++) {
            scanf("%d", &nota_aluno);
            alunos_original[cont] = nota_aluno;
            alunos_ordenado[cont] = nota_aluno;
        }

        p = 0;

        r = numero_aluno;

        mergesort_decrescente(p, r, alunos_ordenado);

        for (int aux = 0; aux < numero_aluno; aux++) {
            if(alunos_ordenado[aux] != alunos_original[aux]) {
                movimentos_fila = movimentos_fila - 1;
            }
        }

        printf("%d\n", movimentos_fila);


    }

    return 0;


}
