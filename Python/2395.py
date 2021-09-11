def main():
    conteiner = input().split()
    navio = input().split()
    medidas_gerais = []
    resposta = 1
    correto = False
    
    for i in range(0, 3):
        conteiner[i] = int(conteiner[i])
        navio[i] = int(navio[i])
        if conteiner[i] > navio[i]:
            correto = True
            break
        
        else:
            medidas_gerais.append(navio[i]//conteiner[i]) 
            
    if not correto:
        for i in range (0, 3):
            resposta = resposta * medidas_gerais[i] 
            
        print(resposta)
            
    else:
        print(0)
        

main()
