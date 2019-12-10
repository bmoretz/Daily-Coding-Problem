'''Given an array of integers, return a new array where each element in the new array
is the number of smaller elements to the right of that element in the original input array.

For example,

given the array [3, 4, 9, 6, 1], return [1, 1, 2, 1, 0]

'''

arr = [3, 4, 9, 6, 1] 

n = len(arr)
result = [0] * n

for index in len(n):
    