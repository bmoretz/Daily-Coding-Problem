from collections import Counter

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

'''Palindrome Permutation:

Given a string, write a function to check if it is a permutation of a palindrome.

A palindrome is a word or phrase that is the same forwads or backwards.
A permutation is a rearrangement of letters.

They do not have to be real words.

Example:

Input: Tact Coa
Output: True (permutations: "taco cat", "atco cta", etc.)
'''

def is_palindrome_perm1(s):

    if s is None: return False
    if len(s) <= 2: return True

    occurrences = Counter(s.replace(' ', '').lower())

    n_odd = sum([0 if v % 2 == 0 else 1 for v in occurrences.values()])

    return n_odd == 1

'''One Away:

There are three types of edits that can be performed on strings:

insert a character,
remove a character,
replace a character

Given two strings, write a function to check if they are one edit (or zero edits) away.

Example:

pale, ple -> true
pales, pale -> true
pale, bale -> true
pale, bake -> false
'''

def is_one_away1(s1, s2):

    def get_differences(s1, s2):

        ordered = (s1, s2) if len(s1) > len(s2) else (s2, s1)

        primary, secondary = ordered[0], ordered[1]
        
        for c in secondary:

            index = primary.find(c)

            if index != -1:
                primary = primary[0 : index : ] + primary[index + 1 ::]

        return len(primary)

    if s1 is None or s1 is None: return False
    if len(s1) == 1 and len(s2) == 1: return True

    return get_differences(s1, s2) <= 1

'''String Compression.

Implement a methods to perform basic string compression using the counts of repeating characters.

For example,

The string aabcccccaaa would become a2b1c5a3.

If the "compressed" string would not become smaller than the original string, your methods should return the original string.

You can assume the string has only uppercase and lowercase letters (a-z).
'''

def compress1(s):

    if s == None: return None

    result, prev, counter = '', s[0], 1

    for char in s[1:]:

        if char != prev:
            result += f'{prev}{counter}'
            prev, counter = char, 1
        else:
            counter += 1
    
    result += f'{prev}{counter}'

    return result if len(result) < len(s) else s