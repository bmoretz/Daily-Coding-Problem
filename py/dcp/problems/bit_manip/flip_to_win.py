'''Flip Bit to Win.

You have an integer and you can flip exactly one bit from 0 to 1.

Write code to find the length of the longest sequence of 1s you could create.

EXAMPLE:

Input: 1775 (or: 11011101111)
Output: 8
'''

'''
brute force solution, try all combinations.
O(B^2)
'''

from .to_bin import to_binary

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