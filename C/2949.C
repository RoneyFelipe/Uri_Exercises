#include <stdio.h>

int main(void) {
    int A = 0, E = 0, H = 0, M = 0, X = 0;
    int num;
    char nome[100];
    char tipo;

    scanf("%d", &num);
    for (int cont = 0; cont < num; cont ++) {
        scanf("%s %c", &nome, &tipo);
        switch(tipo) {
            case 'A':
                A++;
                break;

            case 'E':
                E++;
                break;

            case 'H':
                H++;
                break;

            case 'M':
                M++;
                break;

            case 'X':
                X++;
                break;

            default:
                break;
        }

    }
    printf("%d Hobbit(s)\n", X);
    printf("%d Humano(s)\n", H);
    printf("%d Elfo(s)\n", E);
    printf("%d Anao(s)\n", A);
    printf("%d Mago(s)\n", M);

    return 0;
}


