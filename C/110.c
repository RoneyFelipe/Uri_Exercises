#include <stdio.h>

int main(void) {
    int x, y, cont, soma, menor, maior;
    soma = 0;


    scanf("%d %d", &x, &y);
    for (cont = 0; (x > 0) && (y > 0); cont ++) {


        if (x > y) {
            maior = x;
            menor = y;
        }
        else {
            maior = y;
            menor = x;
        }
        for (int i = menor; i <= maior; i ++){
                soma = soma + i;
                printf("%d ", i);
        }
        printf("Sum=%d\n", soma);
        soma = 0;

        scanf("%d %d", &x, &y);
    }
}

