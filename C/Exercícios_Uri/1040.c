#include <stdio.h>

int main(void) {
    float n1, n2, n3, n4, nota_exame, media_exame, media;

    scanf("%f %f %f %f", &n1, &n2, &n3, &n4);

    media = (n1 * 2 + n2 * 3 + n3 * 4 + n4) / 10.0;
    printf("Media: %.1f\n", media);

    if (media >= 7) {
        printf("Aluno aprovado.\n");
    }

    else if ((media >= 5) && (media < 7)) {

        printf("Aluno em exame.\n");
        scanf("%f", &nota_exame);
        media_exame = (nota_exame + media) / 2.0;
        printf("Nota do exame: %.1f\n", nota_exame);

        if (media_exame >= 5) {
            printf("Aluno aprovado.\n");
            printf("Media final: %.1f\n", media_exame);
        }
        else {
            printf("Aluno reprovado.\n");
            printf("Media final: %.1f\n", media_exame);
        }

    }
    else {
            printf("Aluno reprovado.\n");

        }

    return 0;

}
