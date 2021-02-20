
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
        
s, t = "badc", "baba"
actual = is_isomorphic.isIsomorphic(s, t)
expected = True