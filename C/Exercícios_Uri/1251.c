#include <stdio.h>
#define MAX 10000

typedef struct {
        int freq;
        int asc;
        char carac[2];

    } caracter;

void intercala(int p, int q, int r, caracter v[MAX]) {

    int i, j, k;
    caracter w[MAX];
    i = p;
    j = q;
    k = 0;

    /*Laço responsável por copiar as posições de v para w, realizando as comparações da parte que inicia com p (usando i como índice)*/
    /*e da parte que inicia com q (usando j como índice). Dessa forma, o maior valor é copiado para posição em w (usando k como índice)*/

    while (i < q && j < r) {
        if (v[i].freq < v[j].freq) {
            w[k] = v[i];
            i++;
        }

        else if (v[i].freq == v[j].freq) {

            if (v[i].asc > v[j].asc) {
                w[k] = v[i];
                i++;
            }

            else {
                w[k] = v[j];
                j++;
            }
        }

        else {
            w[k] = v[j];
            j++;
        }
        k++;
    }

    /*Caso o número de posições em p (primeiro conjunto) seja maior que em q (segundo conjunto), este laço copiara as posições restantes de p para w.*/
    while (i < q) {
        w[k] = v[i];
        i++;
        k++;
    }

    /*Caso o número de posições em q (segundo conjunto) seja maior que em p (primeiro conjunto), este laço copiara as posições restantes de q para w.*/
    while (j < r) {
        w[k] = v[j];
        j++;
        k++;
    }

    /*Transfere os valores de w, que foram ordenados, para v*/
    for (i = p; i < r; i++)
        v[i] = w[i-p];

}


void mergesort(int p, int r, caracter v[MAX]) {

    int q;

    if (p < r - 1) {
        q = (p + r) / 2;
        mergesort(p, q, v);
        mergesort(q, r, v);
        intercala(p, q, r, v);
    }
}



int main(void) {

    char valor[MAX];
    caracter caracteris[MAX];

    for(int cont = 0; scanf(" %s", &valor) != EOF; cont++) {

        if(cont != 0){
            printf("\n");
        }

        int aux, aux2, tamanho_vetor, cont_m = 0;
        int p, r;
        int existia = 1;


        for(tamanho_vetor = 0; valor[tamanho_vetor] != '\0'; tamanho_vetor ++); /*Medindo o Tamanho do vetor*/

        for (aux = 0; aux < tamanho_vetor; aux ++) {

            for (aux2 = 0; aux2 < aux; aux2 ++) {

                if (valor[aux] == caracteris[aux2].carac[0]) {
                    existia = 0;
                    caracteris[aux2].freq ++;
                }
            }

            if (existia) {
                caracteris[cont_m].carac[0] = valor[aux];
                caracteris[cont_m].asc = valor[aux];
                caracteris[cont_m].freq = 1;

                cont_m++;
            }
            else {
                caracteris[cont_m].asc = -1;
            }
            existia = 1;
        }

        p = 0;
        r = cont_m;

        mergesort(p, r, caracteris);

        for (int aux = 0; aux < cont_m; aux++) {
                printf("%d %d\n", caracteris[aux].asc, caracteris[aux].freq);
                caracteris[aux].carac[0] = '\0';
                caracteris[aux].asc = '\0';
                caracteris[aux].freq = '\0';

        }

        char valor[MAX];
    }


    return 0;

}

