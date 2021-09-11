def main():
    n = int(input())
    soma = 1
    
    for i in range(0, n):
        senha = input().upper()
        for i in range(0, len(senha)):
            if senha[i] != "A" and senha[i] != "E" and senha[i] != "I" and senha[i] != "O" and senha[i] != "S":
                soma = soma * 2
            
            else:
                soma = soma * 3
                
        print(soma)
        soma = 1
    
main()
