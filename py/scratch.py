'''Magic Index.

A magic index in an array A[0...N-1] is defined to be an index such that A[i] = i.

Given a sorted array of distinct integers, write a method to find a magic index, 
if one exists, in array A.

FOLLOW UP:

What if the values are not distinct?
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

# values = [-5, -3, -2, 1, 4, 5, 7, 9, 11] # 4
# values = [-5, -3, -2, 1, 3, 4, 6, 8, 11] # 6
# values = [-5, -3, -2, 1, 3, 4, 5, 6, 8] # 8

values = [-10, -5, 2, 2, 2, 3, 4, 7, 9, 12, 13] 

result = magic_index2(values)

print(result)