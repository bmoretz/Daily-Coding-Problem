'''
Given a word w and a string s, find all indices in s which are the starting locations of anagrams of w.

For example, given w is ab and s is abxaba, return [0, 3, 4].
'''

def anagram1(s, w):

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

'''Given a list of words, find all pairs of kunique indices such that the concatenation of the two words is a palindrome.

For example, given the list ["code", "edoc", "da", "d"], return [(0, 1), (1, 0), (2, 3)]
'''

def is_palindrome(word):
    return word == word[::-1]    
    
'''O(n) Solution'''
def palindrome1(arr):
    n, c = len(arr) - 1, 0
    iters = []

    # create test matrix
    for index in range(n, -1, -1):
        val = list(zip( [c] * index, [x + (c + 1) for x in range(index)] ))
        iters.append(val)
        c = c + 1

    flattend = [item for sublist in iters for item in sublist]

    results = []

    for index, value in enumerate(flattend):

        e1, e2 = value[0], value[1]

        # test both permutations
        if is_palindrome( arr[e1] + arr[e2] ):
            results.append( (e1, e2) )

        if is_palindrome( arr[e2] + arr[e1] ):
            results.append( (e2, e1) )

    return results

''' O(N^2 + C) Solution '''
def palindrome2(words):
    result = []

    for i, word1 in enumerate(words):
        for j, word2 in enumerate(words):
            if i == j:
                continue
            if is_palindrome(word1 + word2):
                result.append((i, j))

    return result