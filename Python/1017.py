def main():
    tempo_gasto = int(input())
    velocidade_media = int(input())
    distancia = tempo_gasto * velocidade_media
    combustivel_gasto = distancia / 12
    print("%.3f" % combustivel_gasto)

main()
