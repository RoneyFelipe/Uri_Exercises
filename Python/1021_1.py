def main():
    valor = float(input())

    notas_100 = valor // 100
    valor = valor % 100

    notas_50 = valor // 50
    valor = valor % 50

    notas_20 = valor // 20
    valor = valor % 20

    notas_10 = valor // 10
    valor = valor % 10

    notas_5 = valor // 5
    valor = valor % 5

    notas_2 = valor // 2
    valor = valor % 2
    
    moedas = valor

    moedas_1 = moedas // 1
    moedas = moedas % 1

    moedas_050 = moedas // 0.50
    moedas = moedas % 0.50

    moedas_025 = moedas // 0.25
    moedas = moedas % 0.25

    moedas_010 = moedas // 0.10
    moedas = moedas % 0.10

    moedas_05 = moedas // 0.05
    moedas = moedas % 0.05

    moedas_01 = int(round(moedas,2) / 0.01)

    print("NOTAS:")
    print("%i nota(s) de R$ 100.00" % notas_100)
    print("%i nota(s) de R$ 50.00" % notas_50)
    print("%i nota(s) de R$ 20.00" % notas_20)
    print("%i nota(s) de R$ 10.00" % notas_10)
    print("%i nota(s) de R$ 5.00" % notas_5)
    print("%i nota(s) de R$ 2.00" % notas_2)

    print("MOEDAS:")
    print("%i moeda(s) de R$ 1.00" % moedas_1)
    print("%i moeda(s) de R$ 0.50" % moedas_050)
    print("%i moeda(s) de R$ 0.25" % moedas_025)
    print("%i moeda(s) de R$ 0.10" % moedas_010)
    print("%i moeda(s) de R$ 0.05" % moedas_05)
    print("%i moeda(s) de R$ 0.01" % moedas_01)
    
main()
