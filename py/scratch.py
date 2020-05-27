'''Sub Sort.

Given an array of integers, write a method to find indices m and n such that
if you sorted elements m through n, the entire array would be sorted. Minimized
n - m (that is, find the smallest such sequence).

EXAMPLE:

Input: 1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19
Output: (3, 9)
'''

def sub_sort(arr):
    
    if not arr: return None

    n, m = None, None
    prev, inner_min = None, None

    for index, element in enumerate(arr):

        if prev:

            if not m and element < prev: 
                n = index
            
            if n and prev > element: 
                m = index + 1

        if n: inner_min = element \
            if not inner_min else min(inner_min, element)

        prev = element

    if inner_min < arr[0]:
        n = 0
    else:
        while arr[ n - 1 ] > inner_min:
            n -= 1

    return (n, m)

arr = [1, 2, 3, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19]

result = sub_sort(arr)

print(result)