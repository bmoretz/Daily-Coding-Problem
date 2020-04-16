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

# values = [-5, -3, -2, 1, 4, 5, 7, 9, 11] # 4
# values = [-5, -3, -2, 1, 3, 4, 6, 8, 11] # 6
# values = [-5, -3, -2, 1, 3, 4, 5, 6, 8] # 8

values = [-1, 0, 1, 2, 3, 4, 6, 10, 11] 

result = magic_index1(values)

print(result)