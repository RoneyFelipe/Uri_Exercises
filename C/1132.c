#include <stdio.h>

int main(void) {

    int n1, n2, maior, menor, soma = 0;

    scanf("%d", &n1);
    scanf("%d", &n2);

    if(n1 > n2) {
        maior = n1;
        menor = n2;
    }
    else if (n2 >= n1) {
        maior = n2;
        menor = n1;
    }

    for (int cont = menor; cont <= maior; cont ++) {
        if (cont%13 != 0) {
            soma = soma + cont;
        }
    }
    printf("%d\n", soma);
    return 0;

}
