def main():
    n = int(input())
    for i in range(0, n):
        primeira, segunda = input().split()
        primeira, segunda = list(primeira), list(segunda)
        resultante = []
        cont = 0
        r = ''
    
        if len(primeira) < len(segunda):
            while cont < len(primeira):
                resultante.append(primeira[cont])
                resultante.append(segunda[cont])
                cont = cont + 1
        
            resultante = resultante + segunda[len(primeira):]
                
        elif len(primeira) > len(segunda):
            while cont < len(segunda):
                resultante.append(primeira[cont])
                resultante.append(segunda[cont])
                cont = cont + 1
                
            resultante = resultante + primeira[len(segunda):]
        
        else:
            while cont < len(primeira):
                resultante.append(primeira[cont])
                resultante.append(segunda[cont])
                cont = cont + 1
            
        for i in range(0, len(resultante)):
            r += resultante[i]
            
        print(r)
        resultante, cont, r = 0, 0, 0
        

main()
