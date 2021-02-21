'''
Isomorphic Strings
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
'''

class is_isomorphic:

    @staticmethod
    def isIsomorphic(s: str, t: str) -> bool:
        
        s2t, t2s = {}, {}

        for index in range(len(s)):
            
            if s[index] in s2t and s2t[s[index]] != t[index]:
                return False
            
            if t[index] in t2s and t2s[t[index]] != s[index]:
                return False

            s2t[s[index]] = t[index]
            t2s[t[index]] = s[index]

        return True

'''
599. Minimum Index Sum of Two Lists.

Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, 
output all of them with no order requirement. You could assume there always exists an answer.

Example 1:

Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".
Example 2:

Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["KFC","Shogun","Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
Example 3:

Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["KFC","Burger King","Tapioca Express","Shogun"]

Output: ["KFC","Burger King","Tapioca Express","Shogun"]
Example 4:

Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["KNN","KFC","Burger King","Tapioca Express","Shogun"]
Output: ["KFC","Burger King","Tapioca Express","Shogun"]
Example 5:

Input: list1 = ["KFC"], list2 = ["KFC"]
Output: ["KFC"]
 

Constraints:

1 <= list1.length, list2.length <= 1000
1 <= list1[i].length, list2[i].length <= 30
list1[i] and list2[i] consist of spaces ' ' and English letters.
All the stings of list1 are unique.
All the stings of list2 are unique.
'''

class minimum_index_sum:

    from typing import List, Dict

    @staticmethod
    def to_dict(items : List[str]) -> Dict[str, int]:

        result = {}

        for index, item in enumerate(items):
            result[item] = index

        return result

    @staticmethod
    def findRestaurant(list1: List[str], list2: List[str]) -> List[str]:

        from collections import defaultdict

        d1, d2 = minimum_index_sum.to_dict(list1), minimum_index_sum.to_dict(list2)

        results = defaultdict(list)

        for k, v in d1.items():
            if k in d2:
                val = v + d2[k]
                
                results[val] += [k]

        return results[min(results.keys())]

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

    @staticmethod
    def containsNearbyDuplicate(nums: List[int], k :int ) -> bool:

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