from bitarray import bitarray
from decimal import Decimal

'''Flip Bit to Win.

You have an integer and you can flip exactly one bit from 0 to 1.

Write code to find the length of the longest sequence of 1s you could create.

EXAMPLE:

Input: 1775 (or: 11011101111)
Output: 8

'''

def flip_bit(num):
    
    def to_binary(num):

        def greatest_divisor(num):

            power = 0

            while (2**power)/num <= 1:
                power += 1
            
            return power - 1

        power = greatest_divisor(num)
        binary = []

        while power >= 0:
            
            div = 2**power

            rem = num/div

            if rem >= 1:
                binary.append(1)
                num = num % div
            else:
                binary.append(0)

            power -= 1

        return binary

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

    print(''.join([str(e) for e in binary]))

    candidates = [index for index, element in enumerate(binary) if element == 0]

    # handle case of all 1's
    if candidates == []:
        return len(binary)

    max_len = 0

    for path in candidates:
        max_len = max(max_len, seq(binary, path))

    return 1 + max_len

flip = flip_bit(1775)

print(flip)