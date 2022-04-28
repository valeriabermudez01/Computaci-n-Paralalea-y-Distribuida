#cython: language_level=3

def fibonacci(n):
	a = 0.0
	b = 1.0
	for i in range(n):
		a,b = a +b,a
	return a 
