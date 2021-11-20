#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 51

typedef struct cel {
int chave;
struct cel *prox;
} celula;

void enfileira_enc_C(celula **f, int y) {
    celula *nova;
    nova = (celula *) malloc(sizeof (celula));
    nova->chave = y;
    nova->prox = NULL;
    (*f)->prox = nova;
    *f = nova;
}
 
int desenfileira_enc_C(celula *i, celula **f) {
    int x;
    celula *p;
    x = INT_MIN;
    p = i->prox;
    if (p != NULL) {
        x = p->chave;
        i->prox = p->prox;
        free(p);
        if (i->prox == NULL)
        *f = i;
    }
    return x;
}

int main (void) {

    int total_cartas;
    
    scanf("%d", &total_cartas);

    while (total_cartas != 0) {

        celula *i, *f;
        i = (celula *) malloc(sizeof (celula));
        i->prox = NULL;
        f = i;

        int aux = 0, aux2 = 0, lixo;
        
        int digitos_descartados[total_cartas];

        for(aux = 1; aux <= total_cartas; aux++) {

            enfileira_enc_C(&f, aux);

        }

        

        while(aux - 2> aux2) {
            
            digitos_descartados[aux2] = desenfileira_enc_C(i, &f);
            enfileira_enc_C(&f, i->prox->chave);
            lixo = desenfileira_enc_C(i, &f);
            aux2++;
            

        }

        printf("Discarded cards:");

        for(aux2 = 0; aux - 2 > aux2; aux2++) {

            if(aux2 + 1 == aux - 2) {
                printf(" %d\n", digitos_descartados[aux2]);
            } 
            else {
                printf(" %d,", digitos_descartados[aux2]);
            }

            

        }
        printf("Remaining card: %d\n", lixo);

        
        

        scanf("%d", &total_cartas);

    }

    return 0;

}