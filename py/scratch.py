'''Sparse Search.

Given a sorted array of strings that is interspersed with empty strings, write
a method to find the location of the given string.

EXAMPLE

Input: ball, {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""}
Output: 4
'''

def sparse_search(arr, element):
    
    def compare(left, right):

        n_l, n_r = len(left) - 1, len(right) - 1
        n = max( n_l, n_r )

        cmp_val = 0

        for index in range(n):
            
            l = ord( left[index] ) if index < n_l else 0
            r = ord( right[index] ) if index < n_r else 0

            cmp_val += l - r
        
        return cmp_val

    def find(arr, element, left, right):
        
        if left > right: return -1

        mid = left + (right - left)//2
        
        l, r = mid, mid

        while arr[ l ] == '' and arr[ r ] == '':
            l -= 1
            r += 1

        mid = l if arr[ l ] != '' else r

        cmp_val = compare( arr[ mid ], element )

        if cmp_val == 0:
            return mid
        elif cmp_val < 0:
            return find( arr, element, left, mid - 1 )
        else:
            return find( arr, element, mid + 1, right )

    if arr == None or element == None: return None
    
    if element == '': return -1 # searching for spaces not allowed
    
    n = len(arr) - 1

    return find(arr, element, 0, n)

arr = ["at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""]

result = sparse_search(arr, "ball")

print(result)
