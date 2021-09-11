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
        print("Invalido")
    
    elif A == B and A == C and B == C:
        print("Valido-Equilatero")
        triangulo = 1
        
    elif A == B or B == C or C == A:
         print("Valido-Isoceles")
         triangulo = 1
         
    elif A != B and A != C and B != C:
        print("Valido-Escaleno") 
        triangulo = 1
        
    if triangulo == 1:
        if A**2 == (B**2 + C**2):
            print("Retangulo: S")
            
        else:
            print("Retangulo: N")
            
main()
