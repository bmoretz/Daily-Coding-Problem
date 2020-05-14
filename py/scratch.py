'''Number Max.

Write a method that finds the maximum of two numbers. You should not use if-else or
any other comparision operator.
'''

def num_max(a, b):
    pass

from math import copysign

sign = lambda x: copysign(1, x)

a, b = 3, 5

k = sign( a - b )

j = not k

m = a*k + b*(not k)

print(m)