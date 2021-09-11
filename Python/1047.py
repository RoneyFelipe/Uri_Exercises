def main():
    h1, m1, h2, m2 = map(int, input().split())
    horas_inicio = h1 * 3600
    minutos_inicio = m1 * 60
    tempo_inicial = horas_inicio + minutos_inicio

    horas_final = h2 * 3600
    minutos_final = m2 * 60
    tempo_final = horas_final + minutos_final

    if tempo_final > tempo_inicial:
        tempo_total = tempo_final - tempo_inicial

    else: 
        tempo_total = (tempo_final + 24 * 3600) - tempo_inicial

    horas_totais = tempo_total // 3600
    tempo_total = tempo_total % 3600 

    minutos_totais = tempo_total // 60
    tempo_total = tempo_total % 60

    print("O JOGO DUROU %i HORA(S) E %i MINUTO(S)" % (horas_totais, minutos_totais))

main()
