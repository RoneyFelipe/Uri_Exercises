#include <stdio.h>


typedef struct {
    int nota;
    int movimento;
} aluno;

void intercala_decrescente(int p, int q, int r, aluno *v)
{
    int i, j, k;
    aluno w[r+1];
    i = p;
    j = q;
    k = 0;
    while (i < q && j < r) {

        if (v[i].nota >= v[j].nota) {
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

void mergesort_decrescente(int p, int r, aluno *v) {
    int q;
    if (p < r - 1) {
        q = (p + r) / 2;
        mergesort_decrescente(p, q, v);
        mergesort_decrescente(q, r, v);
        intercala_decrescente(p, q, r, v);
    }
}

int main(void) {

    int n, numero_aluno, nota_aluno, *movimentos_fila;

    int p, r;

    scanf("%d", &n);

    for (int aux = 0; aux < n; aux ++) {

        scanf("%d", &numero_aluno);

        aluno alunos[numero_aluno];

        movimentos_fila = &numero_aluno;

        for(int cont = 0; cont < numero_aluno; cont ++) {
            scanf("%d", &nota_aluno);
            alunos[cont].nota = nota_aluno;
            alunos[cont].movimento = 0;
        }

        p = 0;

        r = numero_aluno;

        mergesort_decrescente(p, r, alunos);

        printf("%d\n", *movimentos_fila);

        for (int aux = 0; aux < numero_aluno; aux++) {
            printf("%d\n", alunos[aux].nota);
            alunos[aux].nota = '\0';
        }

    }



}
