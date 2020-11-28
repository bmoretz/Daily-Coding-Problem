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