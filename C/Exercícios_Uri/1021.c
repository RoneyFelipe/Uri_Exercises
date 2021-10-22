#include <stdio.h>
#include <math.h>

int main(void) {
    int notas_100, notas_50, notas_20, notas_10, notas_5, notas_2;
    int moedas_1, moedas_50, moedas_25, moedas_10, moedas_05, moedas_010, moedas_01;
    int dinheiros, resto, moedas, moedas_resto;
    double valor;

    scanf("%lf", &valor);

    dinheiros = valor;

    notas_100 = dinheiros / 100;
    valor = valor - notas_100 * 100;
    resto = dinheiros%100;

    notas_50 = resto / 50;
    valor = valor - notas_50 * 50;
    resto = resto%50;

    notas_20 = resto / 20;
    valor = valor - notas_20 * 20;
    resto = resto%20;

    notas_10 = resto / 10;
    valor = valor - notas_10 * 10;
    resto = resto%10;

    notas_5 = resto / 5;
    valor = valor - notas_5 * 5;
    resto = resto%5;

    notas_2 = resto / 2;
    valor = valor - notas_2 * 2;
    resto = resto%2;

    moedas_1 = resto;
    valor = valor - moedas_1;

    valor = valor * 100 + 0.5;

    resto = valor;

    printf ("NOTAS:\n");

    moedas_50 = resto/50;
    resto = resto%50;

    moedas_25 = resto/25;
    resto = resto%25;

    moedas_010 = resto/10;
    resto = resto%10;

    moedas_05 = resto/5;
    resto = resto%5;

    moedas_01= resto;

    printf ("%d nota(s) de R$ 100.00\n",notas_100);

    printf ("%d nota(s) de R$ 50.00\n",notas_50);

    printf ("%d nota(s) de R$ 20.00\n",notas_20);

    printf ("%d nota(s) de R$ 10.00\n",notas_10);

    printf ("%d nota(s) de R$ 5.00\n",notas_5);

    printf ("%d nota(s) de R$ 2.00\n",notas_2);

    printf ("MOEDAS:\n");

    printf ("%d moeda(s) de R$ 1.00\n",moedas_1);

    printf ("%d moeda(s) de R$ 0.50\n",moedas_50);

    printf ("%d moeda(s) de R$ 0.25\n",moedas_25);

    printf ("%d moeda(s) de R$ 0.10\n",moedas_010);

    printf ("%d moeda(s) de R$ 0.05\n",moedas_05);

    printf ("%d moeda(s) de R$ 0.01\n",moedas_01);

    return 0;
}
