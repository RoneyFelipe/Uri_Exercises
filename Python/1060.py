def main():
    positivos = 0
    soma = 0
    for i in range(0,6):
        n = float(input())
        if n >= 0:
            soma = n + soma
            positivos = positivos + 1

    media = soma / positivos 

    print("%i valores positivos" % positivos)
    print("%.1f" % media)

main()
