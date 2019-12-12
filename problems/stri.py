'''
Given a word w and a string s, find all indices in s which are the starting locations of anagrams of w.

For example, given w is ab and s is abxaba, return [0, 3, 4].
'''

class anagram1:
    def func(self, s, w):
        n = len(s)
        wr = w[::-1]
        parts = []

        start, stop = 0, len(w)
        for index in range(n):

            parts.append( s[start:stop] )

            start = start + 1
            stop = stop + 1

        results = []
        for index in range(len(parts)):
            p = parts[index]

            if p == w or p == wr:
                results.append(index)

        return results