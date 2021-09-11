def main():
    plano_cartersiano = [[ 0 for y in range(100) ] for x in range(100) ]
    area_total = 0
    n = int(input())
    for i in range(0,n):
        x1, x2, y1, y2 = map(int, input().split())
    
        for x in range(x1, x2):
            for y in range(y1, y2):
                if plano_cartersiano[x][y] == 0:
                    area_total = area_total + 1
                    plano_cartersiano[x][y] = 1
            
            
    print(area_total)
    
main()

