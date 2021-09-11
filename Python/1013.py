def main():
    A, B, C = input().split()
    A, B, C = int(A), int(B), int(C)
    maior1 = (A + B + abs(A-B)) / 2
    maior2 = (maior1 + C + abs(maior1-C)) / 2
    print("%i eh o maior" % maior2)

main()
