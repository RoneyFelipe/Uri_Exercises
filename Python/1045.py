def main():
    A, B, C = map(float, input().split())
    lados = [A, B, C]
    aux = 0
    cont = 0
    for aux in range(0,3):
        for cont in range(0,3):
            if lados[aux] > lados[cont]:
                maior = lados[aux]
                lados[aux] = lados[cont]
                lados[cont] = maior
            cont = 0
            
    A, B, C = lados[0], lados[1], lados[2]
    triangulo = 0

    if A >= B + C:
        print("NAO FORMA TRIANGULO")
        triangulo = 1
    
    elif A ** 2 == B ** 2 + C ** 2:
        print("TRIANGULO RETANGULO")
        triangulo = 1
    
    elif A ** 2 > B ** 2 + C ** 2:
        print("TRIANGULO OBTUSANGULO")
        triangulo = 1

    elif A ** 2 < B ** 2 + C ** 2:
        print("TRIANGULO ACUTANGULO")
        triangulo = 1
    
    if triangulo == 1:
        if(A == B) and (B == C) and (A == C):
            print("TRIANGULO EQUILATERO")

        elif (A == B) or (A == C) or (C == B):
            print("TRIANGULO ISOSCELES")

main()
