'''Letters and Numbers.

Given an array filled with letters and numbers, find the longest subarray
with an equal number of letters and numbers.
'''

'''
brute force O(n^2)
'''
def letters_numbers1(arr):

    def encode(arr):
        return [-1 if isinstance(e, int) else 1 for e in arr]

    def is_balanced(encoded):
        return sum(encoded) == 0

    if not arr: return -1
    
    n = len(arr)
    encoded = encode(arr)

    for end in range(n, 0, -1):
        for begin in range(n - end):
            start, stop = begin, begin + end - 1
            if is_balanced(encoded[start:stop]):
                return arr[start:stop]

'''
O(N) solution

steps:

1.) calculate a rolling sum of the number of letters and numbers seen so far
i.e.,

v: 'a', 'a', 1, 1, 'a', 1, 1
l: 1, 2, 2, 2, 3, 3, 3
n: 0, 0, 1, 2, 2, 3, 4
d: 1, 2, 1, 0, 1, 0, -1

2.) build two look-up tables, one that contains the min position of each
delta, and one that contains the max position of each delta

3.) the longest balanced sub-array is the sub-array defined by the largest
difference of the same index in the min/max look-ups.
'''
def letters_numbers2(arr) -> int:

    from collections import defaultdict

    def rolling_delta(arr):
        n = len(arr)
        deltas = [None] * n
        delta = 0

        for index, char in enumerate(arr):

            if isinstance(char, int):
                delta -= 1
            else:
                delta += 1

            deltas[index] = delta

        return deltas
    
    def min_max_positions(arr):
        mins, maxes = defaultdict(int), defaultdict(int)

        for index, value in enumerate(rolling):

            if mins[value] == 0:
                mins[value] = index
            else:
                mins[value] = min(mins[value], index)
            
            maxes[value] = max(maxes[value], index)
        
        return (mins, maxes)

    if not arr: return -1

    rolling = rolling_delta(arr)
    mins, maxes = min_max_positions(rolling)

    best_match = (0, 0)

    for val in mins:
        if val in maxes:
            delta = maxes[val] - mins[val]

            if best_match[0] <= delta:
                best_match = (delta, val)

    head, tail = mins[best_match[1]], maxes[best_match[1] - 1]

    return arr[head:tail + 1]