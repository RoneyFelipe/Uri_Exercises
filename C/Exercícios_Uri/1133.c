#include <stdio.h>

int main(void) {

    int n1, n2, maior, menor, cont;

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

    for (cont = menor + 1; cont < maior; cont ++) {
        if ((cont%5 == 2) || (cont%5 == 3)) {
            printf("%d\n",cont);
        }
    }

}
