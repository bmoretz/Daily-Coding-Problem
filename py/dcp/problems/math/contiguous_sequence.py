"""Contiguous Sequence.

You are given an array of integers (both positive and negative). Find the
contiguous sequence with the largest sum. Return the sum.

EXAMPLE:

Input: 2, -8, 3, -2, 4, -10
Output: 5 (i.e., {3, -2, 4})
"""

def contiguous_seq1(arr):

    if not arr: return None

    total, elements = 0, []

    best = []

    for index, num in enumerate(arr):

        total += num

        if total < 0:
            if len(elements) > 1:
                best = elements
            total, elements = 0, []
        else:
            elements += [num]

    if sum(best) < total:
        best = elements

    return sum(best) if best else None