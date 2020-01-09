import bisect

''' Given an array of integers, return a new array such that each element at index i of the new array
is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], 
the expected output would be: [120, 60, 40, 30, 24].

If the input was [3,2,1],
The output would be [2, 3, 6].

Follow-up: What if you can't use division? '''

'''O(N^2) solution, no division'''
class product1:

    @staticmethod
    def func(arr):
        result = [1] * len(arr)

        for index in range(len(arr)):
            for current in range(len(arr)):
                
                if current == index:
                    continue
                
                result[index] *= arr[ current ]

        return result

'''O(N) solution, w/ division'''
class product2:

    @staticmethod
    def func(arr):
        n = len(arr)
        product = 1

        for index in range(n):
            product *= arr[index]

        return [ int(product / i) for i in arr ]

''' O(N) solution '''
class product3:

    @staticmethod
    def func(arr):
        n = len(arr)
        prefix = []
        for num in arr:
            if prefix:
                prefix.append( prefix[-1] * num )
            else:
                prefix.append( num )

        suffix = []
        for num in reversed(arr):
            if suffix:
                suffix.append( num * suffix[-1] )
            else:
                suffix.append( num )
        suffix.reverse()

        results = []
        for index in range(n):
            if index == 0:
                results.append( suffix[index + 1] )
            elif index == n - 1:
                results.append( prefix[index - 1] )
            else:
                results.append( prefix[index - 1] * suffix[index + 1] )

        return results

''' smallest window

Given an array of integers that are out of order, determine the bounds of the smallest window
that must be sorted in order for the entire array to be sorted.

For example,

given [3, 7, 5, 6, 9], you should return (1, 3)

'''

'''O(N) solution'''
class window1:

    @staticmethod
    def func(arr):
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

'''Given an array of numbers, find the maximum sum of any contiguous subarray of the array.

For example, 

given the array [34, -50, 42, 14, -5, 86], the maximum sum would be 137,

since we would take elements 42, 14, -5 and 86.

Given the array [-5, -1, 8, -9], the maximum sum would be 0, since we would choose not to take any elements.

Do this in O(n) time.

Follow-up: What if the elements can wrap around?

For example, given [8, -1, 3, 4], return 15, as we choose the numbers 3, 4 and 8 where the 8 is obtained from wrapping around.
'''

class max_subarray_sum1:

    @staticmethod
    def func(arr):
        n = len(arr)
        result = [0] * n

        for index in range(n):
            result[index] = max( sum( arr[index:n] ), 0 )
        
        return max(result)


'''Given an array of integers, return a new array where each element in the new array
is the number of smaller elements to the right of that element in the original input array.

For example,

given the array [3, 4, 9, 6, 1], return [1, 1, 2, 1, 0]

'''

''' O(N^2) solution'''
class smaller_counts1():

    @staticmethod
    def func(arr):
        n = len(arr)
        result = [0] * n

        for index in range(n):
            current = arr[index]
            for num in arr[index+1:n]:
                result[index] += 1 if num <= current else 0

        return result