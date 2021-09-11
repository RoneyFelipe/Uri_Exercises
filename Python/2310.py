from typing import ByteString


def main():
    n = int(input())
    Pac = 0
    Pat = 0
    Pbc = 0
    Pbt = 0
    Psc = 0
    Pst = 0
    
    for i in range(0, n):
        nome = input()
        St, Bt, At, = map(int, input().split())
        Sc, Bc, Ac =  map(int, input().split())
        
        Pac = Pac + Ac
        Pat = Pat + At
        
        Pbc = Pbc + Bc
        Pbt = Pbt + Bt
        
        Psc = Psc + Sc
        Pst = Pst + St
    
    pa = (Pac*100)/Pat
    pb = (Pbc*100)/Pbt
    ps = (Psc*100)/Pst
    
    print("Pontos de Saque: {:0.2f} %.".format(ps))
    print("Pontos de Bloqueio: {:0.2f} %.".format(pb))
    print("Pontos de Ataque: {:0.2f} %.".format(pa))
    
main()
