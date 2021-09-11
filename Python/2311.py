def main():
    n = int(input())
    aux_max = 0
    soma = 0
    
    for i in range(0, n):
        nome = input()
        dificuldade = float(input())
        notas = input().split()
        
        for i in range(0, 7):
            notas[i] = float(notas[i])
            
        for aux in range(0, 7):
            for cont in range(0, 7):
                if notas[aux] > notas[cont]:
                    aux_max = notas[aux]
                    notas[aux] = notas[cont]
                    notas[cont] = aux_max
                cont = 0
    
        notas = notas[1:-1]
        
        for i in range(0, 5):
            soma = soma + notas[i]

        resultado = soma * dificuldade
        print("%s %0.2f" % (nome, resultado))
        soma = 0
    
main()
