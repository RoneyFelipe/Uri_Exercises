#include <stdio.h>

int main(void) {
    int cod1, p1, cod2, p2;
    float valor1, valor2, valor_total;

    scanf("%d %d %f", &cod1, &p1, &valor1);
    scanf("%d %d %f", &cod2, &p2, &valor2);

    valor_total = (p1 * valor1 + p2 * valor2);

    printf("VALOR A PAGAR: R$ %.2f\n", valor_total);
    return 0;


}
