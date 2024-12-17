
# include <stdio.h>
# include <stdlib.h>



int posiblesCortes(int cortes, int longitud, int demanda, int queCortes){


}

int main(){

    int cortes[5] = {4, 6, 8, 10, 12};


    return 0;
}

/*

def PosibleCambio(monedas, importe, num_monedas, queMonedas, index=0, memo=None):
    if memo is None:
        memo = {}
    if importe == 0 and num_monedas == 0:
        return True
    if importe < 0 or num_monedas < 0 or index >= len(monedas):
        return False
    if (importe, num_monedas, index) in memo:
        return memo[(importe, num_monedas, index)]

    usar_moneda = PosibleCambio(monedas, importe - monedas[index], num_monedas - 1,queMonedas, index, memo)

    if(usar_moneda):
        queMonedas.append(monedas[index])
        print(memo)
        memo[(importe, num_monedas, index)] = True
        return True

    no_usar_moneda = PosibleCambio(monedas, importe, num_monedas,queMonedas, index + 1, memo)
    memo[(importe, num_monedas, index)] = no_usar_moneda
    return no_usar_moneda


def main():
  tiposDeMonedas = [400, 600, 800, 1000, 1200]
  queMonedas=[]
  try:
    dolares=float(input("\nIngrese los dolares: "))
    importe = int(dolares*100)
    num_monedas = int(input("Ingrese la cantidad de monedas: "))
  except ValueError:
    print("\nPor favor ingrese un valor válido.\n")
    return

  monedas = PosibleCambio(tiposDeMonedas, importe,num_monedas, queMonedas)

  if monedas:
    print(f"Es posible formar ¢{importe} con {num_monedas} monedas")
    a=queMonedas.count(1)
    b=queMonedas.count(5)
    c=queMonedas.count(10)
    d=queMonedas.count(25)
    print(f"Se ocuparon {a} monedas de 1 centavo")
    print(f"Se ocuparon {b} monedas de 5 centavos")
    print(f"Se ocuparon {c} monedas de 10 centavos")
    print(f"Se ocuparon {d} monedas de 25 centavos")
  else:
    print(f"NO es posible formar ¢{importe} con {num_monedas} monedas")

if __name__ == '__main__':
    main()
*/