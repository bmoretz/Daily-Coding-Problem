'''Factorial Zeros.

Write an algorithm which computes the number of trailing zeros in n factorial.
'''

def fact_zeros(n):

    from math import log, ceil, floor

    def factorial(n, fact={}):

        if n == 1: return 1

        if n not in fact:
            fact[n] = n * factorial(n - 1)

        return fact[n]

    if n == None: return None

    if n < 0: return -1

    fact = factorial(n)

    print(fact)

    zeros = 0

    for div in range(1, ceil(log(n, 5))):
        
        zeros += floor(n / (5**div))

    return zeros

res = fact_zeros(64)

print(res)

print(len('00000000000000000000000000000000000000000000'))
