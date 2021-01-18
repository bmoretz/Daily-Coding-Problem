
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
    
    from typing import List

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
    
    from typing import List

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
    
    from typing import List
    
    def removeDuplicates(self, nums: List[int]) -> int:
        
        cnt = 0
        for num in nums:
            if cnt == 0 or num != nums[cnt - 1]:
                nums[cnt] = num
                cnt += 1
                
        return cnt


'''
724. Find Pivot Index.

Given an array of integers nums, write a method that returns the "pivot" index of this array.

We define the pivot index as the index where the sum of all the numbers to the left of the 
index is equal to the sum of all the numbers to the right of the index.

If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index. 

Example 1:

Input: nums = [1,7,3,6,5,6]
Output: 3

Explanation:

The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
Also, 3 is the first index where this occurs.

Example 2:

Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.

Constraints:

The length of nums will be in the range [0, 10000].
Each element nums[i] will be an integer in the range [-1000, 1000].
'''

class find_pivot:

    from typing import List

    @staticmethod
    def pivotIndex(nums: List[int]) -> int:
        
        left_sum, right_sum = 0, sum(nums)
        
        for index in range(len(nums)):
            
            right_sum -= nums[index]
            
            if left_sum == right_sum:
                return index
            
            left_sum += nums[index]
            
        return -1

'''
747. Largest Number At Least Twice of Others.

In a given integer array nums, there is always exactly one largest element.

Find whether the largest element in the array is at least twice as much as every other number in the array.

If it is, return the index of the largest element, otherwise return -1.

Example 1:

Input: nums = [3, 6, 1, 0]
Output: 1
Explanation: 6 is the largest integer, and for every other number in the array x,
6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.
 
Example 2:

Input: nums = [1, 2, 3, 4]
Output: -1
Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.

Note:

nums will have a length in the range [1, 50].
Every nums[i] will be an integer in the range [0, 99].
'''

class dominate_index:

    from typing import List
    
    @staticmethod
    def dominantIndex(nums: List[int]) -> int:
        
        max_index, max_num = float('-inf'), float('-inf')
        
        for index, num in enumerate(nums):
            
            if num > max_num:
                max_index, max_num = index, num
        
        for num in nums:
            
            if num != max_num and num*2 > max_num:
                return -1
            
        return max_index

'''
66. Plus One.

Given a non-empty array of decimal digits representing a non-negative integer, 
increment one to the integer.

The digits are stored such that the most significant digit is at the head of 
the list, and each element in the array contains a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself. 

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Example 3:

Input: digits = [0]
Output: [1]

Constraints:

1 <= digits.length <= 100
0 <= digits[i] <= 9
'''

class plus_one:
    
    from typing import List
    
    @staticmethod
    def plusOne(digits: List[int]) -> List[int]:
        
        if not digits: return []
        
        pos, carry = len(digits) - 1, 1
        
        while pos >= 0 and carry:
            
            digits[pos] = digits[pos] + carry
            
            if digits[pos] > 9:
                digits[pos], carry = 0, 1
                pos -= 1
            else:
                carry = 0
        
        if carry:
            digits = [carry] + digits
            
        return digits

'''
27. Remove Element.

Given an array nums and a value val, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means a modification to the input array will be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeElement(nums, val);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
} 

Example 1:

Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2]

Explanation: Your function should return length = 2, with the first two elements of nums being 2.
It doesn't matter what you leave beyond the returned length. For example if you return 2 with nums = [2,2,3,3] or nums = [2,2,0,0], your answer will be accepted.

Example 2:

Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3]

Explanation: Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4. Note that the order of those five 
elements can be arbitrary. It doesn't matter what values are set beyond the returned length.
 
Constraints:

0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100
'''

class remove_element:

    from typing import List

    @staticmethod
    def removeElement( nums : List[int], val : int ) -> int:
        
        position = 0

        for index in range(len(nums)):

            if nums[index] != val:
                nums[position] = nums[index]
                position += 1

        return position

'''
209. Minimum Size Subarray Sum.

Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
'''

class min_size_subarray_sum:
    
    from typing import List

    @staticmethod
    def minSubArrayLen(s: int, nums: List[int]) -> int:
        
        N, min_len = len(nums), float('inf')
        left, right, cur_sum = 0, 0, 0
        
        while right < N:
            
            while cur_sum < s and right < N:
                cur_sum += nums[right]
                right += 1
            
            while cur_sum >= s:
                min_len = min(min_len, right - left)
                cur_sum -= nums[left]
                left += 1
                
        return 0 if min_len == float('inf') else min_len