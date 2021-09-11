def main():
    n = int(input())
    numeros = input().split()
    for i in range(0, n):
        numeros[i] = int(numeros[i])
        
    div2 = 0 
    div3 = 0
    div4 = 0
    div5 = 0
    
    for i in range(0, n):
        if numeros[i] % 2 == 0:
            div2 = div2 + 1
            
        if numeros[i] % 3 == 0:
            div3 = div3 + 1
            
        if numeros[i] % 4 == 0:
            div4 = div4 + 1
            
        if numeros[i] % 5 == 0:
            div5 = div5 + 1
            
    print("%i Multiplo(s) de 2" % div2)
    print("%i Multiplo(s) de 3" % div3)
    print("%i Multiplo(s) de 4" % div4)
    print("%i Multiplo(s) de 5" % div5)
    
main()
