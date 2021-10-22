#include <stdio.h>






int main(void) {

    int n, quantidade_esferas;


    scanf("%d", &n);


    for(int cont = 0; cont < n; cont ++) {

        int quantidade_divisores = 0, esferas_necessarias = 0;

        scanf("%d", &quantidade_esferas);


        for(int aux = 1; aux <= quantidade_esferas; aux ++) {

            for(int aux2 = 1; aux2 <= aux; aux2++) {

                if (aux % aux2 == 0) {
                    quantidade_divisores++;
                }

            }
            if (quantidade_divisores%2 == 0) {
                    esferas_necessarias++;
                }

            quantidade_divisores = 0;


        }
         printf("%d\n", esferas_necessarias);
         esferas_necessarias = 0;


    }


}
