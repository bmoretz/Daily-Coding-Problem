'''
1100. Find K-Length Substrings With No Repeated Characters.

Given a string S, return the number of substrings of length K with no repeated characters.

Example 1:

Input: S = "havefunonleetcode", K = 5
Output: 6
Explanation: 
There are 6 substrings they are : 'havef','avefu','vefun','efuno','etcod','tcode'.

Example 2:

Input: S = "home", K = 5
Output: 0
Explanation: 
Notice K can be larger than the length of S. In this case is not possible to find any substring.

Note:

1 <= S.length <= 10^4
All characters of S are lowercase English letters.
1 <= K <= 10^4
'''

class k_len_substrings:
    
    def numKLenSubstrNoRepeats(self, S: str, K: int) -> int:
        
        from collections import Counter

        pos, N, result = 0, len(S), 0

        if N < K: return 0

        chars = Counter()

        for index in range(N):
            
            chars[S[index]] += 1
    
            while chars[S[index]] > 1:
                chars[S[pos]] -= 1
                pos += 1

            if index - pos + 1 == K:
                result += 1
                chars[S[pos]] -= 1
                pos += 1

        return result

'''
833. Find And Replace in String.

To some string S, we will perform some replacement operations that replace groups of letters with new ones (not necessarily the same size).

Each replacement operation has 3 parameters: a starting index i, a source word x and a target word y.  The rule is that if x starts at position i 
in the original string S, then we will replace that occurrence of x with y.  If not, we do nothing.

For example, if we have S = "abcd" and we have some replacement operation i = 2, x = "cd", y = "ffff", then because "cd" 
starts at position 2 in the original string S, we will replace it with "ffff".

Using another example on S = "abcd", if we have both the replacement operation i = 0, x = "ab", y = "eee", as well as another 
replacement operation i = 2, x = "ec", y = "ffff", this second operation does nothing because in the original string S[2] = 'c', which doesn't match x[0] = 'e'.

All these operations occur simultaneously.  It's guaranteed that there won't be any overlap in 
replacement: for example, S = "abc", indexes = [0, 1], sources = ["ab","bc"] is not a valid test case. 

Example 1:

Input: S = "abcd", indexes = [0, 2], sources = ["a", "cd"], targets = ["eee", "ffff"]
Output: "eeebffff"
Explanation:
"a" starts at index 0 in S, so it's replaced by "eee".
"cd" starts at index 2 in S, so it's replaced by "ffff".
Example 2:

Input: S = "abcd", indexes = [0, 2], sources = ["ab","ec"], targets = ["eee","ffff"]
Output: "eeecd"
Explanation:
"ab" starts at index 0 in S, so it's replaced by "eee".
"ec" doesn't starts at index 2 in the original S, so we do nothing.
 

Constraints:

0 <= S.length <= 1000
S consists of only lowercase English letters.
0 <= indexes.length <= 100
0 <= indexes[i] < S.length
sources.length == indexes.length
targets.length == indexes.length
1 <= sources[i].length, targets[i].length <= 50
sources[i] and targets[i] consist of only lowercase English letters.
'''

class find_and_replace:
    
    from typing import List
    
    @staticmethod
    def findReplaceString(S : str, indices : List[int], sources : List[int], targets : List[int]) -> str:
            """
            :type S: str
            :type indexes: List[int]
            :type sources: List[str]
            :type targets: List[str]
            :rtype: str
            """

            modified = list(S)
            for index, source, target in zip(indices, sources, targets):
                if not S[index:].startswith(source):
                    continue
                else:
                    modified[index] = target
                    for i in range(index+1, len(source) + index):
                        modified[i] = ""

            return "".join(modified)

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

class longest_common_prefix:

    from typing import List

    @staticmethod
    def longestCommonPrefix(strs: List[str]) -> str:

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

'''
344. Reverse String.

Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
'''

class reverse_string:

    from typing import List

    @staticmethod
    def reverseString(s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """

        left, right = 0, len(s) - 1

        while left < right:

            s[left], s[right] = s[right], s[left]
            left, right = left + 1, right - 1