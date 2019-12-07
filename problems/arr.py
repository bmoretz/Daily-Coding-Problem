''' Given an array of integers, return a new array such that each element at index i of the new array
is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], 
the expected output would be: [120, 60, 40, 30, 24].

If the input was [3,2,1],
The output would be [2, 3, 6].

Follow-up: What if you can't use division? '''

import sys

'''O(N^2)'''
def arrprod(arr):
    result = [1] * len(arr)

    for index in range(len(arr)):
        for current in range(len(arr)):
            
            if current == index:
                continue
            
            result[index] *= arr[ current ]

    return result

def arrprod2(arr):
    pass

''' smallest window

Given an array of integers that are out of order, determine the bounds of the smallest window
that must be sorted in order for the entire array to be sorted.

For example,

given [3, 7, 5, 6, 9], you should return (1, 3)

'''

def smallest_window(arr):
    length = len(arr)
    begin, end, high = -1, -1, 0
    for index in range(length):

        current = arr[index]
        ahead = arr[min(length - 1, index + 1)]

        if current > ahead and begin == -1:
            begin = index
            high = max(current, high)
        
        if ( current > ahead or current <= high ) and begin != -1:
            end = index

    if begin != -1 and end == -1:
        end = len(arr)

    return (begin, end)

if __name__ == '__main__':

    raw_input = sys.argv[1]

    if( raw_input != None ):
        args = [int(i) for i in raw_input.split(",")]
        print(arrprod(args))