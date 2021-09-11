def main():
    distancia = int(input())
    total_combustivel = float(input())
    consumo_km = distancia / total_combustivel
    print("%.3f km/l" % consumo_km)

main()
