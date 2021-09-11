#include <stdio.h>


int main(void) {
    int n, x;
    int sapos = 0;
    int ratos = 0;
    int coelhos = 0;
    double total = 0;
    char animal;

    scanf("%d", &n);

    for (int cont = 0; cont < n; cont ++) {
        scanf("%d %c", &x, &animal);
        total = total + x;

        if (animal == 'C') {
            coelhos = coelhos + x;
        }
        else if (animal == 'R') {
            ratos = ratos + x;
        }
        else if (animal == 'S') {
            sapos = sapos + x;
        }

    }

    printf("Total: %.0f cobaias\n", total);
    printf("Total de coelhos: %d\n", coelhos);
    printf("Total de ratos: %d\n", ratos);
    printf("Total de sapos: %d\n", sapos);
    printf("Percentual de coelhos: %.2f %\n", (coelhos * 100) / total);
    printf("Percentual de ratos: %.2f %\n",(ratos * 100) / total);
    printf("Percentual de sapos: %.2f %\n",(sapos * 100) / total);

}

