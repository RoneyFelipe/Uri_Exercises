#include <stdio.h>
#define MAX 10000


int main(void) {

    int letra[MAX], *p, *p_invertida, aux;

    for(p = letra; ((*p = getchar()) != '\n' && (p < letra + MAX)); p++);

    printf("Palavra original:\n");
    for(p = letra; *p != '\0' ; p++) {
        printf("%c", *p);
    }

    p_invertida = letra;

    p = p - 1;

    while(p >= p_invertida) {

        aux = *p_invertida;

        *p_invertida = *p;

        *p = aux;

        p_invertida++;

        p--;

    }

    printf("\nPalavra invertida:");
    for(p = letra; *p != '\0'; p++) {
        printf("%c", *p);
    }

    printf("\n");

    return 0;

}

