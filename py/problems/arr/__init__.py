import bisect

''' Products.

Given an array of integers, return a new array such that each element at index i of the new array
is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], 
the expected output would be: [120, 60, 40, 30, 24].

If the input was [3,2,1],
The output would be [2, 3, 6].

Follow-up: What if you can't use division? '''

'''O(N^2) solution, no division'''
def product1(arr):
    result = [1] * len(arr)

    for index in range(len(arr)):
        for current in range(len(arr)):
            
            if current == index:
                continue
            
            result[index] *= arr[ current ]

    return result

'''O(N) solution, w/ division'''
def product2(arr):
    n = len(arr)
    product = 1

    for index in range(n):
        product *= arr[index]

    return [ int(product / i) for i in arr ]

''' O(N) solution '''
def product3(arr):
    n = len(arr)
    prefix = []
    for num in arr:
        if prefix:
            prefix.append( prefix[-1] * num )
        else:
            prefix.append( num )

    suffix = []
    for num in reversed(arr):
        if suffix:
            suffix.append( num * suffix[-1] )
        else:
            suffix.append( num )
    suffix.reverse()

    results = []
    for index in range(n):
        if index == 0:
            results.append( suffix[index + 1] )
        elif index == n - 1:
            results.append( prefix[index - 1] )
        else:
            results.append( prefix[index - 1] * suffix[index + 1] )

    return results

'''Smallest Window.

Given an array of integers that are out of order, determine the bounds of the smallest window
that must be sorted in order for the entire array to be sorted.

For example,

given [3, 7, 5, 6, 9], you should return (1, 3)

'''

'''O(N) solution'''
def window1(arr):
    length = len(arr)
    begin, end, high = -1, -1, 0
    for index in range(length):

        current = arr[index]
        ahead = arr[min(length - 1, index + 1)]

        if current > ahead and begin == -1:
            begin = index
            high = max(current, high)
        
        if ( current > ahead or current <= high ) and begin != -1:
            end = index

    if begin != -1 and end == -1:
        end = len(arr)

    return (begin, end)

'''Sum contiguous subarray.

Given an array of numbers, find the maximum sum of any contiguous subarray of the array.

For example, 

given the array [34, -50, 42, 14, -5, 86], the maximum sum would be 137,

since we would take elements 42, 14, -5 and 86.

Given the array [-5, -1, 8, -9], the maximum sum would be 0, since we would choose not to take any elements.

Do this in O(n) time.

Follow-up: What if the elements can wrap around?

For example, given [8, -1, 3, 4], return 15, as we choose the numbers 3, 4 and 8 where the 8 is obtained from wrapping around.
'''

def max_subarray_sum1(arr):
    n = len(arr)
    result = [0] * n

    for index in range(n):
        result[index] = max( sum( arr[index:n] ), 0 )
    
    return max(result)


'''Given an array of integers, return a new array where each element in the new array
is the number of smaller elements to the right of that element in the original input array.

For example,

given the array [3, 4, 9, 6, 1], return [1, 1, 2, 1, 0]

'''

''' O(N^2) solution'''
def smaller_counts1(arr):
    n = len(arr)
    result = [0] * n

    for index in range(n):
        current = arr[index]
        for num in arr[index+1:n]:
            result[index] += 1 if num <= current else 0

    return result

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