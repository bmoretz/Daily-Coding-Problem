'''Magic Index.

A magic index in an array A[0...N-1] is defined to be an index such that A[i] = i.

Given a sorted array of distinct integers, write a method to find a magic index, 
if one exists, in array A.

FOLLOW UP:

What if the values are not distinct?
'''

def magic_index1(values):
    
    def check_index(values, start, stop):
        if stop < start: return None

        mid = (start + stop) // 2
        val = values[mid]

        if val == mid:
            return mid

        if mid < val:
            return check_index(values, start, mid - 1)
        else:
            return check_index(values, mid + 1, stop)

    if values == None: return None

    n = len(values) - 1

    return check_index(values, 0, n)

'''
this approach handles duplicate values
'''
def magic_index2(values):
    
    def check_index(values, start, stop):
        if stop < start: return None

        midIndex = (start + stop) // 2
        val = values[midIndex]

        if val == midIndex:
            return midIndex
        
        leftIndex = min(midIndex - 1, val)
        left = check_index(values, start, leftIndex)

        if left:
            return left

        rightIndex = max(midIndex + 1, val)
        right = check_index(values, rightIndex, stop)

        return right
        
    if values == None: return None

    n = len(values) - 1

    return check_index(values, 0, n)