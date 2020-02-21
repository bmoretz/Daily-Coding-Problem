from collections import defaultdict

''' Paint houses.

A builder is looking to build a row of N houses that can be of K different colors. He has a goal of minimizing cost while 
ensuring that no two neighboring houses are of the same color.

Given an N by K matrix where the nth row and kth column represents the cost to build the nth house with kth color, 
return the minimum cost which achieves this goal.
'''

'''Tower of Hanoi.

The Tower of Hanoi is a puzzle game with three rods and n disks, each with a different size.

All the disks start off on the first rod in a stack. They are ordered by size, with the largest disk on the bottom and the smallest
one at the top.

The goal of this puzzle is to move all the disks from the first rod to the last rod while following these rules:

- You can only move one disk at a time.

- A move consists of taking the uppermost disk from one of the stacks and placing it on top of another stack.

- You cannot place a larger disk on top of a smaller disk.

Write a function that prints out all the steps necessary to complete the Tower of Hanoi. You should assume that the rods are numbered,
with the first rod being 1, the second (aux) being 2, and the last (goal) being 3.
'''

def tower_of_hanoi(n, a='1', b='2', c='3'):
    if n >= 1:
        tower_of_hanoi(n-1, a, c, b)
        move_disk(a, c)
        tower_of_hanoi(n-1, b, c, a)

def move_disk(fp, tp):
    print("moving disk from", fp, "to", tp)

'''Regular expressions.

Implement regular expression matching with the following special characters.

- . (period) which matches any single character.

- * (asterisk) which matches zero or more of the preceding element.

That is, implement a function that takes in a string and a valid regular expression and returns whether or not the string matches
the regular expression.

For example, given the regular expression ra. and the string "ray", your function should return True. The same regular expression
on the string "raymond" should return false.

Given the regular expression .*at and the string "chat", your function  should return true. The same regular expression on the
string "chats" should return false.
'''

def matches_first_char(s, r):
    return s[0] == r[0] or (r[0] == '.' and len(s) > 0)

def matches(r, s):

    if r == '':
        return s == ''

    if len(r) == 1 or r[1] != '*':
        # The first character in the regex is not succeeded by a *.
        if matches_first_char(r, s):
            return matches(s[1:], r[1:])
        else:
            return False

    else:
        # The first character is succeeded by a *.
        # First, try zero length.
        if matches(s, r[2:]):
            return True

        # If that doesn't match straight away, try globbing more prefixes
        # until the first character of the string doesn't match anymore.
        i = 0
        while matches_first_char(s[i:], r):
            if matches(s[i+1:], r[2:]):
                return True

            i += 1

'''Find array extremes efficiently.

Given an array of numbers of length n,, find both the minimum and maximum using less than 2 * (n -2) comparisons.
'''

''' straight forward enumeration '''
def min_and_max1(arr):

    min_element = max_element  = arr[0]

    compare = lambda x, y: (x, y) if y > x else (y, x)

    # Make the list odd so we can pair up the remaining elements neatly.
    if len(arr) % 2 == 0:
        arr.append(arr[-1])

    for i in range(1, len(arr), 2):
        smaller, bigger = compare(arr[i], arr[i + 1])
        min_element = min(min_element, smaller)
        max_element = max(max_element, bigger)

    return min_element, max_element

''' divide & conquer approach '''
def min_and_max2(arr):
    if len(arr) == 1:
        return arr[0], arr[0]

    elif len(arr) == 2:
        return (arr[0], arr[1]) if arr[0] < arr[1] else (arr[1], arr[0])
    
    else:
        n = len(arr) // 2
        lmin, lmax = min_and_max2(arr[:n])
        rmin, rmax = min_and_max2(arr[n:])
        return min(lmin, rmin), max(lmax, rmax)

'''Play Nim.

The game of Nim is played as follows. Starting with three heaps, each containing a variable number of items, two players take turns removing one or more 
items from a single pile. The player who eventually is forced to take the last stone loses. For example, if the initial heap sizes are 3, 4 and 5, a game could
be played as shown below:

A   B   C   | Action
3   4   5   | Player 1 take 3 items from B
3   1   5   | Player 2 take 2 items from C
0   1   3   | Player 1 take 3 items from A
0   1   3   | Player 2 take 3 items from C
0   1   0   | Player 1 take 1 items from A
0   0   0   | Player 1 loses

Given a list of non-zero starting values [a, b, c], and assuming optimal play, determine whether the first player has a forced win.
'''

heaps = [3, 4, 5]

def nim1(heaps):

    def update(heaps, pile, items):
        heaps = list(heaps)
        heaps[pile] -= items
        return tuple(heaps)

    def get_moves(heaps):
        moves = []

        for pile, count in enumerate(heaps):
            for i in range(1, count + 1):
                moves.append(update(heaps, pile, i))

        return set(moves)
    
    def nim(heaps):
        if heaps == (0, 0, 0):
            return True

        moves = get_moves(heaps)

        return any([nim(move) != True for move in moves])
    
    return nim(heaps)

def nim2(heaps):

    a, b, c = heaps

    if a == b == c == 1:
        return False

    return a ^ b ^ c != 0