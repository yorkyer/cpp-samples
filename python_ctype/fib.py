import time
from ctypes import *
def fib(n):
    if n < 2:
        return n
    return fib(n-1) + fib(n-2)
s = time.time(); fib(35); e = time.time()
print("cost time: {} sec".format(e - s))
libfib = CDLL("./libfib.so")
s = time.time(); libfib.fib(35); e = time.time()
print("cost time: {} sec".format(e - s))