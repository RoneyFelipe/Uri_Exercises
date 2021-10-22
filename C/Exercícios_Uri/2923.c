#include <stdio.h>


int main(void) {

    int  T, A, W, C;

    int percentual_utilizado;

    scanf("%d", &T);
    scanf("%d", &A);
    scanf("%d", &W);
    scanf("%d", &C);

    percentual_utilizado = (A * 100) / T;

    if(percentual_utilizado >= C) {
        printf("critical\n");
    }
    else if (percentual_utilizado >= W) {
        printf("warning\n");
    }
    else {
        printf("OK\n");
    }





}
