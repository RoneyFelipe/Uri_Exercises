def main():
    A, B, C = input().split()
    A = int(A)
    B = int(B)
    C = int(C)
    resultado_1 = (A + B + abs(A - B)) / 2
    resultado_final = (resultado_1 + C + abs(resultado_1 - C)) / 2 
    print("%i eh o maior" % resultado_final)

main()
