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

'''Flip Bit to Win.

You have an integer and you can flip exactly one bit from 0 to 1.

Write code to find the length of the longest sequence of 1s you could create.

EXAMPLE:

Input: 1775 (or: 11011101111)
Output: 8
'''

'''
helper for flip bit

O(log2 B) run-time, O(log2 B) space for the binary representation
'''
from math import log2, ceil

def to_binary(num):

    power = ceil(log2(num))
    binary = []

    while power >= 0:
        
        div = 2**power

        if len(binary) == 0 and div > num:
            power -= 1
            continue

        rem = num/div

        if rem >= 1:
            binary.append(1)
            num = num % div
        else:
            binary.append(0)

        power -= 1

    return binary

'''
brute force solution, try all combinations.
O(B^2)
'''
def flip_bit1(num):

    def seq(binary, index):

        count = 0

        left = binary[:index]
        
        while left and left.pop() == 1:
            count += 1

        right = binary[index + 1:]

        while right and right[0] == 1:
            right = right[1:]
            count += 1

        return count

    if num == None: return None

    binary = to_binary(num)
    candidates = [index for index, element in enumerate(binary) if element == 0]

    # handle case of all 1's
    if candidates == []:
        return len(binary)

    max_len = 0

    for path in candidates:
        max_len = max(max_len, seq(binary, path))

    return 1 + max_len

'''
O(B) run-time, O(1) space for the bit flip
'''
def flip_bit2(num):
    
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

'''Next Number.

Given a positive integer, print the next smallest and the next largest
number that have the same number of 1 bits in their binary representation.
'''

'''
brute force approach

take the passed number, convert it to binary array

smaller number is move the largest (excluding zero)
binary digit down to the lowest non-one position

e.g.: 1010011 -> 1010010

larger number is move the smallest 1 bit up
one position. if there is not another 1 bit besides
the current bit (i.e, 64 = 1000000), then we increase
the size of the array by 1 and make this the new msb.

e.g.: 1010011 -> 1010110

binary representation is passed to a bin_to_dec function that
returns the base 10 representation.
'''
def next_number1(num):

    def bin_to_dec(binary):

        if binary == None: return None

        n = len(binary)

        result = 0

        for index in range(n):

            if binary[index] == 0:
                continue

            power = n - index - 1
            result += 2**power
        
        return result

    def next_smaller(num):
        if num <= 1: return None

        binary = to_binary(num)

        n = len(binary)
        min_one = 0

        for index in range(n - 1, 0, -1):
            if binary[index] == 1:
                min_one = index

        binary[min_one] = 0
        binary[min_one + 1] = 1

        return binary

    def next_larger(num):

        binary = to_binary(num)

        n = len(binary)
        max_one, max_zero = 0, 0
        
        for index in range(n):
            if binary[index] == 0:
                max_zero = index
            if binary[index] == 1:
                max_one = index
        
        if max_one == 0:
            binary = [1] + [0] * n
        elif max_one == 1:
            binary[max_one] = 0
            binary = [1] + binary
        else:
            binary[max_one] = 0
            binary[max_zero] = 1
            
        return binary

    if num == None: return None

    smaller = next_smaller(num)
    larger = next_larger(num)

    return (bin_to_dec(smaller),
            bin_to_dec(larger))

'''Number Swapper.

Write a function to swap a number in place (that is, without temporary variables).
'''

def number_swap(a, b):

    a = a ^ b
    b = b ^ a
    a = a ^ b

    return a, b

'''Add without plus.

Write a function that adds two numbers. You should not use + or any
arithmetic operators.
'''

def bin_add(a, b):
    from math import log2, ceil

    def get_bit(val, pos):
        
        mask = 1 << pos

        return (val & mask) == mask

    if not (a and b): return None

    base = a ^ b
    carry = (a & b) << 1
    
    positions = ceil(log2(max(a, b)))
    
    result, has_carry = 0, False

    for index in range(positions):
        
        j, k = get_bit(base, index), get_bit(carry, index)

        if j & k:
            carry <<= 1
        elif j | k:
            result |= ( 1 << index)

    return result | carry