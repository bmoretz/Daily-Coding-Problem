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