def main():
    #Recebendo dados
    dia_inicio = input() 
    dia_inicio = int(dia_inicio[-2] + dia_inicio[-1])
    hora_inicio, minutos_inicio, segundos_inicio = map(int, input().split(":"))
    
    dia_termino = input()
    dia_termino = int(dia_termino[-2] + dia_termino[-1])
    hora_termino, minutos_termino, segundos_termino = map(int, input().split(":"))

    #Convertendo dados para segundos
    valor_inicial = (dia_inicio * 24 * 3600) + (hora_inicio * 3600) + (minutos_inicio * 60) + segundos_inicio
    valor_final = (dia_termino * 24 * 3600) + (hora_termino * 3600) + (minutos_termino * 60) + segundos_termino

    #transformando para data
    tempo_duracao_evento = valor_final - valor_inicial

    dias_finais = tempo_duracao_evento // (24 * 3600)
    tempo_duracao_evento = tempo_duracao_evento % (24 * 3600)

    horas_finais = tempo_duracao_evento // 3600
    tempo_duracao_evento = tempo_duracao_evento % 3600

    minutos_finais = tempo_duracao_evento // 60
    tempo_duracao_evento = tempo_duracao_evento % 60

    segundos_finais = tempo_duracao_evento

    print("%i dia(s)" % dias_finais)
    print("%i hora(s)" % horas_finais)
    print("%i minuto(s)" % minutos_finais)
    print("%i segundo(s)" % segundos_finais)

main()
