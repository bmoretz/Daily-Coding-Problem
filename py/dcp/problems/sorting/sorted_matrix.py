"""
Sorted Matrix.

Given an M x N matrix in which each row and each column is sorted in ascending order,
write a method to find an element.
"""

def mat_search(mat, element):

    def find(arr, element, left, right):
        
        if left > right: return - 1

        mid = left + (right - left)//2

        if element == arr[mid]:
            return mid
        elif element < arr[mid]:
            return find( arr, element, left, mid - 1 )
        else:
            return find( arr, element, mid + 1, right )
    
    def find_row(mat, element, bottom, top):

        if bottom > top: return -1

        mid = top + (bottom - top)//2

        n = len(mat[mid]) - 1

        minimum, maximum = mat[mid][0], mat[mid][n]

        if element >= minimum and element <= maximum:
            return mid
        elif element <= minimum:
            return find_row(mat, element, bottom, mid - 1)
        else:
            return find_row(mat, element, mid  + 1, top)

    if mat == None or element == None: return None

    position = find_row(mat, element, 0, len(mat) - 1)

    if position == -1: return -1

    row = mat[position]

    return (position, find( row, element, 0, len(row) -1 ))

def build_mat(n):
    return [[( (y * 10) + x ) for x in range(1, n + 1)] for y in range(n)]