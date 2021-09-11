def main():
    n = int(input())
    resposta = ''
    ultima_entrada = 0
    aux = 0
    teclado = [["A","B","C","0"],["D","E","F","0"],["G","H","I","0"],["J","K","L","0"],["M","N","O","0"],["P","Q","R", "S"],["T","U","V","0"],["W","X","Y", "Z"]]

    for c in range(0, n):
        palavra = input()
        
        for i in range(0, len(palavra)):
            
            for t in range(0,8):
            
                for e in range(0, 4):
    
                    if palavra[i].upper() == teclado[t][e]:
                        
                        tecla = teclado[t]
                        
                        if palavra[i] == tecla[0].upper() or palavra[i] == tecla[1].upper() or palavra[i] == tecla[2].upper() or palavra[i] == tecla[3].upper():
                            resposta += "#" + (str(t+2) * (e+1))
                            aux = 0
                        
                        else:
                            if ultima_entrada == teclado[t] and aux != 1:
                                resposta += "*" + (str(t+2) * (e+1))
                            
                            else:
                                resposta += str(t+2) * (e+1)
                                aux = 0
                                
                            
                        ultima_entrada = teclado[t]
                    
            if palavra[i] == " ":
                resposta = resposta + "0"
                aux = 1
            
        print(resposta)
        resposta = ''
        ultima_entrada = 0
    
main()
