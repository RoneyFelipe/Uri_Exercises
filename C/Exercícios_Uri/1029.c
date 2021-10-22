#include <stdio.h>

int fibonacci (int n, int *cont) {

    *cont = *cont + 1;

    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return fibonacci(n-1, cont) + fibonacci(n-2, cont);
    }

}

int main(void) {

    int n, valor, cont = -1, result;

    scanf("%d", &n);

    for(int aux = 0; aux < n; aux++) {

        scanf("%d", &valor);

        result = fibonacci(valor, &cont);

        printf("fib(%d) = %d calls = %d\n", valor, cont, result);

        cont = -1;

    }

    return 0;

}
