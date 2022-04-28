# Universidad Sergio Arboleda 
#	Fecha : 21-04-2022
#	Autor : Valeria Bermúdez
#	Materia : Parallel Computing
#	Tema : Interfaz 

#Función de Fibonacci
def fib(n):
    a, b = 0.0, 1.0
    for i in range(n):
        a, b = a + b, a
    return a

#Llamado Principal
if __name__ == '__main__':
    import sys
    arg, numiter = map(int, sys.argv[1:])
    for i in range(numiter):
        fib(arg)
