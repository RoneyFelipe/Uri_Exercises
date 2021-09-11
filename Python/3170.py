import math
def main():
    quantidade_bolinhas = int(input())
    quantidade_galhos = int(input())
    quantidade_comprar = math.floor((quantidade_galhos / 2)) - quantidade_bolinhas
    if quantidade_comprar <= 0:
        print("Amelia tem todas bolinhas!")

    else:
        print("Faltam %i bolinha(s)" % quantidade_comprar)

main()
