
'''
219. Contains Duplicate II.

Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
'''

class contains_duplicate_ii:

    from typing import List

    def containsNearbyDuplicate(self, nums: List[int], k :int ) -> bool:

        result = {}

        for index, item in enumerate(nums):
            if item not in result:
                result[item] = [index]
            else:
                for other in result[item]:
                    if abs(other - index) <= k:
                        return True
                
                result[item] += [index]

        return False
        
nums, k = [1,0,1,1], 1

actual = contains_duplicate_ii().containsNearbyDuplicate(nums, k)

print(actual)