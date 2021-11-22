#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

    int soma, valor;

    for(int cont = 1; cont < argc; cont++) {

        valor = atoi(argv[cont]);

        soma += valor;

    }

    printf("Soma Total:", valor);

    return 0;

}
