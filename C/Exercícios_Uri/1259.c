#include <stdio.h>
#define MAX 100000

void intercala(int p, int q, int r, int v[MAX], int regula) {

    int i, j, k, w[MAX];
    i = p;
    j = q;
    k = 0;

    /*La�o respons�vel por copiar as posi��es de v para w, realizando as compara��es da parte que inicia com p (usando i como �ndice)*/
    /*e da parte que inicia com q (usando j como �ndice). Dessa forma, o maior valor � copiado para posi��o em w (usando k como �ndice)*/

    if (regula) {
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
    }
    else {
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
    }


    /*Caso o n�mero de posi��es em p (primeiro conjunto) seja maior que em q (segundo conjunto), este la�o copiara as posi��es restantes de p para w.*/
    while (i < q) {
        w[k] = v[i];
        i++;
        k++;
    }

    /*Caso o n�mero de posi��es em q (segundo conjunto) seja maior que em p (primeiro conjunto), este la�o copiara as posi��es restantes de q para w.*/
    while (j < r) {
        w[k] = v[j];
        j++;
        k++;
    }

    /*Transfere os valores de w, que foram ordenados, para v*/
    for (i = p; i < r; i++)
        v[i] = w[i-p];

}



void mergesort(int p, int r, int v[MAX],int regula) {

    int q;

    if (p < r - 1) {
        q = (p + r) / 2;
        mergesort(p, q, v, regula);
        mergesort(q, r, v, regula);
        intercala(p, q, r, v, regula);
    }
}


int main(void) {
    int n, valor;
    int v_pares[MAX], v_impares[MAX];
    int cont_p = 0, cont_i = 0;
    int p, r, regula;

    scanf("%d", &n);

    for(int cont = 0; cont < n; cont ++) {

        scanf("%d", &valor);

        if (valor % 2 == 0) {
            v_pares[cont_p] = valor;
            cont_p++;
        }
        else {
            v_impares[cont_i] = valor;
            cont_i++;
        }
    }

    p = 0;
    r = cont_p;

    mergesort(p, r, v_pares, regula = 0);

    r = cont_i;

    mergesort(p, r, v_impares, regula = 1);

    for(int cont = 0; cont < cont_p; cont++)
        printf("%d\n", v_pares[cont]);

    for(int cont = 0; cont < cont_i; cont++)
        printf("%d\n", v_impares[cont]);

    return 0;

}
