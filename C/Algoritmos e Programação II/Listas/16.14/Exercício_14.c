#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int chave;
    struct celula *prox;
} celula;


void busca_insere_C(int y, int x, celula *lst) {

    celula *p, *q, *nova;
    nova = (celula *) malloc(sizeof (celula));

    nova->chave = y;
    p = lst;
    q = lst->prox;

    while (q != NULL && q->chave != x) {
        p = q;
        q = q->prox;
    }

    nova->prox = q;
    p->prox = nova;
}


void remove_lista(celula *p) {

    celula *item_apagar;

    while(p != NULL) {

        item_apagar = p;
        p = p -> prox;
        free(item_apagar);

    }

}

void imprime_lista(celula *lst, int cont) {

    celula *p;

    for (p = lst; p != NULL && cont >= 0; p = p->prox) {
        printf("%d\n", p->chave);
        cont--;
    }


}

int main(void) {

    celula *lista;
    int cont = 0, aux;

    lista = (celula *) malloc(sizeof ( struct celula));

    lista->prox = NULL;


    for(cont = 0; cont < 10; cont++) {
        busca_insere_C(cont, 0, lista);
    }
    printf("-------------------------------\n");
    printf("Valores iniciais da lista:\n");

    aux = cont;
    imprime_lista(lista, cont);

    remove_lista(lista);

    cont = aux;

    printf("-------------------------------\n");
    printf("Depois da exclusao:\n");

    imprime_lista(lista, cont);


}

