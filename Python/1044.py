def main():
    A, B = map(int,input().split())
    Maior = max(A, B)
    Menor = min(A, B)
    respota = Maior / Menor
    if respota % 1 == 0:
        print("Sao Multiplos")
    else:
        print("Nao sao Multiplos")

main()
