'''Karatsuba's algorithm.

So: what's the product of the following two 64-digit numbers?

3141592653589793238462643383279502884197169399375105820974944592

2718281828459045235360287471352662497757247093699959574966967627
'''

from math import ceil

def karatsuba(x, y):

    def zero_pad(value, digits, left = True):

        for pad in range(digits):
            if left:
                value = '0' + value
            else:
                value = value + '0'

        return value

    def split(value):
        n = len(value)

        mid =  ceil(n / 2)

        return (int(value[:mid]), int(value[mid:]))

    x, y = str(x), str(y)

    nx, ny = len(x), len(y)

    n = max(nx, ny)
    j = n//2

    if n % 2 != 0:
        j += 1

    b_pad = n - j
    a_pad = b_pad * 2

    if nx == 1 and ny == 1:
        return int(x) * int(y)

    x, y = zero_pad(x, ny - nx), zero_pad(y, nx - ny)

    a, b = split(x)
    c, d = split(y)

    p = a + b
    q = c + d

    ac = karatsuba(a, c)
    bd = karatsuba(b, d)
    pq = karatsuba(p, q)

    abcd = pq - ac - bd

    A = int(zero_pad( str(ac), a_pad, left=False))
    B = int(zero_pad( str(abcd), b_pad, left=False))
    C = bd

    return A + B + C

x = 3141592653589793238462643383279502884197169399375105820974944592
y = 2718281828459045235360287471352662497757247093699959574966967627

ret = karatsuba(x, y)

print(ret)

