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

from typing import List

class Solution:
    
    def sortedSquares(self, A):
        
        answer = [0] * len(A)
        l, r = 0, len(A) - 1
        
        while l <= r:
            
            left, right = abs(A[l]), abs(A[r])
            
            if left > right:
                answer[r - l] = left * left
                l += 1
            else:
                answer[r - l] = right * right
                r -= 1
                
        return answer

arr = [-4,-1,0,3,10]

Solution().sortedSquares(arr)

print(arr)