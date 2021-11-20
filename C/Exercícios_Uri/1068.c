#include <stdio.h>
#define MAX 1001

void empilhar_pilha(int *t, char *P, char y, int n) {

    if (*t != n - 1) {

        (*t)++;
        P[*t] = y;

    } 

}

int verificar_parenteses (char *palavra_final, int cont) {

    int t; 
    char P[cont];

    t = -1;

    for(int aux = 0; aux < cont; aux++) {

        if (palavra_final[aux] == '(') {

            empilhar_pilha(&t, P, palavra_final[aux], cont);

        }

        else if (palavra_final[aux] == ')') {

            if((t != -1) && (P[t] == '(')) {
                t--;
            }
            else {
                return 0;
            }
        }

    }

    if (t == -1) {
        return 1;
    }
    else {
        return 0;
    }


}


int main (void) {
   
    char palavra_recebida[MAX];    

    while (scanf(" %[^\n]%*c", palavra_recebida) != EOF) {

        char palavra_final[MAX];
        int cont = 0, result;

        for(int aux = 0; palavra_recebida[aux] != '\0'; aux++) {

            if ((palavra_recebida[aux] == '(') || (palavra_recebida[aux] == ')')) {
                palavra_final[cont] = palavra_recebida[aux];
                cont++;
            }

        }
        palavra_final[cont] = '\0';
        palavra_recebida[0] = '\0';

        result = verificar_parenteses(palavra_final, cont);

        if (result == 1) {
            printf("correct\n");
        }
        else  {
            printf("incorrect\n");
        }

    }

    return 0;

}