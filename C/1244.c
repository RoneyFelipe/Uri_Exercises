#include <stdio.h>
#define MAX 51


typedef struct {
        int tamanho;
        char string[51];

    } palavra;



int main(void) {

    char valor[MAX];

    int n, cont_palaras = 0, tamanho_total = 0;

    scanf("%d", &n);

    for(int cont = 0; cont < n; cont++) {
        palavra palavras[MAX][MAX];

        char valor[MAX];
        scanf(" %s", &valor);

        for( int aux = 0; (valor[aux] != '\0'); aux++) {
            if (valor[aux] != ' ') {
                palavras[cont][cont_palaras].string[aux] = valor[aux];
                tamanho_total++;

            }
            else {
                palavras[cont][aux].tamanho = cont_palaras + 1;
                cont_palaras++;
            }
            for (int aux2 = 0; aux2 < tamanho_total; aux2++){
                for(int aux3 = 0; aux3 <= palavras[cont][aux2].tamanho; aux3++) {
                    printf("%c", palavras[cont][aux2].string[aux3]);
                }
            }


        }


    }


    return 0;
}
