#include <stdio.h>
#include <math.h>

int main(void) {
    float a, b, c, delta, r1, r2;

    scanf("%f %f %f", &a, &b, &c);

    delta = (b*b) - (4*a*c);

    if ((delta <= 0) || (a == 0)) {
        printf("Impossivel calcular\n");
    }
    else if (delta > 0) {
        r1 = (-b + sqrt(delta)) / (2* a);
        r2 = (-b - sqrt(delta)) / (2* a);
        printf("R1 = %.5f\n", r1);
        printf("R2 = %.5f\n", r2);
    }

    return 0;

}

