#Se importan las funciones a utilizar de las respectivas bibliotecas
from timeit import repeat
from subprocess import check_output

#Función que retorna el tiempo
def timer(arg, niter, name, module):
    stmt = "%s(%s)" % (name, arg)
    setup = "from %s import %s" % (module, name)
    time = min(repeat(stmt=stmt, setup=setup,number=niter)) / float(niter) * 1e9
    return time

#Ejecuciones con diferentes tiempos

N = 10**6
pytime_0 = timer(0, N, name='fib', module='fib')
cytime_0 = timer(0, N, name='fib', module='cyfib')
ctime_0 = float(check_output(('./cfib.x 0 %d' %N).split()))

py0speedup = 1.0
cy0speedup = pytime_0 / cytime_0
c0speedup = pytime_0 / ctime_0

N = 10**5
pytime_90 = timer(90, N, name='fib', module='fib')
cytime_90 = timer(90, N, name='fib',module='cyfib')
ctime_90 = float(check_output(('./cfib.x 90 %d' %N).split()))

py90speedup = 1.0
cy90speedup = pytime_90 / cytime_90
c90speedup = pytime_90 / ctime_90

N = 10**4
pytime_180 = timer(180, N, name='fib', module='fib')
cytime_180 = timer(180, N, name='fib',module='cyfib')
ctime_180 = float(check_output(('./cfib.x 180 %d' %N).split()))

py180speedup = 1.0
cy180speedup = pytime_180 / cytime_180
c180speedup = pytime_180 / ctime_180


N = 10**3
pytime_200 = timer(200, N, name='fib', module='fib')
cytime_200 = timer(200, N, name='fib',module='cyfib')
ctime_200 = float(check_output(('./cfib.x 200 %d' %N).split()))

py200speedup = 1.0
cy200speedup = pytime_200 / cytime_200
c200speedup = pytime_200 / ctime_200


N = 10**2
pytime_220 = timer(220, N, name='fib', module='fib')
cytime_220 = timer(220, N, name='fib',module='cyfib')
ctime_220 = float(check_output(('./cfib.x 220 %d' %N).split()))

py220speedup = 1.0
cy220speedup = pytime_220 / cytime_220
c220speedup = pytime_220 / ctime_220

data_format = "{:s},{:.0f},{:.1f},{:.0f},{:.1f},{:.0f},{:.1f},{:.0f},{:.1f},{:.0f},{:.1f}\n"


#Se escribe el csv
with open("fib0.csv", 'w') as fh:
     fh.write("Version,fib(0) runtime[ns],speedup,fib(90) runtime [ns],speedup,fib(180) runtime [ns],speedup,fib(200) runtime [ns],speedup,fib(220) runtime [ns],speedup\n")
     fh.write(data_format.format("Python", pytime_0,py0speedup, pytime_90, py90speedup, pytime_180, py180speedup, 	     pytime_200, py200speedup, pytime_220, py220speedup))
     fh.write(data_format.format("Cython", cytime_0,cy0speedup, cytime_90, cy90speedup,cytime_180, cy180speedup,
     cytime_200, cy200speedup,cytime_220, cy220speedup))
     fh.write(data_format.format("Pure C", ctime_0,c0speedup, ctime_90, c90speedup, ctime_180, c180speedup,
     ctime_200, c200speedup ,ctime_220, c220speedup))
