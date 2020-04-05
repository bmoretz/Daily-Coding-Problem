'''Next Number.

Given a positive integer, print the next smallest and the next largest
number that have the same number of 1 bits in their binary representation.
'''

from problems.bit_manip import to_binary

def next_number(num):

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
        elif max_one == 0:
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


t = next_number(57)

print(t)