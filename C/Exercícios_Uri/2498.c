#include <stdio.h>


typedef struct {
    float peso;
    float interesse;
    float coeficinete;
} livro;

void intercala_decrescente(int p, int q, int r, livro *v) {

    int i, j, k;
    livro w[r];
    i = p;
    j = q;
    k = 0;
    while (i < q && j < r) {

        if (v[i].coeficinete >= v[j].coeficinete) {
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

void mergesort_decrescente(int p, int r, livro *v) {

    int q;
    if (p < r - 1) {
        q = (p + r) / 2;
        mergesort_decrescente(p, q, v);
        mergesort_decrescente(q, r, v);
        intercala_decrescente(p, q, r, v);
    }
}

int main(void) {

    int quantidade_livros = 1, capacidade_bolsa = 1, aux = 1;

    while((quantidade_livros != 0) && (capacidade_bolsa != 0)) {

        int interesse = 0, peso = 0;

        scanf("%d %d", &quantidade_livros, &capacidade_bolsa);

        livro livros[quantidade_livros];

        for(int cont = 0; cont < quantidade_livros; cont++) {
            scanf("%f %f", &livros[cont].peso, &livros[cont].interesse);
            livros[cont].coeficinete = livros[cont].interesse/ livros[cont].peso;
        }

        for(int cont = 0; cont < quantidade_livros; cont++) {
            printf("%f ", livros[cont].coeficinete);
            }
        printf("\n");
        for(int cont = 0; cont < quantidade_livros; cont++) {
            printf("%f ", livros[cont].interesse);
            }
             printf("\n");
        mergesort_decrescente(0, quantidade_livros, livros);

        for(int cont = 0; cont < quantidade_livros; cont++) {
            printf("%f ", livros[cont].coeficinete);
            }

        for(int cont = 0; cont < quantidade_livros; cont++) {
            if ( peso + livros[cont].peso <= capacidade_bolsa) {
                interesse = interesse + livros[cont].interesse;
                printf("%f ", livros[cont].interesse);
                printf("%f ", livros[cont].coeficinete);
                peso = peso + livros[cont].peso;
            }
        }
        printf("Caso %d: %d\n", aux, interesse);
        aux++;
    }

}
