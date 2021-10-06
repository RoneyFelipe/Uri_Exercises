#include <stdio.h>
#define MAX 1000

/**************************************************
*
* Nome do(a) estudante: Roney Felipe de Oliveira Miranda
* Trabalho 1
* Professor(a): Diego Rubert
*
*/

/* Armazena informa��es de uma capivara */
typedef struct {
    int numero; /* N�mero da capivara = posi��o na largada */
    int ultrapass; /* Quantidade de ultrapassagens feitas */
} capivara;

/*Fun��o respons�vel por receber duas capivaras e inverter a posi��o de tais dentro do vetor de capivaras*/
void troca(capivara *a, capivara *b){
    capivara temp = *a;
    *a = *b;
    *b = temp;
}


void intercala(int p, int q, int r, capivara capivaras[MAX]) {

    /*i, j e k ir�o controlar as posi��es que ser�o intercaladas*/
    /*i e j do vetor capivaras e k do vetor auxiliar (w)*/
    int i, j, k;

    /*Vertor auxiliar para ordena��o por intercala��o,*/
    /*No final, ele ser� copiada inteiramente para o vetor de capivaras pois auxiliar_de_capivaras estar� ordenado*/
    capivara auxiliar_de_capivaras[MAX];

    /*i recebe p, primeira posi��o do vetor de capivaras*/
    i = p;

    /*i recebe q, posi��o no meio do vetor de capivaras*/
    j = q;

    /*k come�a em zero pois nele os valores ordenados ser�o ordenados*/
    k = 0;

    /*Este while verificada qual valor � maior entre capivaras[i].ultrapass e capivaras[j].ultrapass*/
    while (i < q && j < r) {

        /*Quando a quantidade de ultrapassagens em capiravas[i] == capiravas[j], devemos ordenar via o n�mero na fila*/
        /*de largada.*/
        if (capivaras[i].ultrapass == capivaras[j].ultrapass) {


            /*Desse modo, caso o n�mero na fila de largada de capivaras[j] seja menor que em capivaras[i],*/
            /*auxiliar_de_capivaras recebe capivaras[j]*/
            if(capivaras[i].numero > capivaras[j].numero) {

                auxiliar_de_capivaras[k] = capivaras[j];

                j++;
            }

            /*Desse modo, caso o n�mero na fila de largada de capivaras[i] seja menor que em capivaras[j],*/
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


        /*Se capivaras[i] n�o � igual ou maior que capivaras[j], ela s� pode ser menor.*/
        /*Ent�o, auxiliar_de_capivaras[k] recebe recebe capivaras[j]*/

        else {
            auxiliar_de_capivaras[k] = capivaras[j];
            j++;
        }

        /*O k � incrementado pois auxiliar_capivaras j� recebeu o valor ordenado nessa posi��o.*/
        k++;
    }

    /*Caso o intervalo de p � q - 1 seja maior que de q � r - 1, os termos restantes de*/
    /*p � q-1 devem ser movidos para auxilixar_de_capivaras*/
    while (i < q) {
        auxiliar_de_capivaras[k] = capivaras[i];
        i++;
        k++;
    }

    /*Caso o intervalo de q � r - 1 seja maior que de p � a - 1, os termos restantes de*/
    /*q � r - 1 devem ser movidos para auxilixar_de_capivaras*/
    while (j < r) {
        auxiliar_de_capivaras[k] = capivaras[j];
        j++;
        k++;
    }

    /*Copia os termos ordenados que est�o em auxiliar_capivaras para o vetor capivaras original*/
    for (i = p; i < r; i++)
        capivaras[i] = auxiliar_de_capivaras[i-p];

}

/*Fun��o respons�vel por ordenar o vetor de capivaras*/
void mergesort(int p, int r, capivara capivaras[MAX]) {

    /*A vari�vel q � incubida de dizer at� qual posi��o o vetor ser� utilizado na fun��o intercala*/
    /*Como a fun��o mergesorte � uma fun��o recursiva, o q sempre ser� diminuido at� chegar em 2.*/
    int q;
    if (p < r - 1) {

        /*Determina��o do valor de q, muda a cada recurs�o*/
        q = (p + r) / 2;

        /*Nova recurs�o, ir� resultar na ordena��o dos termos entre p e q*/
        mergesort(p, q, capivaras);

        /*Nova recurs�o, ir� resultar na ordena��o dos termos entre q e r*/
        mergesort(q, r, capivaras);

        /*Chamada da fun��o intercala, incubida de fazer a intercala��o dos termos*/
        /*dentro do vetor, n� pr�tica � ela que realmente os ordena*/
        intercala(p, q, r, capivaras);

    }
}

int main(void) {

    /*Declara��o das vari�veis que ir�o receber o total de capivaras competindo e*/
    /*a ultrapassagem que foi inserida*/
    int total_de_capivaras, ultrapassagem_atual;

    /*Vari�veis padr�es para ordena��o via merge_sort. p = 0 e r = total de posi��es do vetor que ser� ordenado*/
    int p, r;

    /*Inser��o do n�mero total de capivaras competindo*/
    scanf("%d", &total_de_capivaras);

    /*Declara��o do vetor que cont�m todas as capivaras competidores, assim como seu n�mero na fila e*/
    /*total de ultrapassagens j� realizadas*/
    capivara capivaras[total_de_capivaras];

    /*A partir da quantidade de capivaras competidoras devemos atribuir o n�mero de largada a cada uma delas,*/
    /*de 1 � total_de_capivaras. Assim como, atribuir o valor 0 a suas ultraspassagens para que no futuro*/
    /*possamos utilizar o operador ++ para agregar valor sempre que tais realizarem uma ultrapassagem*/
    for(int contador = 0; contador < total_de_capivaras; contador++) {
        capivaras[contador].numero = contador + 1;
        capivaras[contador].ultrapass = 0;
    }

    /*While respons�vel por receber as capivaras que caparam de realizar uma ultrapassagem*/
    while(scanf("%d", &ultrapassagem_atual) != EOF) {

        /*For incubido de procurar a capivara que realizou a ultrapassagem dentro do vetor de capivaras*/
        for(int contador = 0; contador < total_de_capivaras; contador++) {

            /*Este if verifica se na posi��o contador do vetor capivaras est� a capivara que realizou a ultrapassaem*/
            if(capivaras[contador].numero == ultrapassagem_atual) {


                /*Se sim, o valor de ultrapassagens � agregado em 1 e as capivaras s�o trocadas de posi��o dentro do vetor*/

                capivaras[contador].ultrapass++;

                /*A capivara que ultrapassou assume a posi��o da que foi ultrapassada e a ultrapassada assume a da que ultrapassou*/

                troca(&capivaras[contador], &capivaras[contador - 1]);

            }
        }
    }

    /*Como dito anteriomente, p sempre vale recebe o indice da primeira posi��o que ser� ordenado, nesse caso � 0*/
    p = 0;

    /*Da mesma for, r recebe o valor da �ltima posi��o do vetor que ser� ordenado.*/
    /*Nesse caso, total_de_capivaras - 1, porque um vetor sempre inicia da posi��o 0*/
    r = total_de_capivaras - 1;

    /*Este la�o realiza a exibi��o da ordem de chegada das capivaras, iniciando na posi��o 0, contador, e*/
    /*indo at� total_de_capivaras que � o limite do vetor*/
    for(int contador = 0; contador < total_de_capivaras; contador++) {

        /*O seguinte if e else, servem para que n�o haja um " " ap�s a exbi��o da �ltima capivara*/
        if (contador + 1 < total_de_capivaras) {
            printf("%d ", capivaras[contador].numero);
        }
        else {
            printf("%d", capivaras[contador].numero);
        }

    }
    /*Pula uma linha entre a ordem que as capivaras chegaram e a ordem de classifica��o dentro da competi��o*/
    printf("\n");

    /*Chama o m�todo de ordena��o, passando o p (0), r(total_de_capivaras) e capivaras (Vetor de capivaras)*/
    mergesort(p, r, capivaras);


    /*Este la�o realiza a exibi��o da ordem de classifica��o das capivaras, iniciando na posi��o 0, contador, e*/
    /*indo at� total_de_capivaras que � o limite do vetor*/
    for(int contador = 0; contador < total_de_capivaras; contador++) {

        /*O seguinte if e else, servem para que n�o haja um " " ap�s a exbi��o da �ltima capivara*/
        if (contador + 1 < total_de_capivaras) {
            printf("%d ", capivaras[contador].numero);
        }
        else {
            printf("%d", capivaras[contador].numero);
        }

    }

}


