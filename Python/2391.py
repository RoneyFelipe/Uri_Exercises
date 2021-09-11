def main():
    n = int(input())
    sequencia = input().split()
    total_pas = 0
    atual_num = 0
    anterior_num = 0
    sequencia_pa = 0
    sequencia_num = 0
    
    for i in range(0, n):
        atual_num = int(sequencia[i])
        
        if sequencia_num == 1:
            sequencia_pa = atual_num - anterior_num
            sequencia_num = 0
            
        elif sequencia_pa != (atual_num - anterior_num):
            sequencia_num = 1
            total_pas = total_pas + 1
            
        anterior_num = atual_num
        
    print(total_pas)
            
main()
