from distutils.core import setup,Extension
from Cython.Build import cythonize

exts=(cythonize("fibonacciFunctionCyOP.pyx"))
setup(ext_modules=exts)
