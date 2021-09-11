def main():
    p1_código, p1_quantidade, p1_preco = input().split()
    p2_código, p2_quantidade, p2_preco = input().split()
    valor_total = (p1_quantidade) * (p1_preco) + (p2_quantidade) * (p2_preco)
    print("VALOR A PAGAR: R$ %.2f" % valor_total)

main()
