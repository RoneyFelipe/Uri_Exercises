#include <stdio.h>

int main(void) {

    int n, num_pessoas;

    scanf("%d", &n);

    int altura_pessoas[231] = {0};

    for(int cont = 0; cont < n; cont++) {

        scanf("%d", &num_pessoas);

        int altura_inserida;

        for(int aux = 0; aux < num_pessoas; aux++) {

            scanf("%d", &altura_inserida);

            altura_pessoas[altura_inserida]++;

        }
        int v = 1;
        for(int aux = 20; aux < 231; aux++) {

                for (int aux2 = 0; aux2 < altura_pessoas[aux]; aux2++) {

                    if(v) {
                        printf("%d", aux);
                        v = 0;
                    }
                    else {
                        printf(" %d", aux);
                    }

                }

                altura_pessoas[aux] = 0;


        }

        printf("\n");

    }

    return 0;

}
