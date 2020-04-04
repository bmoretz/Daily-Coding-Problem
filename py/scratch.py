from bitarray import bitarray
from decimal import Decimal

'''Flip Bit to Win.

You have an integer and you can flip exactly one bit from 0 to 1.

Write code to find the length of the longest sequence of 1s you could create.

EXAMPLE:

Input: 1775 (or: 11011101111)
Output: 8

'''

def merge_sort(values):
    n = len(values)

    if n <= 2:
        if n == 1:
            return values[0]
        elif values[0] <= values[1]:
            return [values[0], values[1]]
        else:
            return [values[1], values[0]]

    mid = int(n/2)

    left = values[:mid]
    left = merge_sort(left)

    right = values[mid:]
    right = merge_sort(right)

    left_ptr, right_ptr = 0, 0

    result = []

    for index in range(n):

        if left_ptr == len(left):
            # left set empty, fill from right
            while right_ptr < len(right):
                result += [right[right_ptr]]
                right_ptr += 1

        elif right_ptr == len(right):
            # right set empty, fill from left
            while left_ptr < len(left):
                result += [left[left_ptr]]
                left_ptr += 1

        # take min element from both sides
        elif left[left_ptr] <= right[right_ptr]:
            result += [left[left_ptr]]
            left_ptr += 1
        else:
            result += [right[right_ptr]]
            right_ptr += 1

    return result

values = [5, 4, 1, 8, 7, 2, 6, 3]

msort = merge_sort(values)

print(values)