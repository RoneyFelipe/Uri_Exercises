#include <stdio.h>

/**************************************************
*
* Nome do(a) estudante: Roney Felipe de Oliveira Miranda
* Trabalho 1
* Professor(a): Diego Rubert
*
*/

/* Armazena informações de uma capivara */
typedef struct {
    int numero; /* Número da capivara = posição na largada */
    int ultrapass; /* Quantidade de ultrapassagens feitas */
} capivara;

/*Função responsável por receber duas capivaras e inverter seus valores dentro do array_de_capivaras*/
/*Ao fim, capivara_1 terá o valor de capivara_2 e capivara_2 terá o valor de capivara_1*/
void troca(capivara *capivara_1, capivara *capivara_2){

    capivara aux_capivara = *capivara_1;
    *capivara_1 = *capivara_2;
    *capivara_2 = aux_capivara;

}


void intercala(int p, int q, int r, capivara *array_de_capivaras) {

    /*i, j e k irão controlar as posições que serão intercaladas*/
    /*i e j do array_de_capiravas e k do vetor auxiliar (w)*/
    int i, j, k;

    /*Vetor auxiliar para ordenação por intercalação,*/
    /*No final, ele será copiado inteiramente para o vetor de capivaras pois auxiliar_de_capivaras estará ordenado*/
    capivara auxiliar_de_capivaras[r+1];

    /*i recebe p, primeira posição do array_de_capiravas*/
    i = p;

    /*i recebe q, posição no meio do array_de_capiravas*/
    j = q;

    /*k começa em zero pois ele é contador de auxiliar_de_capivaras*/
    /*E nele os valores serão ordenados*/
    k = 0;

    /*Este while será executado enquanto i, contador que vai da primeira posição da primeira parte*/
    /*do array_de_capivaras até q (índice da última posição da primeira parte do array).*/
    /*Assim como, enquanto j, contador que vai da primeira posição da segunda parte do array_de_capivaras*/
    /*até r (índice da última posição da segunda parte do array).*/

    while (i < q && j < r) {

        /*Quando a quantidade de ultrapassagens em array_de_capiravas[i] == array_de_capiravas[j], */
        /*devemos ordenar via o número na fila de largada.*/
        if (array_de_capivaras[i].ultrapass == array_de_capivaras[j].ultrapass) {


            /*Desse modo, caso o número na fila de largada de array_de_capivaras[j] seja menor que em array_de_capivaras[i],*/
            /*auxiliar_de_capivaras recebe array_de_capivaras[j]*/
            if(array_de_capivaras[i].numero > array_de_capivaras[j].numero) {

                auxiliar_de_capivaras[k] = array_de_capivaras[j];

                j++;
            }

            /*Desse modo, caso o número na fila de largada de array_de_capivaras[i] seja menor que*/
            /* em array_de_capivaras[j], auxiliar_de_capivaras recebe array_de_capivaras[i]*/
            else {

                auxiliar_de_capivaras[k] = array_de_capivaras[i];

                i++;
            }
        }

        /*Quando a quantidade de ultrapassagens de array_de_capivaras[i] for maior que*/
        /*array_de_capivaras[j], auxiliar_de_capivaras recebe array_de_capivaras[i]*/
        else if (array_de_capivaras[i].ultrapass > array_de_capivaras[j].ultrapass) {

            auxiliar_de_capivaras[k] = array_de_capivaras[i];

            i++;

        }


        /*Se array_de_capivaras[i] não é igual ou maior que array_de_capivaras[j], ela só pode ser menor.*/
        /*Então, auxiliar_de_capivaras[k] recebe array_de_capivaras[j]*/

        else {
            auxiliar_de_capivaras[k] = array_de_capivaras[j];
            j++;
        }

        /*O k é incrementado pois auxiliar_capivaras já recebeu o valor ordenado nessa posição.*/
        k++;
    }

    /*Caso o intervalo de p à q - 1 seja maior que de q à r - 1, os termos restantes de*/
    /*p à q-1 devem ser movidos para auxilixar_de_capivaras*/
    while (i < q) {
        auxiliar_de_capivaras[k] = array_de_capivaras[i];
        i++;
        k++;
    }

    /*Caso o intervalo de q à r - 1 seja maior que de p à a - 1, os termos restantes de*/
    /*q à r - 1 devem ser movidos para auxilixar_de_capivaras*/
    while (j < r) {
        auxiliar_de_capivaras[k] = array_de_capivaras[j];
        j++;
        k++;
    }

    /*Copia os termos ordenados que estão em auxiliar_capivaras para o array_de_capivaras*/
    for (i = p; i < r; i++)
        array_de_capivaras[i] = auxiliar_de_capivaras[i-p];

}

