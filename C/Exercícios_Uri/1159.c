#include <stdio.h>


int main(void) {

    int n = 13; /*rs*/
    int soma = 0;
    int pares = 0;
    scanf("%d", &n);

    for (int cont = 0; n != 0; cont ++) {

        for (int aux = n ; pares < 5; aux ++) {
            if (aux%2 == 0) {
                pares++;
                soma = soma + aux;
            }
        }
        printf("%d\n", soma);
        soma = 0;
        pares = 0;
        scanf("%d", &n);

    }
    return 0;

}
