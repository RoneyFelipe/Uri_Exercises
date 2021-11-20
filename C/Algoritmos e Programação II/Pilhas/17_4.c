#include <stdio.h>
#define MAX 1000

void empilha_seq(int *t, char *P, char y, int n) {

    if (*t != n - 1) {

        (*t)++;
        P[*t] = y;

    } 

}

int bem_formada (char *palavra, int n) {

    int t; 
    char P[n];

    t = -1;

    for (int cont = 0; cont < n; cont++) {

        if ((palavra[cont] == '(') || (palavra[cont] == '{')) {

            empilha_seq(&t, P, palavra[cont], n);

        }

        else if (palavra[cont] == ')') {

            if (t != -1 && P[t] == '(') {
                t--;
            } 

            else {
                return 0;
            }

        }

        else if (palavra[cont] == '}') {

            if (t != -1 && P[t] == '{') {
                t--;
            } 

            else {
                return 0;
            }

        }
    }

    if (t == -1){
        return 1;  
    } 
    else {
        return 0;
    }

}


int main (void) {

    int cont, result, n = 0;

    char palavra[MAX];
    char new_palavra[MAX];

    printf("Digite a sequencia: \n");

    scanf(" %[^\n]%*c", palavra);

    for(cont = 0; palavra[cont] != '\0'; cont++) {
        
        if(palavra[cont] != ' ') {
            new_palavra[n] = palavra[cont];
            n++;
        }

    }

    new_palavra[n] = '\0';

    result = bem_formada(new_palavra, n);

    if(result == 1) {
        printf("Sequencia bem formada");
    }
    else {
        printf("Sequencia mal formada");
    }


}