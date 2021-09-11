def main():
    altura, quantidade = map(int, input().split())
    degraus = input().split()
    continuar = 0
    
    for i in range(0, quantidade):
        degraus[i] = int(degraus[i])
        
    for i in range(0, quantidade-1):
        if (degraus[i] + altura) < degraus[i+1]:
            continuar = -1
            break
        
        elif (degraus[i] + altura) > degraus[i+1]:
            if (degraus[i] - degraus[i+1]) > altura:
                continuar = -1
                break
            
            else:
                continuar = continuar + 1
            
    if continuar == -1:
        print("GAME OVER")
        
    else:
        print("YOU WIN")
        
main()
