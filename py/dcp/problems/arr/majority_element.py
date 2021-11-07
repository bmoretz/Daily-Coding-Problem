'''Majority Element.

A majority element is an element that makes up more than half of the
items in an array. Given a positive integer array, find the majority
element. If there is no majority element, return -1. Do this in O(N)
time and O(1) space.

EXAMPLE:

Input: 1, 2, 5, 9, 5, 9, 5, 5, 5
Output: 5
'''

def majority_element(arr):
    
    def occurrences(arr, element, start, stop):
        count = 0

        for index in range(start, stop):
            if arr[index] == element:
                count += 1
        
        return count

    if arr == None: return None
    n, mid = len(arr), len(arr)//2
    if n == 0: return -1

    threshold, majority = mid + 1, -1

    for index in range(0, threshold):
        current = arr[index]

        upper = occurrences(arr, current, threshold, n)

        if upper >= threshold//2:
            lower = occurrences(arr, current, 0, threshold)

            if upper + lower >= threshold:
                majority = current
                break

    return majority