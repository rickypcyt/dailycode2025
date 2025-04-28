def esPrimo(n,i = 2): 
    if n <= 1: 
        return False
    if i * i > n:
        return True
    if n % i == 0:
        return False
    return esPrimo(n, i + 1)

if __name__ == "__main__":
    n = int(input("Ingresa un número para verificar si es primo: "))  # Pedimos el valor de n al usuario
    if esPrimo(n):
        print(f"{n} es un número primo.")
    else:
        print(f"{n} no es un número primo.")
# Los numero primos son mayores a 1. Por esos i n es menor que uno retornamos
# False
# toma dos parametros n e i. n es el numero que sea que pidamos e i es dos
# porque  es el primer divisor con el que tratamos
# comprobamos que el cuadrado de i  es mayor al numero introducido 
# si el resultado del n modulo i es cero significa que n es divisible
# entre i por lo que no es primo 

#numero primo es siempre mayor que uno
# solo es divisible por 1 y por si mismo
# dos es el unico numero primo par.
# se puede probar hasta su raiz cuadrada porque ya pues la raiz cuadrada es
# por si mismo

#literal es un bucle iterativo donde pasa tres pruebas hasta que una de esas
# sea verdadera. 

#Entonces si te preguntan como saber si un numero es primo debes decir que
#debes primero verificar si es menor o igual a 1 lo que significaria
#que no es primo. de ahi debes ver si el divisor multiplicado por si mismo o
#sea al cuadrado es igual es mayor a n en ese caso es primo

#tienes un numero n este numero puede tener divisores o sea numeros que lo
#dividen perfectamente sin dejar residuos. son lus numero que pueden dividir
#a otro sin que sobre nada.

#La raiz cuadrada nos dice el punto medio. por ejemplo el num 12 su raiz
#cuadrada es 3.46 asi que teneomos que revisar los divisores hasta el 3.
#Si no encontramos ningun divisor hasta el tres entonces es primo.


