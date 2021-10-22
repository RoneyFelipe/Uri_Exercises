#include <stdio.h>

int main(void) {
    char nome;
    double salario, venda, novo_salario;

    scanf("%s", &nome);
    scanf("%lf", &salario);
    scanf("%lf", &venda);

    novo_salario = salario + venda * 0.15;

    printf("TOTAL = R$ %.2f\n", novo_salario);

    return 0;

}
