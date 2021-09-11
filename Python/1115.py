def main():
    cont = [0]
    for i in cont:
        x, y = map(int, input().split())
        if x != 0 and y != 0:
            if x > 0 and y > 0:
                print("primeiro")

            elif x < 0 and y > 0:
                print("segundo")

            elif x < 0 and y < 0:
                print("terceiro")

            elif x > 0 and y < 0:
                print("quarto")
            cont.append(i)
        else:
            cont = 0

main()
