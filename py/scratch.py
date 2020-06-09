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

a, b = 9101, 43

result = bin_add(a, b)

print(result)
