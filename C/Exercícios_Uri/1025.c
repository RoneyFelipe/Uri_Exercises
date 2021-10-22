#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

int compara_cres(const void * a, const void * b) {
    return *(int *)a - *(int *)b;
}

int main(void) {

    int total_marmores, total_consulta_marmores, consulta_marmores;
    int cont = 0, encontrei = 1, atual_consulta = 1;

    scanf("%d %d", &total_marmores, &total_consulta_marmores);

    while ((total_consulta_marmores != 0) && (total_marmores != 0)) {
        int marmore[MAX];

        /*Recebendo os valores dos marmores*/

        for(cont = 0; cont < total_marmores; cont++) {
            scanf("%d", &marmore[cont]);
        }

        /*Ordenando os valores*/
        qsort(marmore, cont, sizeof(int), compara_cres);

        /*Fazendos as consultas*/


        for (int aux = 0; aux < total_consulta_marmores; aux ++) {
            scanf("%d", &consulta_marmores);

            if (aux == 0) {
                printf("CASE# %d:\n", atual_consulta);
            }


            for (int aux2 = 0; aux2 < total_marmores ; aux2 ++) {

                if((marmore[aux2] == consulta_marmores) && (encontrei != 0)) {
                    encontrei = 0;
                    printf("%d found at %d\n", consulta_marmores, aux2 + 1);

                }
            }
            /*Se o valor não for encontrado*/
            if (encontrei){
                    printf("%d not found\n", consulta_marmores);
            }
            encontrei = 1;
        }
        scanf("%d %d", &total_marmores, &total_consulta_marmores);

        atual_consulta ++;

    }
}
