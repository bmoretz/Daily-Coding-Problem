# Given an array of integers, return a new array such that each element at index i of the new array
# is the product of all the numbers in the original array except the one at i.
#
# For example, if our input was [1, 2, 3, 4, 5], 
# the expected output would be: [120, 60, 40, 30, 24]
#
# If the input was [3,2,1]
# The output would be [2, 3, 6]
#
# Follow-up: What if you can't use division?

import sys

def arrprod(arr):
    result = [1] * len(arr)

    for index in range(len(arr)):
        for current in range(len(arr)):
            
            if current == index:
                continue
            
            result[index] *= arr[ current ]

    return result

if __name__ == '__main__':

    raw_input = sys.argv[1]

    if( raw_input != None ):
        args = [int(i) for i in raw_input.split(",")]
        print(arrprod(args))