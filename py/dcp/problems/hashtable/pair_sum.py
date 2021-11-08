'''Paris with Sum.

Design an algorithm to find all pairs of integers within an array which sum
to a specified value.
'''

'''
O(n) solution
'''
def pair_sum1(arr, t):
    
    if not arr: return None

    lookup = defaultdict(int)

    for n in arr:
        lookup[n] += 1

    results = set()

    for index, x in enumerate(arr):
        y = t - x

        # can't sum it with itself to find a pair,
        # there needs to be at least 2 of the same
        # number if this is the case.
        if y == x and lookup[x] == 1:
            continue

        if y in lookup and (y, x) not in results:
            results.add((x, y))

    return results