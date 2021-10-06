#include <stdio.h>
#define MAX 1000

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

/*Função responsável por receber duas capivaras e inverter a posição de tais dentro do vetor de capivaras*/
void troca(capivara *a, capivara *b){
    capivara temp = *a;
    *a = *b;
    *b = temp;
}


void intercala(int p, int q, int r, capivara capivaras[MAX]) {

    /*i, j e k irão controlar as posições que serão intercaladas*/
    /*i e j do vetor capivaras e k do vetor auxiliar (w)*/
    int i, j, k;

    /*Vertor auxiliar para ordenação por intercalação,*/
    /*No final, ele será copiada inteiramente para o vetor de capivaras pois auxiliar_de_capivaras estará ordenado*/
    capivara auxiliar_de_capivaras[MAX];

    /*i recebe p, primeira posição do vetor de capivaras*/
    i = p;

    /*i recebe q, posição no meio do vetor de capivaras*/
    j = q;

    /*k começa em zero pois nele os valores ordenados serão ordenados*/
    k = 0;

    /*Este while verificada qual valor é maior entre capivaras[i].ultrapass e capivaras[j].ultrapass*/
    while (i < q && j < r) {

        /*Quando a quantidade de ultrapassagens em capiravas[i] == capiravas[j], devemos ordenar via o número na fila*/
        /*de largada.*/
        if (capivaras[i].ultrapass == capivaras[j].ultrapass) {


            /*Desse modo, caso o número na fila de largada de capivaras[j] seja menor que em capivaras[i],*/
            /*auxiliar_de_capivaras recebe capivaras[j]*/
            if(capivaras[i].numero > capivaras[j].numero) {

                auxiliar_de_capivaras[k] = capivaras[j];

                j++;
            }

            /*Desse modo, caso o número na fila de largada de capivaras[i] seja menor que em capivaras[j],*/
            /*auxiliar_de_capivaras recebe capivaras[i]*/
            else {

                auxiliar_de_capivaras[k] = capivaras[i];

                i++;
            }
        }

        /*Quando a quantidade de ultrapassagens de capivaras[i] for maior que capivaras[j], auxiliar_de_capivaras */
        /*recebe capivaras[i]*/
        else if (capivaras[i].ultrapass > capivaras[j].ultrapass) {

            auxiliar_de_capivaras[k] = capivaras[i];

            i++;

        }


        /*Se capivaras[i] não é igual ou maior que capivaras[j], ela só pode ser menor.*/
        /*Então, auxiliar_de_capivaras[k] recebe recebe capivaras[j]*/

        else {
            auxiliar_de_capivaras[k] = capivaras[j];
            j++;
        }

        /*O k é incrementado pois auxiliar_capivaras já recebeu o valor ordenado nessa posição.*/
        k++;
    }

    /*Caso o intervalo de p à q - 1 seja maior que de q à r - 1, os termos restantes de*/
    /*p à q-1 devem ser movidos para auxilixar_de_capivaras*/
    while (i < q) {
        auxiliar_de_capivaras[k] = capivaras[i];
        i++;
        k++;
    }

    /*Caso o intervalo de q à r - 1 seja maior que de p à a - 1, os termos restantes de*/
    /*q à r - 1 devem ser movidos para auxilixar_de_capivaras*/
    while (j < r) {
        auxiliar_de_capivaras[k] = capivaras[j];
        j++;
        k++;
    }

    /*Copia os termos ordenados que estão em auxiliar_capivaras para o vetor capivaras original*/
    for (i = p; i < r; i++)
        capivaras[i] = auxiliar_de_capivaras[i-p];

}

