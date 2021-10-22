#include <stdio.h>


int main(void) {

    int n1, n2;

    scanf("%d %d", &n1, &n2);

    for (int cont = 1; cont <= n2; cont = cont + n1) {
        for (int aux = cont; aux < cont + n1; aux ++) {
                if (aux + 1 < cont) {
                    printf("%d ", aux);
                }
                else {
                    printf("%d", aux);
                }

        }
        printf("\n");
    }


}
