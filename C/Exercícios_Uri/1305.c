#include <stdio.h>
#define MAX 1000



int main(void) {

    float num;

    float aproximacao;


    while(scanf("%f", &num) != EOF) {

        scanf("%f", &aproximacao);

        int result;

        int inteiro_num = num;

        float decimal_num = num - inteiro_num;


        if(decimal_num > aproximacao) {
            result = inteiro_num + 1;
        }
        else {
            result = inteiro_num;
        }

        printf("%d\n", result);


    }



}
