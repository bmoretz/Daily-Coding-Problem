from bitarray import bitarray

'''Insertion.

You are given two 32-bit numbers, N and M, and two bit positions, i and j.

Write a method to insert M into N such that M starts at bit j and ends at i. You
can assume that the bits j through i have enough space to fit all of M. That is,
if M = 10011, you can assume that there are at least 5 bits between j and i. You
would not, for example, have j = 3 and i = 2, because M could not fully fit
between bit 3 and 2.

EXAMPLE:

Input: N = 10000000000, M = 10011, i = 2, j = 6
Output: N = 10001001100
'''

def insertion1(M, N, j, i):

    def leftshift(ba, count):
        return ba[count:] + (bitarray('0') * count)
    
    position = leftshift(N, i)

    return M | position

'''Binary to String.

Given a real number between 0 and 1 (e.g., .72) that is passed in as
a double, print the binary representation. If the number cannot be
represented accurately in binary with at most 32 characters, print "ERROR".
'''

def binrep1(num, tol=0.00001):
    
    if num >= 1 or num <= 0: return 'ERROR'

    result, frac = '.', 0.5
    
    while num > tol:
        if len(result) >= 32:
            return 'ERROR'

 
        if num >= frac:
            result += '1'
            num -= frac
        else:
            result += '0'
        
        frac /= 2

    return result