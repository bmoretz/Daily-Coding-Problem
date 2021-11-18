"""First missing.

Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.
"""

'''O(N) time and O(N) space.'''

def first_missing1(values):

    n = len(set(values))

    canidates = range(min(values), n - 1)
    canidates = list(reversed(canidates))

    for v in values:
        
        if v in canidates:
            canidates.remove(v)

    return canidates[0] if canidates else n


'''O(N) time O(N) space.'''
def first_missing2(values):

    s, counter = set(values), 1

    while counter in s:
        counter += 1

    return counter