def main():
    n, voltas = map(int, input().split())
    carros = []
    temp_aux = 0
    
    for i in range(0, n):
        tempos = input().split()
        for c in range(0, voltas):
            temp_aux += int(tempos[c])
            
        carros.append(temp_aux)
        temp_aux = 0
    
    carros_ordenado = carros[0:len(carros)+1]
    
    for aux in range(0, len(carros_ordenado)):
        for cont in range(0, len(carros_ordenado)):
            if carros_ordenado[aux] < carros_ordenado[cont]:
                aux_max = carros_ordenado[aux]
                carros_ordenado[aux] = carros_ordenado[cont]
                carros_ordenado[cont] = aux_max
    
    for aux in range(0,3):
        for cont in range(0, len(carros_ordenado)): 
            if carros_ordenado[aux] == carros[cont]:
                print(cont+1)
            

main()
