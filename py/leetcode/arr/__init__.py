from typing import List

'''
1089. Duplicate Zeros

Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written.

Do the above modifications to the input array in place, do not return anything from your function.

Example 1:

Input: [1,0,2,3,0,4,5,0]
Output: null
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
Example 2:

Input: [1,2,3]
Output: null
Explanation: After calling your function, the input array is modified to: [1,2,3]

Note:

1 <= arr.length <= 10000
0 <= arr[i] <= 9
'''

class duplicate_zeros:
    
    def shift_arr( self, arr : List[int], index : int ) -> None:
        
        pos = len(arr) - 1
        
        while pos > 0 and pos > index:
            arr[pos] = arr[pos-1]
            pos -= 1
            
        
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        
        pos, n = 0, len(arr)
        
        while pos < n:
            
            if arr[pos] == 0 and pos < n - 1:
                
                self.shift_arr(arr, pos + 1 )
                arr[pos+1] = 0
                
                pos += 1
            elif pos == n:
                pos[arr] = 0
                
            pos += 1

'''
Given an array nums of integers, return how many of them contain an even number of digits.
 
Example 1:

Input: nums = [12,345,2,6,7896]
Output: 2
Explanation: 
12 contains 2 digits (even number of digits). 
345 contains 3 digits (odd number of digits). 
2 contains 1 digit (odd number of digits). 
6 contains 1 digit (odd number of digits). 
7896 contains 4 digits (even number of digits). 
Therefore only 12 and 7896 contain an even number of digits.
Example 2:

Input: nums = [555,901,482,1771]
Output: 1 
Explanation: 
Only 1771 contains an even number of digits.
 

Constraints:

1 <= nums.length <= 500
1 <= nums[i] <= 10^5
'''

class even_digits1:
    
    def num_digits( self, num : int ):
        
        digits = 0
        
        while int(num) > 0:
            digits += 1
            num /= 10
        
        return digits
    
    def findNumbers(self, nums: List[int]) -> int:
        
        result = 0
        
        for num in nums:
            
            if self.num_digits( num ) % 2 == 0:
                result += 1

        return result

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

class sorted_squares():
    
    def sortedSquares(self, arr):
        
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

'''
26. Remove Duplicates from Sorted Array.

Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means a modification to the input array will be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}

Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2]
Explanation: Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the returned length.
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4]
Explanation: Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively. It doesn't matter what values are set beyond the returned length.
 

Constraints:

0 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
nums is sorted in ascending order.
'''

class dedupe_sorted:
        
    def removeDuplicates(self, nums: List[int]) -> int:
        
        cnt = 0
        for num in nums:
            if cnt == 0 or num != nums[cnt - 1]:
                nums[cnt] = num
                cnt += 1
                
        return cnt