#include <stdio.h>




int main(void) {

    int n;

    char cartas[1001];

    scanf("%d", &n);

    for(int cont = 0; cont < n; cont++) {

        scanf(" %s", &cartas);

        int a = 0, q = 0, k = 0, j = 0;

        for(int aux = 0; cartas[aux] != '\0'; aux++) {
            if (cartas[aux] == 'Q') {
                q++;
            }
            if (cartas[aux] == 'J') {
                j++;
            }
            if (cartas[aux] == 'A') {
                a++;
            }
            if (cartas[aux] == 'K') {
                k++;
            }
        }

        if ((a > 0) && (k > 0) && (j > 0) && (q > 0)) {
            printf("Aaah muleke\n");
        }
        else {
            printf("Ooo raca viu\n");
        }

    }


}
