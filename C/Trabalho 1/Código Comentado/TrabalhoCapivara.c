#include <stdio.h>

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

/*Fun��o respons�vel por receber duas capivaras e inverter seus valores dentro do array_de_capivaras*/
/*Ao fim, capivara_1 ter� o valor de capivara_2 e capivara_2 ter� o valor de capivara_1*/
void troca(capivara *capivara_1, capivara *capivara_2){

    capivara aux_capivara = *capivara_1;
    *capivara_1 = *capivara_2;
    *capivara_2 = aux_capivara;

}


void intercala(int p, int q, int r, capivara *array_de_capivaras) {

    /*i, j e k ir�o controlar as posi��es que ser�o intercaladas*/
    /*i e j do array_de_capiravas e k do vetor auxiliar (w)*/
    int i, j, k;

    /*Vetor auxiliar para ordena��o por intercala��o,*/
    /*No final, ele ser� copiado inteiramente para o vetor de capivaras pois auxiliar_de_capivaras estar� ordenado*/
    capivara auxiliar_de_capivaras[r+1];

    /*i recebe p, primeira posi��o do array_de_capiravas*/
    i = p;

    /*i recebe q, posi��o no meio do array_de_capiravas*/
    j = q;

    /*k come�a em zero pois ele � contador de auxiliar_de_capivaras*/
    /*E nele os valores ser�o ordenados*/
    k = 0;

    /*Este while ser� executado enquanto i, contador que vai da primeira posi��o da primeira parte*/
    /*do array_de_capivaras at� q (�ndice da �ltima posi��o da primeira parte do array).*/
    /*Assim como, enquanto j, contador que vai da primeira posi��o da segunda parte do array_de_capivaras*/
    /*at� r (�ndice da �ltima posi��o da segunda parte do array).*/

    while (i < q && j < r) {

        /*Quando a quantidade de ultrapassagens em array_de_capiravas[i] == array_de_capiravas[j], */
        /*devemos ordenar via o n�mero na fila de largada.*/
        if (array_de_capivaras[i].ultrapass == array_de_capivaras[j].ultrapass) {


            /*Desse modo, caso o n�mero na fila de largada de array_de_capivaras[j] seja menor que em array_de_capivaras[i],*/
            /*auxiliar_de_capivaras recebe array_de_capivaras[j]*/
            if(array_de_capivaras[i].numero > array_de_capivaras[j].numero) {

                auxiliar_de_capivaras[k] = array_de_capivaras[j];

                j++;
            }

            /*Desse modo, caso o n�mero na fila de largada de array_de_capivaras[i] seja menor que*/
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


        /*Se array_de_capivaras[i] n�o � igual ou maior que array_de_capivaras[j], ela s� pode ser menor.*/
        /*Ent�o, auxiliar_de_capivaras[k] recebe array_de_capivaras[j]*/

        else {
            auxiliar_de_capivaras[k] = array_de_capivaras[j];
            j++;
        }

        /*O k � incrementado pois auxiliar_capivaras j� recebeu o valor ordenado nessa posi��o.*/
        k++;
    }

    /*Caso o intervalo de p � q - 1 seja maior que de q � r - 1, os termos restantes de*/
    /*p � q-1 devem ser movidos para auxilixar_de_capivaras*/
    while (i < q) {
        auxiliar_de_capivaras[k] = array_de_capivaras[i];
        i++;
        k++;
    }

    /*Caso o intervalo de q � r - 1 seja maior que de p � a - 1, os termos restantes de*/
    /*q � r - 1 devem ser movidos para auxilixar_de_capivaras*/
    while (j < r) {
        auxiliar_de_capivaras[k] = array_de_capivaras[j];
        j++;
        k++;
    }

    /*Copia os termos ordenados que est�o em auxiliar_capivaras para o array_de_capivaras*/
    for (i = p; i < r; i++)
        array_de_capivaras[i] = auxiliar_de_capivaras[i-p];

}

/*Fun��o respons�vel por ordenar o vetor de capivaras*/
void mergesort(int p, int r, capivara *array_de_capivaras) {

    /*A vari�vel q � incubida de dizer at� qual posi��o a primeira parte do array_de_capivaras vai.*/
    /*Da mesma forma, determinar em qual posi��o inicia a segunda parte do array_de_capivaras.*/
    /*Com isso, a fun��o intercala ir� realizar a quebra do array_de_capivaras at� que seja poss�vel*/
    /*analisar apenas duas ou tr�s posi��es por vez. Lembrando que a fun��o mergesorte � uma fun��o recursiva,*/
    /*ent�o ser� repetida algumas vezes, sempre modificando o valor de q.*/

    int q;
    if (p < r - 1) {

        /*Determina��o do valor de q, muda a cada recurs�o*/
        q = (p + r) / 2;

        /*Nova recurs�o, ir� resultar na ordena��o dos termos entre p e q*/
        mergesort(p, q, array_de_capivaras);

        /*Nova recurs�o, ir� resultar na ordena��o dos termos entre q e r*/
        mergesort(q, r, array_de_capivaras);

        /*Chamada da fun��o intercala, incubida de fazer a intercala��o dos termos*/
        /*dentro do vetor, na pr�tica � ela que realmente os ordena*/
        intercala(p, q, r, array_de_capivaras);

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

    /*Declara��o do vetor que cont�m todas as capivaras competidoras, assim como seu n�mero na fila e*/
    /*total de ultrapassagens j� realizadas*/
    capivara array_de_capivaras[total_de_capivaras];

    /*A partir da quantidade de capivaras competidoras devemos atribuir o n�mero de largada a cada uma delas,*/
    /*de 1 � total_de_capivaras. Assim como, atribuir o valor 0 a suas ultraspassagens para que no futuro*/
    /*possamos utilizar o operador ++ para agregar valor sempre que tais realizarem uma ultrapassagem*/
    for(int contador = 0; contador < total_de_capivaras; contador++) {
        array_de_capivaras[contador].numero = contador + 1;
        array_de_capivaras[contador].ultrapass = 0;
    }

    /*While respons�vel por receber as capivaras que caparam de realizar uma ultrapassagem*/
    while(scanf("%d", &ultrapassagem_atual) != EOF) {

        /*For incubido de procurar a capivara que realizou a ultrapassagem dentro do array_de_capivaras*/
        for(int contador = 0; contador < total_de_capivaras; contador++) {

            /*Este if verifica se na posi��o contador, do array_de_capivaras, est� a capivara que realizou a ultrapassaem*/
            if(array_de_capivaras[contador].numero == ultrapassagem_atual) {


                /*Se sim, o valor de ultrapassagens (ultrapass) � agregado em 1 e */
                /*as capivaras s�o trocadas de posi��o dentro do array*/

                array_de_capivaras[contador].ultrapass++;

                /*A capivara que ultrapassou assume a posi��o da que foi ultrapassada e a ultrapassada assume a da que ultrapassou*/

                troca(&array_de_capivaras[contador], &array_de_capivaras[contador - 1]);

            }
        }
    }

    /*Como dito anteriomente, p sempre vai recebe o indice da primeira posi��o do*/
    /*array que ser� ordenado, nesse caso � 0*/
    p = 0;

    /*Da mesma forma, r recebe o valor da �ltima posi��o do array que ser� ordenado.*/
    /*Nesse caso, total_de_capivaras - 1, porque um vetor sempre inicia da posi��o 0*/
    r = total_de_capivaras - 1;

    /*Este la�o realiza a exibi��o da ordem de chegada das capivaras, iniciando na posi��o 0, contador, e*/
    /*indo at� total_de_capivaras que � o limite do array*/
    for(int contador = 0; contador < total_de_capivaras; contador++) {

        /*O seguinte if e else, servem para que n�o haja um " " ap�s a exbi��o da �ltima capivara*/
        if (contador + 1 < total_de_capivaras) {
            printf("%d ", array_de_capivaras[contador].numero);
        }
        else {
            printf("%d", array_de_capivaras[contador].numero);
        }

    }
    /*Pula uma linha entre a ordem que as capivaras chegaram e a ordem de classifica��o dentro da competi��o*/
    printf("\n");

    /*Chama o m�todo de ordena��o, passando o p (0), r(total_de_capivaras) e o array_de_capivaras)*/
    mergesort(p, r, array_de_capivaras);


    /*Este la�o realiza a exibi��o da ordem de classifica��o das capivaras, iniciando na posi��o 0, contador, e*/
    /*indo at� total_de_capivaras que � o limite do vetor*/
    for(int contador = 0; contador < total_de_capivaras; contador++) {

        /*O seguinte if e else, servem para que n�o haja um " " ap�s a exbi��o da �ltima capivara*/
        if (contador + 1 < total_de_capivaras) {
            printf("%d ", array_de_capivaras[contador].numero);
        }
        else {
            printf("%d", array_de_capivaras[contador].numero);
        }

    }

}


