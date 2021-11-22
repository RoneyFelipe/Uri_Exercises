#include <stdio.h>
#define MAX 1000


void min_max(int n, int v[MAX], int *max, int *min) {

    for(int cont = 0; cont < n; cont ++) {
        if (*max < v[cont]) {
            *max = v[cont];
        }
        if (*min > v[cont]) {
            *min = v[cont];
        }
    }


}

int main(void) {

    int n, valor, v[MAX], maior, menor;


    printf("Qual sera o tamanho do vetor:\n");
    scanf("%d", &n);

     printf("Insira o vetor (Um digito por linha):\n");

    for(int cont = 0; cont < n; cont ++) {
            scanf("%d", &valor);
            v[cont] = valor;
    }

    maior = v[0];
    menor = v[1];

    min_max(n, v, &maior, &menor);

    printf("Maior: %d\n", maior);
    printf("Menor: %d", menor);


}
