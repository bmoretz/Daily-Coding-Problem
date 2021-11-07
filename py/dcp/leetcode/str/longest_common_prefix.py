'''
14. Longest Common Prefix.

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

0 <= strs.length <= 200
0 <= strs[i].length <= 200

strs[i] consists of only lower-case English letters.
'''

def longestCommonPrefix(strs: list[str]) -> str:

    max_len, prefix = 0, ''

    for string in strs:
        max_len = max(max_len, len(string))
    
    for position in range(0, max_len):
        
        if len(strs[0]) <= position:
            break

        cur = strs[0][position]

        for index in range(1,len(strs)):

            if len(strs[index]) <= position:
                cur = None
                break

            if strs[index][position] != cur:
                cur = None
                break
        
        if cur is None:
            break
        
        prefix += cur

    return prefix