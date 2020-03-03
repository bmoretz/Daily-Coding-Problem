'''Anagrams.

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

'''Palindromes.

Given a list of words, find all pairs of k unique indices such that the concatenation of the two words is a palindrome.

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

'''Zigzag.

Given a string and a number of lines k, print the string in zigzag form.

In zigzag, characters are printed out diagonally from top left to bottom right until reaching the k^th line, then back up to top right, and so on.

For example, given the sentence "thisisazigzag" and k = 4, you should print:

t     a     g
 h   s z   a
  i i   i z
   s     g
'''

''' O(N * k) Solution '''
def zigzag1(stri, k):

    def get_spaces(row, desc, k):
        max_spaces = (k - 1) * 2 - 1

        if desc:
            spaces = max_spaces - row * 2
        else:
            spaces = max_spaces - (k - 1 - row) * 2
        return spaces

    def is_descending(index, k):
        # Check whether the index is more or less than halfway
        # though its ocillation back to the starting point
        return index % (2 * (k - 1)) < k -1

    def zigzag(sentence, k):
        n = len(sentence)
        result = "\n"

        for row in range(k):
            i = row
            line = [" " for _ in range(n)]

            while i < n:
                line[i] = sentence[i]
                desc = is_descending(i, k)
                spaces = get_spaces(row, desc, k)
                i += spaces + 1
            result += "".join(line) + "\n"

        return result

    return zigzag(stri, k)

''' Unique characters.

Implement an algorithm to determine if a string has all unique characters.

What if you can't use additional data structures?
'''

def is_unique1(s):
    if s is None: return False
    return len(s) == len(set(s))

def is_unique2(string):
    values = 0
    for char in string:

        current = ord(char) - ord('a')

        val = values & (1 << current)
        
        if val > 0: return False
        
        values |= (1 << current)

    return True

'''Check Permutation.

Given two strings, write a method to decide if one is a permutation of the other.
'''

def is_permutation(s1, s2):

    if s1 == None or s2 == None: return False
    if len(s1) != len(s2): return False

    check = set(s1)
    is_perm = True

    for char in s2:
        is_perm &= char in check

    return is_perm

'''URLify.

Write a method to replace all spaces in a string with '%20'. You may assume that the string
has sufficient space at the end to hold the additional characters, and that you are given
the "true" length of the string.
'''

''' Forward insertion approach, O(N) runtime, O(1) space. '''
def urlify1(url):

    def to_str(s):
        return ''.join(s)

    if url is None: return None
    
    characters = list(url)

    for index in range(len(characters) + 1):

        if characters[index].isspace():
            characters[index] = '%'
            characters.insert(index + 1, '20')

    return to_str(characters)

''' Backward fill, O(N) runtime, O(n) space. '''
def urlify2(url):

    def count_spaces(s):
        return sum([1 if c.isspace() else 0 for c in s])

    def to_str(s):
        return ''.join(s)

    if url is None: return None
    
    n = len(url) + count_spaces(url) * 2
    characters = [''] * n

    index, cur = len(url) - 1, n - 1

    while index > -1:

        if url[index].isspace():
            characters[cur] = '0'
            characters[cur - 1] = '2'
            characters[cur - 2] = '%'
            cur -= 3
        else:
            characters[cur] = url[index]
            cur -= 1

        index -= 1

    return to_str(characters)