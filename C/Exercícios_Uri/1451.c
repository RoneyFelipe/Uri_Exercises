#include <stdio.h>
#include <stdlib.h>
#define MAX 100001


typedef struct cel {
    int chave;
    struct cel *prox;
} celula;


void insere_C(char y, celula *p, celula **fim) {

    celula *nova;
    nova = (celula *) malloc(sizeof (celula));
    nova->chave = y;
    nova->prox = p->prox;
    p->prox = nova;

    if(nova->prox == NULL) {
        *fim = nova;
    }

}

void remove_lista(celula *p) {

    celula *item_apagar;
    p = p->prox;

    while(p != NULL) {

        item_apagar = p;
        p = p -> prox;
        free(item_apagar);

    }

}

void imprimir_lista(celula *lista) {

    celula *q;

    for(q = lista->prox; q != NULL; q = q->prox) {
        printf("%c", q->chave);
    }

    printf("\n");

}


int main (void) {

    celula *lista, *fim, *cursor;
    lista = (celula *) malloc(sizeof (celula));
    char sequencia[MAX];

    lista->prox = NULL;
    cursor = lista;
    fim = lista;


   for(int cont = 0; scanf(" %[^\n]%*c", sequencia) != EOF; cont++) {

       for(int aux = 0; sequencia[aux] != '\0'; aux++) {
            if (sequencia[aux] == '[') {
                cursor = lista;
            } 
            else if (sequencia[aux] == ']') {
                cursor = fim;
            }

            else {
                insere_C(sequencia[aux], cursor, &fim);
                cursor = cursor->prox;
            }
        }

        imprimir_lista(lista);
        remove_lista(lista);
        lista->prox = NULL;
        cursor = lista;
        fim = lista;
        
    }

    return 0;

}