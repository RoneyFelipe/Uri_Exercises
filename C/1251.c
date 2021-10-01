#include <stdio.h>
#define MAX 10000

int main(void) {

    char v[MAX], valor[MAX];
    int aux, aux2, tamanho_vetor, cont_m = 0;

    typedef struct {
        int freq;
        int asc;
        char carac[2];

    } caracter;


    int existia = 1;

    for(int cont = 0; scanf(" %s", &valor) != EOF; cont ++) {
        caracter caracteris[MAX];
        caracter caracteris_totais[MAX];

        for(tamanho_vetor = 0; valor[tamanho_vetor] != '\0'; tamanho_vetor ++);

        for (aux = 0; aux < tamanho_vetor; aux ++) {
            for (aux2 = 0; aux2 < aux; aux2 ++) {
                if (valor[aux] == caracteris[aux2].carac[0]) {
                    existia = 0;
                    caracteris[aux2].freq ++;
                }
            }

            if (existia) {
                caracteris[aux2].carac[0] = valor[aux];
                caracteris[aux2].asc = valor[aux];
            }
            else {
                caracteris[aux2].asc = -1;
            }
            existia = 1;
        }

        for(int cont = 0; cont <= aux2; cont++) {
            if(caracteris[cont].asc != -1) {
                caracteris_totais[cont_m] = caracteris[cont];
                if (caracteris_totais[cont_m].asc > 0) {
                    caracteris_totais[cont_m].asc ++;
                }
                cont_m ++;
            }
        }
        qsort(caracteris_totais, cont_m, sizeof(int), compara_cres);

    }




}
