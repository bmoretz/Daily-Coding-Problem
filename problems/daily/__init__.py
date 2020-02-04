'''1.27

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

''' 1.28

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

'''1.30

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