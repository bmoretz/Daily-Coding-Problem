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

def insertion(M, N, j, i):

    def leftshift(ba, count):
        return ba[count:] + (bitarray('0') * count)
    
    position = leftshift(N, i)

    return M | position


N = bitarray('10000000000')
M = bitarray('00000010011')

r = insertion(N, M, 6, 2)

print(r)