/*Função responsável por ordenar o vetor de capivaras*/
void mergesort(int p, int r, capivara capivaras[MAX]) {

    /*A variável q é incubida de dizer até qual posição o vetor será utilizado na função intercala*/
    /*Como a função mergesorte é uma função recursiva, o q sempre será diminuido até chegar em 2.*/
    int q;
    if (p < r - 1) {

        /*Determinação do valor de q, muda a cada recursão*/
        q = (p + r) / 2;

        /*Nova recursão, irá resultar na ordenação dos termos entre p e q*/
        mergesort(p, q, capivaras);

        /*Nova recursão, irá resultar na ordenação dos termos entre q e r*/
        mergesort(q, r, capivaras);

        /*Chamada da função intercala, incubida de fazer a intercalação dos termos*/
        /*dentro do vetor, ná prática é ela que realmente os ordena*/
        intercala(p, q, r, capivaras);

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

    /*Declaração do vetor que contém todas as capivaras competidores, assim como seu número na fila e*/
    /*total de ultrapassagens já realizadas*/
    capivara capivaras[total_de_capivaras];

    /*A partir da quantidade de capivaras competidoras devemos atribuir o número de largada a cada uma delas,*/
    /*de 1 à total_de_capivaras. Assim como, atribuir o valor 0 a suas ultraspassagens para que no futuro*/
    /*possamos utilizar o operador ++ para agregar valor sempre que tais realizarem uma ultrapassagem*/
    for(int contador = 0; contador < total_de_capivaras; contador++) {
        capivaras[contador].numero = contador + 1;
        capivaras[contador].ultrapass = 0;
    }

    /*While responsável por receber as capivaras que caparam de realizar uma ultrapassagem*/
    while(scanf("%d", &ultrapassagem_atual) != EOF) {

        /*For incubido de procurar a capivara que realizou a ultrapassagem dentro do vetor de capivaras*/
        for(int contador = 0; contador < total_de_capivaras; contador++) {

            /*Este if verifica se na posição contador do vetor capivaras está a capivara que realizou a ultrapassaem*/
            if(capivaras[contador].numero == ultrapassagem_atual) {


                /*Se sim, o valor de ultrapassagens é agregado em 1 e as capivaras são trocadas de posição dentro do vetor*/

                capivaras[contador].ultrapass++;

                /*A capivara que ultrapassou assume a posição da que foi ultrapassada e a ultrapassada assume a da que ultrapassou*/

                troca(&capivaras[contador], &capivaras[contador - 1]);

            }
        }
    }

    /*Como dito anteriomente, p sempre vale recebe o indice da primeira posição que será ordenado, nesse caso é 0*/
    p = 0;

    /*Da mesma for, r recebe o valor da última posição do vetor que será ordenado.*/
    /*Nesse caso, total_de_capivaras - 1, porque um vetor sempre inicia da posição 0*/
    r = total_de_capivaras - 1;

    /*Este laço realiza a exibição da ordem de chegada das capivaras, iniciando na posição 0, contador, e*/
    /*indo até total_de_capivaras que é o limite do vetor*/
    for(int contador = 0; contador < total_de_capivaras; contador++) {

        /*O seguinte if e else, servem para que não haja um " " após a exbição da última capivara*/
        if (contador + 1 < total_de_capivaras) {
            printf("%d ", capivaras[contador].numero);
        }
        else {
            printf("%d", capivaras[contador].numero);
        }

    }
    /*Pula uma linha entre a ordem que as capivaras chegaram e a ordem de classificação dentro da competição*/
    printf("\n");

    /*Chama o método de ordenação, passando o p (0), r(total_de_capivaras) e capivaras (Vetor de capivaras)*/
    mergesort(p, r, capivaras);


    /*Este laço realiza a exibição da ordem de classificação das capivaras, iniciando na posição 0, contador, e*/
    /*indo até total_de_capivaras que é o limite do vetor*/
    for(int contador = 0; contador < total_de_capivaras; contador++) {

        /*O seguinte if e else, servem para que não haja um " " após a exbição da última capivara*/
        if (contador + 1 < total_de_capivaras) {
            printf("%d ", capivaras[contador].numero);
        }
        else {
            printf("%d", capivaras[contador].numero);
        }

    }

}


