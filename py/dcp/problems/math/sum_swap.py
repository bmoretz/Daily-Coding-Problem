"""Sum Swap.

Given two arrays of integers, find a pair of values (one value from
each array) that you can swap to give the two arrays the same
sum.

EXAMPLE
Input: {4, 1, 2, 1, 1, 2} and {3, 6, 3, 3}
Output: {1, 3}
"""

def sum_swap(arr1, arr2):

    if not (arr1 and arr2): return None
    
    sumA, sumB = sum(arr1), sum(arr2)

    delta = (sumB - sumA)/2

    ys, results = set(arr2), set()

    for x in arr1:

        t = x + delta

        if t in ys:
            results.add(( int(x), int(t) ))

    return results