#include <stdio.h>
#include <string.h>


void copiar_strings(char ultimo_idioma[],char idiomas[]) {
    int i;
    for (i = 0; idiomas[i] != '\0'; i ++) {
        ultimo_idioma[i] = idiomas[i];
    }
    ultimo_idioma[i] = '\0';


}

int main(void) {
    int n, k, total_idiomas = 0;
    char idiomas[50];
    char ultimo_idioma[50] = {'k','\0'};

    scanf("%d", &n);
    for(int cont = 0; cont < n; cont ++) {
        scanf("%d", &k);

        for(int aux = 0; aux < k; aux ++) {

            scanf(" %s", idiomas);

            if ((strcmp(ultimo_idioma, idiomas) != 0) && (aux > 0)) {
                total_idiomas++;
            }
            copiar_strings(ultimo_idioma,idiomas);

        }

        if (total_idiomas > 0) {
            printf("ingles\n");
        }
        else {
            printf("%s\n", idiomas);
        }
        total_idiomas = 0;
    }

}
