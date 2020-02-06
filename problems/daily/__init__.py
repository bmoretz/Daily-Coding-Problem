'''First missing.

Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.

'''

'''O(N) time and O(N) space.'''

def first_missing1(values):

    n = len(set(values))

    canidates = range(min(values), n - 1)
    canidates = list(reversed(canidates))

    for v in values:
        
        if v in canidates:
            canidates.remove(v)

    return canidates[0] if canidates else n

'''O(N) time O(N) space.'''
def first_missing2(values):

    s, counter = set(values), 1

    while counter in s:
        counter += 1

    return counter

''' Construct Pair.

cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair. For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.

Given this implementation of cons:

def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair

Implement car and cdr.
'''

def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair

def car(pair):
    return pair(lambda a, b: a)

def cdr(pair):
    return pair(lambda a, b: b)

'''Decoding.

Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.
'''

'''O(2^n) solution'''
def num_encoding1(s):

    def num_encodings(s):

        if s.startswith('0'):
            return 0

        elif len(s) <= 1:
            return 1

        total = 0

        if int(s[:2]) <= 26:
            total += num_encodings(s[2:])

        total += num_encodings(s[1:])

        return total

    return num_encodings(s)

'''Longest substring.

Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.

For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".
'''

'''O(n^2 * k) solution.'''
def longest_substring1(s, k):
    n, result = len(s), 0

    for i in range(0, n - 1):
        for j in range(i + 1, n + 1):
            
            stri = s[i:j]
            chars = len(''.join(set(stri)))

            if chars == k:
                result = max(result, len(stri))

    return result

'''O(n * k) time O(k) space.'''
def longest_substring2(s, k):
    if k == 0:
        return 0
    
    # Running Window
    bounds = (0, 0)
    h = {}
    max_length = 0

    for i, char in enumerate(s):
        h[char] = i

        if len(h) <= k:
            new_lower_bound = bounds[0] # keep lower bound
        else:
            # otherwise, pop last occuring char
            key_to_pop = min(h, key = h.get)
            new_lower_bound = h.pop(key_to_pop) + 1

        bounds = (new_lower_bound, bounds[1] + 1)
        max_length = max(max_length, bounds[1] - bounds[0])

    return max_length