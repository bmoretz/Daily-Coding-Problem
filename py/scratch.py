
'''
485. Max Consecutive Ones.

Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:

Input: [1,1,0,1,1,1]
Output: 3

Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.

Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
'''

class Solution:

    from typing import List

    @staticmethod
    def findMaxConsecutiveOnes(nums: List[int]) -> int:
        
        left, right, max_len, N = 0, 0, 0, len(nums)

        while right < N:
            
            left = right

            while right < N and nums[right] == 1:
                right += 1

            max_len = max(max_len, right - left)

            while right < N and nums[right] == 0:
                right += 1

        return max_len

s = [1,1,0,1,1,1]
actual = Solution.findMaxConsecutiveOnes(s)

expected = [2, 2]