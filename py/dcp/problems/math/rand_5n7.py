"""
Rand7 from Rand5.

Implement a method rand7() given rand5(). That is, given a
method that generates a random number between 0 and 4 (inclusive),
write a method that generates a random number between 0 and 6
(inclusive).
"""

from random import randrange

def rand5():
    return randrange(0, 5)

"""
rand7 1

simple / deterministic, does not generate a uniform
distribution though.
"""

def rand7_1():
    a, b = rand5(), rand5()
    n = (a + b) % 7
    return n

"""
rand7 2

somewhat more complicated, and also non-deterministic (unknown loops
before we get a result, but it will complete). we generate a number
between 0-8 using rand5, then scale it by 5. we discard anything >
20 (21 values inc zero), and then mod the result to put it in the 
range. Produces uniform range.
"""

def rand7_2():
    
    while True:
        a, b = rand5(), rand5()
        n = 5 * a + b

        if n < 21:
            return n % 7

"""
rand7 3

most complicated and also non-deterministic. Generate the even
numbers between 0 and 9 (2*rand5), and then an additional rand
that must be between 0 and 3 (to maintain the distribution),
then mod b to get a 1 or a zero. finally, n will be in range 0-9,
so we discard > 7.
"""
def rand7_3():

    while True:
        a, b = 2 * rand5(), rand5()

        if b != 4:
            r = b % 2
            n = a + r
            if n < 7:
                return n