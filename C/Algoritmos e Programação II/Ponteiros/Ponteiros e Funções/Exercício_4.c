#include <stdio.h>
#define MAX 1000



int *maximo(int n, int v[MAX]) {

    int *maior;

    maior = &v[0];

    for(int cont = 0; cont < n; cont ++) {

        if(*maior < v[cont]) {
                *maior = v[cont];
        }

    }
    return maior;

}


int main(void) {

    int n, valor, v[MAX], *maior;


    printf("Qual sera o tamanho do vetor:\n");
    scanf("%d", &n);

     printf("Insira o vetor (Um digito por linha):\n");

    for(int cont = 0; cont < n; cont ++) {
            scanf("%d", &valor);
            v[cont] = valor;
    }


    maior = maximo(n, v);

    printf("Valor do Maior: %d\n", *maior);
    printf("Ponteiro do Maior: %p\n", maior);

    return 0;

}
