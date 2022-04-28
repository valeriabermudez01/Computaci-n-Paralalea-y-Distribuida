#cython: language_level=3


def fibonacci(n):
	cdef double a = 0
	cdef double b = 1
	cdef int i
	for i in range(n):
		a,b = a +b,a
	return a 
