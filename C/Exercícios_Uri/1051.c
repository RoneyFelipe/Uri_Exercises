#include <stdio.h>

int main(void) {

    float salario, imposto_total;
    float imposto_primeira_casa, imposto_segunda_casa, imposto_terceira_casa;
    float primeira_casa, segunda_casa, terceira_casa;

    scanf("%f", &salario);

    if (salario <= 2000) {
        printf("Isento\n");
    }
    else if ((salario >= 2000.01) && (salario <= 3000.00)) {
        imposto_primeira_casa = (salario - 2000) * 0.08;
        printf("R$ %.2f\n", imposto_primeira_casa);

    }

    else if ((salario >= 3000.01) && (salario <= 4500.00)) {
        segunda_casa = salario - 3000.00;
        imposto_segunda_casa = segunda_casa * 0.18;

        primeira_casa = salario - 2000.00 - segunda_casa;
        imposto_primeira_casa = primeira_casa * 0.08;

        imposto_total = imposto_segunda_casa + imposto_primeira_casa;

        printf("R$ %.2f\n", imposto_total);


    }
    else if (salario >= 4500.00) {

        terceira_casa = salario - 4500.00;
        imposto_terceira_casa = terceira_casa * 0.28;

        segunda_casa = salario - 3000.00 - terceira_casa;
        imposto_segunda_casa = segunda_casa * 0.18;

        primeira_casa = salario - 2000.00 - segunda_casa - terceira_casa;
        imposto_primeira_casa = primeira_casa * 0.08;

        imposto_total = imposto_terceira_casa + imposto_segunda_casa + imposto_primeira_casa;

        printf("R$ %.2f\n", imposto_total);
    }

}


/*double valor;
scanf("%lf",%valor);
int valor_n = valor;
int valor_m = (valor - valor_n) * 100;*\

