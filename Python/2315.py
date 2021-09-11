from datetime import date

def main():
    dn, mn = map(int, input().split())
    df, mf = map(int, input().split())
    
    ano_atual = date.today()
    
    ano_atual = ano_atual.year  
    
    cal_data = date(ano_atual, mf, df) - date(ano_atual, mn, dn)         
    
    dias_restantes = cal_data.days
    
    print(dias_restantes)
    
main()
