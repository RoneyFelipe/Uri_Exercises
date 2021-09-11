#include <stdio.h>
#define MAX 1000

int main(void) {
    char runas[MAX], valores_runas[MAX], runas_recebidas[MAX];
    int quantidade_runas, valor_amizade;
    int quantidade_amizade = 0, runas_faladas;

    scanf("%d %d", &quantidade_runas, &valor_amizade);

    for (int cont = 0; cont < quantidade_runas; cont ++) {
        scanf(" %c %i", &runas[cont], &valores_runas[cont]);
    }
    scanf("%d", &runas_faladas);
    scanf(" %[^\n]", runas_recebidas);

    for (int cont = 0; runas_recebidas[cont] != "\0"; cont ++) {
        for (int aux = 0; aux < quantidade_runas; aux ++) {
            if ((runas_recebidas[cont] == runas[aux]))  {
                quantidade_amizade += valores_runas[aux];
            }
        }
    }

    if (quantidade_amizade >= valor_amizade) {
        printf("%d\n", quantidade_amizade);
        printf("You shall pass!\n");
    }
    else {
        printf("%d\n", quantidade_amizade);
        printf("My precioooous\n");
    }

}

