def main():
    valor_inserido = float(input())
    notas = [100, 50, 20, 10, 5, 2]
    moedas = [1, 0.50, 0.25, 0.10, 0.05, 0.01]
    
    print("NOTAS:")
    for nota in notas:
        quantidade_de_notas = int(valor_inserido / nota)
        valor_inserido = valor_inserido - quantidade_de_notas * nota
        print("%i nota(s) de R$ %.2f" % (quantidade_de_notas, nota))

    print("MOEDAS:")
    for moeda in moedas:
        quantidade_de_moedas = int(round(valor_inserido,2) / moeda)
        valor_inserido = valor_inserido - quantidade_de_moedas * moeda
        print("%i moeda(s) de R$ %.2f" % (quantidade_de_moedas, moeda))
    
main()
