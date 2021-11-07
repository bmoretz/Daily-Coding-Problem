
'''
977. Squares of a Sorted Array.

Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 
Note:

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A is sorted in non-decreasing order.
'''
    
def sortedSquares(arr):
    
    N = len( arr )
    
    result = [0] * N 
    left, right = 0, N - 1
    pos = N - 1
    
    while left <= right:
        
        l, r = abs(arr[left]), abs(arr[right])
        
        if l < r:
            result[pos] = r * r
            right -= 1
        else:
            result[pos] = l * l
            left += 1
        
        pos -= 1
        
    return result