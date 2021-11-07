''' Print the nth fibonacci number. '''

''' brute force. '''
def fib1(n):

    def fib(n):
        if n == 0: return 0
        if n == 1: return 1

        return fib(n - 2) + fib(n - 1)

    return fib(n)

''' dynamic. '''
def fib2(n):

    cache = {0: 0, 1: 1}

    def fib(n):
        if n not in cache:
            cache[n] = fib(n - 2) + fib(n - 1)
        
        return cache[n]
    
    return fib(n)

'''Number of ways to climb a staircase.

There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time.

Given N, write a function that returns the number of unique ways you can climb the staircase.
The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

1, 1, 1, 1
2, 1, 1
1, 2, 1
1, 1, 2
2, 2

What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a set of positive integers X? For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.

'''

def staircase1(n, X):
    def staircase(n, X):
        if n < 0:
            return 0
        elif n == 0:
            return 1
        else:
            return sum(staircase(n - step, X) for step in X)
    return staircase(n, X)

def staircase2(n, X):
    def staircase(n, X):
        if n < 0:
            return 0
        elif n == 0:
            return 1
        elif n in X:
            return 1 + sum(staircase(n - x, X) for x in X if x < n)
        else:
            return sum(staircase(n - x, X) for x in X if x < n)
    return staircase(n, X)

'''Number of ways to decode a string.

Given the mapping a = 1, b = 2, ..., z = 26, and an encoded message, d count the number of ways it can be decoded.

For example, the message "111" should be 3, since it could be decoded as "aaa", "ka", and "ak".

You can assume that the messages are always valid. For example, "001" is not allowed.
'''

from collections import defaultdict

'''O(2^n) solution.'''
def num_encodings1(s):

    def num_encodings(s, total=0):
        # There are no valid encodings if the string starts with 0.
        if s.startswith('0'):
            return 0

        # Both the empty string and a single character should return 1.
        elif len(s) <= 1:
            return 1

        total += num_encodings(s[1:])

        if int(s[:2]) <= 26:
            total += num_encodings(s[2:])

        return total
    
    return num_encodings(s)

'''O(N) solution.'''
def num_encodings2(s):
    cache = defaultdict(int)
    cache[len(s)] = 1

    for i in reversed(range(len(s))):
        if s[i].startswith('0'):
            cache[i] = 0
        elif i == len(s) - 1:
            cache[i] = 1
        else:
            cache[i] += cache[i + 1]
            if int(s[i:i + 2]) <= 26:
                cache[i] = cache[i + 2]

    return cache[0]

''' Paint houses.

A builder is looking to build a row of N houses that can be of K different colors. He has a goal of minimizing cost while 
ensuring that no two neighboring houses are of the same color.

Given an N by K matrix where the nth row and kth column represents the cost to build the nth house with kth color, 
return the minimum cost which achieves this goal.
'''

''' O(n*k*k) solution. '''
def build_houses(matrix):

    n = len(matrix)
    k = len(matrix[0])
    solution_matrix = [[0] * k]

    # Solution matrix: matrix[i][j] represents the minimum cost to build house i with color j.
    # build house i with color j.
    for r, row in enumerate(matrix):
        row_cost = []
        for c, val in enumerate(row):
            row_cost.append(min(solution_matrix[r][i]
                            for i in range(k)
                            if i != c) + val)
        solution_matrix.append(row_cost)

    return min(solution_matrix[-1])