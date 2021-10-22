#include <stdio.h>
#define MAX 1000


typedef struct {
        int tamanho;
        char string[51];

} palavra;

void intercala(int p, int q, int r, palavra v[MAX]) {

    int i, j, k;
    palavra w[MAX];
    i = p;
    j = q;
    k = 0;

    /*La�o respons�vel por copiar as posi��es de v para w, realizando as compara��es da parte que inicia com p (usando i como �ndice)*/
    /*e da parte que inicia com q (usando j como �ndice). Dessa forma, o maior valor � copiado para posi��o em w (usando k como �ndice)*/

    while (i < q && j < r) {

        if (v[i].tamanho >= v[j].tamanho) {
            w[k] = v[i];
            i++;
        }
        else {
            w[k] = v[j];
            j++;
        }
        k++;
    }

    /*Caso o n�mero de posi��es em p (primeiro conjunto) seja maior que em q (segundo conjunto), este la�o copiara as posi��es restantes de p para w.*/
    while (i < q) {
        w[k]= v[i];
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

void mergesort(int p, int r, palavra v[MAX]) {

    int q;

    if (p < r - 1) {
        q = (p + r) / 2;
        mergesort(p, q, v);
        mergesort(q, r, v);
        intercala(p, q, r, v);
    }
}



int main(void) {

    int n;
    int p, r, c;

    scanf("%d", &n);

    for(int cont = 0; cont < n; cont++) {

        int cont_palavras = 0, cont_caracteris = 0;

        palavra palavras[MAX];

        char valor[MAX];

        scanf(" %[^\n]%*c", valor);

        palavras[cont_palavras].tamanho = 0;

        /*Este la�o roda at� o final da string recebida, ou seja, todas as palavras juntas*/

        for(int aux = 0; valor[aux] != '\0'; aux++) {

            /*Este vai recebendo as palavras at� encontrar um espa�o*/
            if (valor[aux] != ' ') {
                palavras[cont_palavras].string[cont_caracteris] = valor[aux];
                palavras[cont_palavras].tamanho++;
                cont_caracteris++;
            }

            /*Quando um espa�o � encontrado, o contador de palavras muda pois significa que aquela palavra acabou e um nova ir� come�ar*/
            else {
                cont_palavras++;
                cont_caracteris = 0;
                palavras[cont_palavras].tamanho = 0;
            }
        }

        p = 0;
        r = cont_palavras+1;

        mergesort(p, r, palavras);

        for(int aux = 0; aux <= cont_palavras; aux++) {
            for (int aux2 = 0; aux2 < palavras[aux].tamanho; aux2++) {
                printf("%c", palavras[aux].string[aux2]);

            }
            palavras[aux].string[0] = '\0';
            if (aux + 1 <= cont_palavras) {
                printf(" ");
            }

        }
        printf("\n");

    }
    return 0;
}



