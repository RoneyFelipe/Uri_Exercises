#include <stdio.h>
#define MAX 301

void empilha_seq(int *t, char *P, char y, int n) {

    if (*t != n - 1) {

        (*t)++;
        P[*t] = y;

    } 

}

int contar_bases(char *RNA) {

    int t; 
    int quantidade_bases = 0;
    char P[MAX];

    t = -1;

    for(int cont = 0; RNA[cont] != '\0'; cont++) {

        if (((RNA[cont] == 'B') && (P[t] != 'S')) || ((RNA[cont] == 'S') && (P[t] != 'B'))) {
            empilha_seq(&t, P, RNA[cont], MAX);
        }

        else if (((RNA[cont] == 'B') && (P[t] == 'S')) || ((RNA[cont] == 'S') && (P[t] == 'B'))) {
            t--;
            quantidade_bases++;
        }

        else if (((RNA[cont] == 'C') && (P[t] != 'F')) || ((RNA[cont] == 'F') && (P[t] != 'C'))) {
            empilha_seq(&t, P, RNA[cont], MAX);
        }

        else if (((RNA[cont] == 'C') && (P[t] == 'F')) || ((RNA[cont] == 'F') && (P[t] == 'C'))) {
            t--;
            quantidade_bases++;
        }

    }

    return quantidade_bases;

}


int main (void) {

    char RNA[MAX];

    while(scanf("%s", RNA) != EOF) {
        
        int result;

        result = contar_bases(RNA);

        printf("%d\n", result);

    }
    

    return 0;
    
} 