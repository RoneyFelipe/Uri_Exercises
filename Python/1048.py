def main():
    salario = float(input())
    novo_salario = 0
    reajuste = 0
    percental = 0

    if salario <= 400.00:
        reajuste = salario * 0.15
        novo_salario = salario + reajuste
        percental = 15
    
    elif salario >= 400.01 and salario <= 800.00:
        reajuste = salario * 0.12
        novo_salario = salario + reajuste
        percental = 12
    
    elif salario >= 800.01 and salario <= 1200.00:
        reajuste = salario * 0.1
        novo_salario = salario + reajuste
        percental = 10

    elif salario >= 1200.01 and salario <= 2000.00:
        reajuste = salario * 0.07
        novo_salario = salario+ reajuste
        percental = 7

    elif salario >= 2000.00:
        reajuste = salario * 0.04
        novo_salario = salario + reajuste
        percental = 4

    print("Novo salario: %.2f" % novo_salario)
    print("Reajuste ganho: %.2f" % reajuste)
    print("Em percentual:",percental,"%")

main()
