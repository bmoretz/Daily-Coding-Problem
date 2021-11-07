'''Smallest Difference.

Given two arrays of integers, compute the pair of values (one value in each array)
with the smallest (non-negative) difference. Return the difference.

EXAMPLE:

Input: {1, 3, 15, 11, 2}, {23, 127, 235, 19, 8}
Output: 3. That is, the pair (11, 8)
'''

''' O(n*m) solution, brute force.'''
def smallest_difference1(arr1, arr2):
    
    if arr1 == None or arr2 == None: return None

    deltas = []

    for j in arr1:
        for k in arr2:

            if k - j >= 0:
                deltas += [(j, k, k - j)]

            if j - k >= 0:
                deltas += [(j, k, j - k)]

    result = sorted(deltas, key=lambda x: x[2])

    return result[0] if len(result) > 0 else None

'''O((n + m)log(n + m)) solution'''
def smallest_difference2(arr1, arr2):

    if arr1 == None or arr2 == None: return None

    combined = []

    # pairs of element value/arr index
    for j in arr1: combined += [(j, 1)]
    for k in arr2: combined += [(k, 2)]

    # sort to push elements with similar values together
    combined = sorted(combined, key=lambda x: (x[0], x[1]))

    delta = []
    
    for index in range(1, len(combined)):

        j, k = combined[ index ], combined[ index - 1]

        # must be in different lists
        if j[1] != k[1]:
            
            u, v = j[0], k[0]

            # add only positive deltas

            if u - v >= 0:
                delta += [(u, v, u - v)]

            if v - u >= 0:
                delta += [(v, u, v - u)]
    
    # smallest delta
    delta = sorted(delta, key=lambda x: x[2])

    return delta[0] if len(delta) > 0 else None