/*Função responsável por ordenar o vetor de capivaras*/
void mergesort(int p, int r, capivara *array_de_capivaras) {

    /*A variável q é incubida de dizer até qual posição a primeira parte do array_de_capivaras vai.*/
    /*Da mesma forma, determinar em qual posição inicia a segunda parte do array_de_capivaras.*/
    /*Com isso, a função intercala irá realizar a quebra do array_de_capivaras até que seja possível*/
    /*analisar apenas duas ou três posições por vez. Lembrando que a função mergesorte é uma função recursiva,*/
    /*então será repetida algumas vezes, sempre modificando o valor de q.*/

    int q;
    if (p < r - 1) {

        /*Determinação do valor de q, muda a cada recursão*/
        q = (p + r) / 2;

        /*Nova recursão, irá resultar na ordenação dos termos entre p e q*/
        mergesort(p, q, array_de_capivaras);

        /*Nova recursão, irá resultar na ordenação dos termos entre q e r*/
        mergesort(q, r, array_de_capivaras);

        /*Chamada da função intercala, incubida de fazer a intercalação dos termos*/
        /*dentro do vetor, na prática é ela que realmente os ordena*/
        intercala(p, q, r, array_de_capivaras);

    }
}

int main(void) {

    /*Declaração das variáveis que irão receber o total de capivaras competindo e*/
    /*a ultrapassagem que foi inserida*/
    int total_de_capivaras, ultrapassagem_atual;

    /*Variáveis padrões para ordenação via merge_sort. p = 0 e r = total de posições do vetor que será ordenado*/
    int p, r;

    /*Inserção do número total de capivaras competindo*/
    scanf("%d", &total_de_capivaras);

    /*Declaração do vetor que contém todas as capivaras competidoras, assim como seu número na fila e*/
    /*total de ultrapassagens já realizadas*/
    capivara array_de_capivaras[total_de_capivaras];

    /*A partir da quantidade de capivaras competidoras devemos atribuir o número de largada a cada uma delas,*/
    /*de 1 à total_de_capivaras. Assim como, atribuir o valor 0 a suas ultraspassagens para que no futuro*/
    /*possamos utilizar o operador ++ para agregar valor sempre que tais realizarem uma ultrapassagem*/
    for(int contador = 0; contador < total_de_capivaras; contador++) {
        array_de_capivaras[contador].numero = contador + 1;
        array_de_capivaras[contador].ultrapass = 0;
    }

    /*While responsável por receber as capivaras que caparam de realizar uma ultrapassagem*/
    while(scanf("%d", &ultrapassagem_atual) != EOF) {

        /*For incubido de procurar a capivara que realizou a ultrapassagem dentro do array_de_capivaras*/
        for(int contador = 0; contador < total_de_capivaras; contador++) {

            /*Este if verifica se na posição contador, do array_de_capivaras, está a capivara que realizou a ultrapassaem*/
            if(array_de_capivaras[contador].numero == ultrapassagem_atual) {


                /*Se sim, o valor de ultrapassagens (ultrapass) é agregado em 1 e */
                /*as capivaras são trocadas de posição dentro do array*/

                array_de_capivaras[contador].ultrapass++;

                /*A capivara que ultrapassou assume a posição da que foi ultrapassada e a ultrapassada assume a da que ultrapassou*/

                troca(&array_de_capivaras[contador], &array_de_capivaras[contador - 1]);

            }
        }
    }

    /*Como dito anteriomente, p sempre vai recebe o indice da primeira posição do*/
    /*array que será ordenado, nesse caso é 0*/
    p = 0;

    /*Da mesma forma, r recebe o valor da última posição do array que será ordenado.*/
    /*Nesse caso, total_de_capivaras - 1, porque um vetor sempre inicia da posição 0*/
    r = total_de_capivaras - 1;

    /*Este laço realiza a exibição da ordem de chegada das capivaras, iniciando na posição 0, contador, e*/
    /*indo até total_de_capivaras que é o limite do array*/
    for(int contador = 0; contador < total_de_capivaras; contador++) {

        /*O seguinte if e else, servem para que não haja um " " após a exbição da última capivara*/
        if (contador + 1 < total_de_capivaras) {
            printf("%d ", array_de_capivaras[contador].numero);
        }
        else {
            printf("%d", array_de_capivaras[contador].numero);
        }

    }
    /*Pula uma linha entre a ordem que as capivaras chegaram e a ordem de classificação dentro da competição*/
    printf("\n");

    /*Chama o método de ordenação, passando o p (0), r(total_de_capivaras) e o array_de_capivaras)*/
    mergesort(p, r, array_de_capivaras);


    /*Este laço realiza a exibição da ordem de classificação das capivaras, iniciando na posição 0, contador, e*/
    /*indo até total_de_capivaras que é o limite do vetor*/
    for(int contador = 0; contador < total_de_capivaras; contador++) {

        /*O seguinte if e else, servem para que não haja um " " após a exbição da última capivara*/
        if (contador + 1 < total_de_capivaras) {
            printf("%d ", array_de_capivaras[contador].numero);
        }
        else {
            printf("%d", array_de_capivaras[contador].numero);
        }

    }

}


