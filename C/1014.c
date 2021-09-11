#include <stdio.h>

int main(void) {
    float x,y,cm;

    scanf("%f",&x);
    scanf("%f",&y);

    cm = x/y;
    printf("%.3f km/l\n", cm);

    return 0;


}

