#include <stdio.h>
#include <stdlib.h>

int compara_cres(const void * a, const void * b) {
    return *(int *)a - *(int *)b;
}

int main(void) {

    int n, aux ,num_pessoas;

    scanf("%d", &n);

    for(int cont = 0; cont < n; cont ++) {

        scanf("%d", &num_pessoas);

        int alturas[num_pessoas];

        for(aux = 0; aux < num_pessoas; aux++) {

            scanf("%d", &alturas[aux]);

        }

        qsort(alturas, aux, sizeof(int), compara_cres);

        for(aux = 0; aux < num_pessoas; aux++) {

            if (aux + 1 >= num_pessoas) {
                printf("%d\n", alturas[aux]);
            }

            else {
                printf("%d ", alturas[aux]);
            }

        }

    }

    return 0;

}
