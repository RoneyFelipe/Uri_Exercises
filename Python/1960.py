def main():
    paginas = int(input())
    resposta_c = ''
    resposta_d = ''
    resposta_u = ''
    unidade = paginas%10
    dezena = paginas%100//10
    centena = paginas//100
    
    if centena >= 5:
        
        if centena > 8:
            resposta_c = resposta_c + "M"
            for i in range(8, centena):
                resposta_c = "C" + resposta_c
                
        else :
            resposta_c = resposta_c + "D"
            for i in range(5, centena):
                resposta_c = resposta_c + "C"
                
    else:
        if centena > 3:
            resposta_c = resposta_c + "D"
            for i in range(3, centena):
                resposta_c = "C" + resposta_c
                
        else:
            for i in range(0, centena):
                resposta_c = resposta_c + "C"
                
                
    if dezena >= 5:
        
        if dezena > 8:
            resposta_d = resposta_d + "C"
            for i in range(8, dezena):
                resposta_d = "X" + resposta_d
                
        else :
            resposta_d = resposta_d + "L"
            for i in range(5, dezena):
                resposta_d = resposta_d + "X"
                
    else:
        if dezena > 3:
            resposta_d = resposta_d + "L"
            for i in range(3, dezena):
                resposta_d = "X" + resposta_d
                
        else:
            for i in range(0, dezena):
                resposta_d = resposta_d + "X"
                
                
    if unidade >= 5:
        
        if unidade > 8:
            resposta_u = resposta_u + "X"
            for i in range(8, unidade):
                resposta_u = "I" + resposta_u
                
        else :
            resposta_u = resposta_u + "V"
            for i in range(5, unidade):
                resposta_u = resposta_u + "I"
                
    else:
        if unidade > 3:
            resposta_u = resposta_u + "V"
            for i in range(3, unidade):
                resposta_u = "I" + resposta_u
                
        else:
            for i in range(0, unidade):
                resposta_u = resposta_u + "I"
                
            
    print(resposta_c+resposta_d+resposta_u)
            
main()
