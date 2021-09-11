def main():
    limite = 100
    lista = [0] * limite
    aux_max = 0
    aux = 0
    cont = 0
    posicao_maior = 0

    for i in range(0, limite):
        lista[i] = int(input())
    
    listas_desordenada = lista[0:limite + 1]

    for aux in range(0, limite):
        for cont in range(0, limite):
            if lista[aux] > lista[cont]:
                aux_max = lista[aux]
                lista[aux] = lista[cont]
                lista[cont] = aux_max
            cont = 0
    
    cont = 0
    for cont in range(0, limite):
        if lista[0] == listas_desordenada[cont]:
            posicao_maior = cont
        cont = cont + 1

    print(lista[0])
    print(posicao_maior + 1)

main()
