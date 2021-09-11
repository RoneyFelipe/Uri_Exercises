def main():
    pares = 0
    positivos = 0
    negativos = 0
    impares = 0
    for i in range(0,5):
        n = int(input())
        if n % 2 == 0:
            pares = pares + 1
            if n > 0:
                positivos = positivos + 1
            elif n < 0:
                negativos = negativos + 1
        
        else:
            impares = impares + 1
            if n > 0:
                positivos = positivos + 1
            elif n < 0:
                negativos = negativos + 1

    print("%i valor(es) par(es)" % pares)
    print("%i valor(es) impar(es)" % impares)
    print("%i valor(es) positivo(s)" % positivos)
    print("%i valor(es) negativo(s)" % negativos)


main()
