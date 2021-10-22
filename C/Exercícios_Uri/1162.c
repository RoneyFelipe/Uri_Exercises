#include <stdio.h>

void troca(int *a, int *b, int *contagem) {

    int aux = *a;
    *a = *b;
    *b = aux;
    *contagem = *contagem + 1;
}

void trocas_sucessivas_Crescente(int n, int *v, int *contagem) {
    int i, j;
    for (i = n - 1; i > 0; i--)
        for (j = 0; j < i; j++)
            if (v[j] > v[j+1])
            troca(&v[j], &v[j+1], contagem);
}

int main(void) {

    int n, tamanho;

    scanf("%d", &n);

    for(int cont = 0; cont < n; cont++) {

        scanf("%d", &tamanho);

        int vagao, trocas = 0, *contagem;

        contagem = &trocas;


        int trens_ordenado[tamanho];

        for(int aux = 0; aux < tamanho; aux++) {
            scanf("%d", &vagao);

            trens_ordenado[aux] = vagao;
        }

        trocas_sucessivas_Crescente(tamanho, trens_ordenado, contagem);

        printf("Optimal train swapping takes %d swaps.\n", *contagem);


    }

}
