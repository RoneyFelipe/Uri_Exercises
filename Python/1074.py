def main():
    n = int(input())
    i = 0
    
    for i in range(i, n):
        n = int(input())
        if n == 0:
            print("NULL")

        else:
            if n % 2 == 0:
                if n > 0:
                    print("EVEN POSITIVE")
                else:
                    print("EVEN NEGATIVE")
            
            else: 
                if n > 0:
                    print("ODD POSITIVE")
                else:
                    print("ODD NEGATIVE")

main() 
