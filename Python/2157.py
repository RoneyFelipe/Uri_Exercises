def main():
    n = int(input())
    crescente = ''
    descrecente = ''
    resultado = 0
    
    for i in range(0, n):
        inicio, fim = map(int, input().split())
        cont = fim
        
        for i in range (inicio, fim + 1):
            crescente = crescente + str(i)
            
        while cont >= inicio :
            aux = (str(cont))[::-1]
            descrecente = descrecente + aux
            
            cont = cont - 1
            
        resultado = crescente + descrecente
        
        print(resultado)
        resultado, crescente, descrecente = '', '', ''
        
    
main()
