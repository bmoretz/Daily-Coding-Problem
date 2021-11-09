
'''Peaks and Valleys.

In an array of integers, a "peak" is an element which is greater than or equal to 
the adjacent integers and a "valley" is an element which is less than or equal to
the adjacent integers. For example, in the array [5, 8, 6, 2, 3, 4, 6], {5, 8} and
{6, 2} are valleys. Given an array of integers, sort the array into an alternating
sequence of peaks and valleys.

EXAMPLE:
Input: {5, 3, 1, 2, 3}
Output: {5, 1, 3, 2, 3}
'''

def alt_sort1(arr):
    
    if arr == None: return None

    n = len(arr)

    if n == 0: return []

    s = list(reversed(sorted(arr)))

    mid = n//2

    high, low = s[:mid], list(reversed(s[mid:]))
    h, l = 0, 0

    result = []

    while h < len(high) or l < len(low):
        
        if h < len(high):
            result.append(high[h])
            h += 1
        
        if l < len(low):
            result.append(low[l])
            l += 1

    return result

def alt_sort2(arr):

    if arr == None: return None

    n = len(arr)

    if n == 0: return []

    s = sorted(arr)

    mid = n//2

    high, low = s[mid:], s[:mid]
    h, l = len(high) - 1, 0

    result = []

    while h >= 0 or l < len(low):
        
        if h >= 0:
            result.append(high[h])
            h -= 1
        
        if l < len(low):
            result.append(low[l])
            l += 1

    return result