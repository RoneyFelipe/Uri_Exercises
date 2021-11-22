#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int chave;
    struct cel *ant;
    struct cel *prox;
} celula;

void inserir_sem_cabeca(int x, celula **lst) {

    celula *p, *q, *nova;

    nova = (celula *) malloc(sizeof (celula));
    nova -> chave = x;

    p = NULL;
    q = *lst;

    while (q != NULL) {
        p = q;
        q = q->prox;
    }

    nova->ant = p;
    nova->prox = q;

    if (p != NULL) { 
         p->prox = nova;
    }
    else {
        *lst = nova;
    }

    if(q != NULL) {
        q-> ant = nova;
    }
       
}

void busca_remover_sem_cabeca(int x, celula **lst) {

    celula *p;
    p = *lst;

    while (p != NULL && p->chave != x)
        p = p->prox;

    if (p != NULL) {

        if (p->prox != NULL) {
            p->prox->ant = p->ant;
        }

        if (p->ant != NULL) {
            p->ant->prox = p->prox;
        }

        else {
            *lst = p->prox;
        }
            
        free(p);

    }
}

void imprime_lista(celula *lst) {

    celula *p;
    for (p = lst; p != NULL; p = p->prox) {
        printf("%d\n", p->chave);
    }


}


int main (void) {

    celula *lista;
    lista = NULL;

    int dec = 1, n;

    while ((dec < 3) && (dec > 0)) {

        printf("Deseja inserir ou remover?\n");
        printf("1 - Inserir  2 - Remover  3 - Encerrar programa: ");

        scanf("%d", &dec);

        if (dec == 1) {
            printf("Qual valor deseja inserir?: ");
            scanf("%d",&n);

            inserir_sem_cabeca(n, &lista);

            printf("\n-------------------------------\n");
            printf("Lista depois da insercao:\n");

            imprime_lista(lista);

             printf("\n-------------------------------\n");

        }

        else if (dec == 2) {
            printf("Qual valor deseja remover?: ");
            scanf("%d",&n);

            busca_remover_sem_cabeca(n, &lista);

            printf("\n-------------------------------\n");
            printf("Depois da exclusao:\n");

            imprime_lista(lista);

             printf("\n-------------------------------\n");

        } 

        else {
            printf("\n------------ Encerrado ------------\n");
        }
    }
    
    return 0;

}
