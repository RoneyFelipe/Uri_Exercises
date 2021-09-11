def main():
    n = int(input())

    for i in range(0, n):
        ano = int(input())
        conta = 2015 - ano 
        if conta <= 0:
            conta = conta * -1
            conta = conta + 1
            print("%i A.C." % conta)

        else:
            print("%i D.C." % conta)
    
main()
