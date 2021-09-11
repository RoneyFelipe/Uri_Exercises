def main():
    animal = input()
    animal2 = input()
    animal3 = input()

    if animal == "vertebrado":
        if animal2 == "ave":
            if animal3 == "carnivoro":
                print("aguia")
        
            elif animal3 == "onivoro":
                print("pomba")

        if animal2 == "mamifero":
            if animal3 == "onivoro":
                print("homem")
        
            elif animal3 == "herbivoro":
                print("vaca")

    elif animal == "invertebrado":
        if animal2 == "inseto":
            if animal3 == "hematofago":
                print("pulga")
        
            elif animal3 == "herbivoro":
                print("lagarta")

        if animal2 == "anelideo":
            if animal3 == "hematofago":
                print("sanguessuga")
        
            elif animal3 == "onivoro":
                print("minhoca")

main()
