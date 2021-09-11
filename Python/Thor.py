def main():
    quantidade_de_teste = int(input())
    aux = 0

    while quantidade_de_teste > aux: 
        nome, forca_do_personagem = input().split()
        
        if nome == "Thor":
            print("Y")
        else:
            print("N")
        aux = aux + 1

main()
