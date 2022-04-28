from distutils.core import setup,Extension
from Cython.Build import cythonize

exts=(cythonize("programa.pyx"))
setup(ext_modules=exts)
