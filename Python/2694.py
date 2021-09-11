def main():
    n = int(input())
    soma = 0
    
    for i in range(0, n):
        palavra = input()
        soma = soma + int(palavra[2:4]) + int(palavra[5:8]) + int(palavra[11:13])
        print(soma)
        soma = 0
    
main()
