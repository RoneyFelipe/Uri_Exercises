#include <stdio.h>
#define MAX 1001

void empilhar_pilha(int *t, char *P, char y, int n) {

    if (*t != n - 1) {

        (*t)++;
        P[*t] = y;

    } 

}

int verificar_diamantes (char *palavra_final, int cont) {

    int t; 
    char P[cont];
    int diamantes = 0;

    t = -1;

    for(int aux = 0; aux < cont; aux++) {

        if (palavra_final[aux] == '<') {

            empilhar_pilha(&t, P, palavra_final[aux], cont);

        }

        else if (palavra_final[aux] == '>') {

            if((t != -1) && (P[t] == '<')) {
                t--;
                diamantes++;
            }
        }

    }

    return diamantes;


}

int main (void) {
      
    int n;

    scanf("%d", &n);

    for(int aux = 0; aux < n; aux++) {

        char palavra_recebida[MAX];
        char palavra_final[MAX];
        int cont = 0, result;
         
        scanf(" %[^\n]%*c", palavra_recebida);

        for(int aux2 = 0; palavra_recebida[aux2] != '\0'; aux2++) {

            if ((palavra_recebida[aux2] == '<') || (palavra_recebida[aux2] == '>')) {
                palavra_final[cont] = palavra_recebida[aux2];
                cont++;
            }

        }
        palavra_final[cont] = '\0';

        result = verificar_diamantes(palavra_final, cont);

        printf("%d\n", result);

       

    }

    return 0;

}