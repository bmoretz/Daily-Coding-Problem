from bitarray import bitarray
from decimal import Decimal

'''Flip Bit to Win.

You have an integer and you can flip exactly one bit from 0 to 1.

Write code to find the length of the longest sequence of 1s you could create.

EXAMPLE:

Input: 1775 (or: 11011101111)
Output: 8

'''

from problems.bit_manip import to_binary

def flip_bit(num):
    
    if num == None: return None

    binary = to_binary(num)

    counter, n = 0, len(binary)
    gaps = []

    for index in range(n + 1):

        if index < n and binary[index] == 1:
            counter += 1
        else:
            gaps.append(counter)
            counter = 0
    
    if len(gaps) == 1: return gaps[0]

    max_gap = 0

    for start in range(len(gaps) - 1):
        
        end = start + 1

        max_gap = max( gaps[start] + gaps[end], max_gap)

    return max_gap + 1

flip = flip_bit(13331)

print(flip)