'''Smaller Counts.

Given an array of integers, return a new array where each element in the new array
is the number of smaller elements to the right of that element in the original input array.

For example,

given the array [3, 4, 9, 6, 1], return [1, 1, 2, 1, 0]

'''

''' O(N^2) solution'''
def smaller_counts1(arr):
    n = len(arr)
    result = [0] * n

    for index in range(n):
        current = arr[index]
        for num in arr[index+1:n]:
            result[index] += 1 if num <= current else 0

    return result