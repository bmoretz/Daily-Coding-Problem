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