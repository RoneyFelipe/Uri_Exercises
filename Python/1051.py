def main():
    salario = float(input())

    if salario <= 2000.00:
        print("Isento")

    elif salario >= 2000.01 and salario <= 3000.00:
            primeira_casa = salario - 2000.00
            imposto_primeira_casa = primeira_casa * 0.08

            imposto_total = imposto_primeira_casa
            print("R$ %.2f" % (imposto_total))

    elif salario >= 3000.01 and salario <= 4500.00:

            segunda_casa = salario - 3000.00
            imposto_segunda_casa = segunda_casa * 0.18

            primeira_casa = salario - 2000.00 - segunda_casa
            imposto_primeira_casa = primeira_casa * 0.08

            imposto_total = imposto_segunda_casa + imposto_primeira_casa

            print("R$ %.2f" % (imposto_total))

    elif salario >= 4500.00:
            terceira_casa = salario - 4500.00
            imposto_terceira_casa = terceira_casa * 0.28

            segunda_casa = salario - 3000.00 - terceira_casa
            imposto_segunda_casa = segunda_casa * 0.18

            primeira_casa = salario - 2000.00 - segunda_casa - terceira_casa
            imposto_primeira_casa = primeira_casa * 0.08

            imposto_total = imposto_terceira_casa + imposto_segunda_casa + imposto_primeira_casa

            print("R$ %.2f" % (imposto_total))


main()
