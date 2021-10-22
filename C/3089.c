#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

int compara_cres(const void * a, const void * b) {
    return *(int *)a - *(int *)b;
}


int main(void) {

    int quantidade_netos;

    for(int cont = 0; quantidade_netos != 0; cont++) {

        scanf("%d", &quantidade_netos);

        int presentes[quantidade_netos*2];

        int soma[MAX];

        for(int aux = 0; aux < quantidade_netos * 2; aux++) {
            scanf("%d", &presentes[aux]);
        }

        int aux3 = 0;

        for(int aux = 0; aux < 2 * quantidade_netos; aux++) {
            for(int aux2 = 0; aux2 < aux; aux2++) {
                soma[aux3] = presentes[aux] + presentes[aux2];
                aux3++;
            }
        }

        qsort(soma, aux3, sizeof(int), compara_cres);

        for(int aux = 0; aux < aux3; aux++) {
            printf("%d\n", soma[aux]);
        }

        if( quantidade_netos == 1) {
            printf("%d %d\n", soma[aux3/2], soma[aux3/2]);
        }
        else {
            printf("%d %d\n", soma[aux3/2], soma[(aux3/2)-1]);
        }








    }

}
