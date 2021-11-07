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

def minSubArrayLen(s: int, nums: list[int]) -> int:
    
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