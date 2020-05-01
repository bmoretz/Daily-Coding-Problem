'''Search in Rotated Array.

Given a sorted array of n integers that has been rotated an unknown number of times,
write code to find an element in the array. You may assume that the array was originally
sorted in increasing order.

EXAMPLE:

Input: Find 5 in [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14]
Output: 8 (the index of the array)
'''

def find_rotated1(arr, search):

    def find_pivot(arr, left, right):

        while left < right:

            mid = left + (right - left) // 2

            if arr[mid] > arr[right]:
                left = mid + 1
            else:
                right = mid

        return mid + 1

    def find_element(arr, search, left, right):

        n = right - left

        if left  > right: return -1

        mid = left + n // 2

        if arr[ mid ] == search:
            return mid
        elif search < arr[ mid ]:
            return find_element( arr, search, left, mid )
        else:
            return find_element( arr, search, mid + 1, right )

    if arr == None or search == None: return None
    
    n = len(arr) - 1

    pivot = find_pivot(arr, 0, n)

    if search == arr[ pivot ]:
        return pivot
    elif search > arr[pivot] and search <= arr[ n ]:
        return find_element(arr, search, pivot + 1, n)
    else:
        return find_element(arr, search, 0, pivot)

arr = [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14]

res = find_rotated1(arr, 14)

print(res)