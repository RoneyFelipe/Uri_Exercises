def main():
    numero_funcionario = input()
    horas_trabalhadas = int(input())
    valor_por_hora = float(input())
    salario_mes = horas_trabalhadas * valor_por_hora
    print("NUMBER =",numero_funcionario)
    print("SALARY = U$ %.2f" % salario_mes)

main()
