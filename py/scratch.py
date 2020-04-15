'''Magic Index.

A magic index in an array A[0...N-1] is defined to be an index such that A[i] = i.

Given a sorted array of distinct integers, write a method to find a magic index, 
if one exists, in array A.

FOLLOW UP:

What if the values are not distinct?
'''

def magic_index1(values):
    
    def check_index(values, index):

        n = len(values) - 1

        current = values[index]

        if current == index:
            return index

        if index == 0 or index == n:
            return None

        if current < index:
            return check_index(values, index + index//2)
        else:
            return check_index(values, index//2)

    if values == None: return None

    n = len(values)

    return check_index(values, n//2)

# values = [-5, -3, -2, 1, 4, 5, 7, 9, 11] # 4
# values = [-5, -3, -2, 1, 3, 4, 6, 8, 11] # 6

values = [-5, -3, -2, 1, 3, 4, 5, 6, 9]

result = magic_index1(values)

print(result)