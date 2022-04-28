import timeit
from fibonacciFunction import fibonacci
from fibonacciFunctionCy import fibonacci
from fibonacciFunctionCyOP import fibonacci

pyTiempo = timeit.timeit('''fb.fibonacci(100000)''',setup = 'import fibonacciFunction as fb',number = 100)

cyTiempo = timeit.timeit('''fbCy.fibonacci(100000)''',setup = 'import fibonacciFunction as fbCy',number = 100)


cyOPTiempo = timeit.timeit('''fbCyOP.fibonacci(100000)''',setup = 'import fibonacciFunction as fbCyOP',number = 100)

print(f"Cython es {pyTiempo/cyTiempo} más rápido\n")
print(f"CythonOP es {pyTiempo/cyOPTiempo} más rápido\n")

