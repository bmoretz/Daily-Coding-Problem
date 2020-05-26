'''Fenwick tree.

You are given an array of length 24, where each element represents the number of new subscribers during the corresponding hour. 
Implement a data structure that efficiently supports the following:

update (hour, value): increment the element at index hour by value.

query(start, end) retrieve the numbner of subscribers that have signed up between start and end (inclusive).

You can assume that all values get cleared at the end of the day, and that you will not be asked for start and end values
that wrap around midnight.
'''

'''naive O(N) solution. '''
class Subscribers1():

    def __init__(self, nums):

        self.counter = {index : value for index, value in enumerate(nums)}

    def update(self, hour, value):
        
        self.counter[hour] += value

    def query(self, start, end):
        values = [self.counter[index] for index in range(start, end + 1)]
        return sum( values )


class BIT:
    def __init__(self, nums):
        # Prepend a zero to our array to use lowest set bit trick.
        self.tree = [0 for _ in range(len(nums) + 1)]
        for i, num in enumerate(nums):
            self.update(i + 1, num)

    def update(self, index, value):
        while index < len(self.tree):
            self.tree[index] += value
            index += index & -index

    def query(self, index):
        total = 0
        while index > 0:
            total += self.tree[index]
            index -= index & -index
        return total

'''O(log n) solution. '''
class Subscribers2:
    
    def __init__(self, nums):
        self.bit = BIT(nums)
        self.nums = nums

    def update(self, hour, value):
        self.bit.update(hour, value - self.nums[hour])
        self.nums[hour] = value

    def query(self, start, end):
        # Shift start and end indices forward as our array is 1-based.
        return self.bit.query(end + 1) - self.bit.query(start)

'''Disjoint-set.

A classroom consists of n students, whose friendships can be represented in an adjacency list. For example, the following describes
a situation where 0 is friends with 1 and 2, 3 is friends with 6, and so on.

{ 0: [1, 2],
  1: [0, 5],
  2: [0],
  3: [6],
  4: [],
  5: [1],
  6: [3]
}

Each student can be placed in a friend group, which can be defined as the transitive closure of that student's relations. In other words,
this is the smallest set such that no student in the group has any friends outside this group. For the example above, the friend group
would be:

{0, 1, 2, 5}, {3, 6}, {4}

Given a friendship list such as the one above, determine the number of friend groups in the class.
'''

import hashlib
class DisjointSet:

    def __init__(self, n):
        self.sets = list(range(n))
        self.sizes = [1] * n
        self.count = n

    def union(self, x, y):
        x, y = self.find(x), self.find(y)

        if x != y:
            # Union by size: always add students to the bigger set.

            if self.sizes[x] < self.sizes[y]:
                x, y = y, x

            self.sets[y] = x
            self.sizes[x] += self.sizes[y]
            self.count -= 1

    def find(self, x):
        group = self.sets[x]

        while group != self.sets[group]:
            group = self.sets[group]

        # Path compression: reassign x to the correct group.
        self.sets[x] = group

        return group

def friend_groups(students):

    groups = DisjointSet(len(students))

    for student, friends in students.items():
        for friend in friends:
            groups.union(student, friend)

    return groups.count

class BloomFilter:

    def __init__(self, n=1000, k=3):
        self.array = [False] * n
        self.hash_algorithms = [
            hashlib.md5,
            hashlib.sha1,
            hashlib.sha256,
            hashlib.sha384,
            hashlib.sha512
        ]
        self.hashes = [self._get_hash(f) for f in self.hash_algorithms[:k]]

    def _get_hash(self, f):
        def hash_function(value):
            h = f(str(value).encode('utf-8')).hexdigest()
            return int(h, 16) % len(self.array)
        
        return hash_function

    def add(self, value):
        for h in self.hashes:
            v = h(value)
            self.array[v] = True

    def check(self, value):
        for h in self.hashes:
            v = h(value)
            if not self.array[v]:
                return False
        
        return True

'''Tic Tac Win.

Design an algorithm to figure out if someone has won a game of tic-tak-toe.
'''

def make_board(n=3):
    return [[None for c in range(n)] for r in range(n)]

def check_win(board):

    def get_pos_value(piece):
        return -1 if piece == 'X' else 1

    def check_cols(board):
        
        n, m = len(board), len(board[0])

        for col in range(m):
            total = 0
            for row in range(n):
                total += get_pos_value( board[row][col] )

            if abs(total) == 3: return True
        
        return False

    def check_rows(board):

        n, m = len(board), len(board[0])

        for row in range(n):
            total = 0
            for col in range(m):
                total += get_pos_value( board[row][col] )

            if abs(total) == 3: return True
        
        return False

    def check_diags(board):
        
        n, m = len(board), len(board[0])

        total, position = 0, 0
        for _ in range(n):
            total += get_pos_value( board[position][position] )
            position += 1
        
        if abs(total) == 3: return True

        total, position = 0, 2
        for row in range(n):
            total += get_pos_value( board[row][position] )
            position -= 1
        
        if abs(total) == 3: return True

        return False        

    if board == None: return None

    if check_diags(board): return True
    if check_rows(board): return True
    if check_cols(board): return True
    
    return False

'''Master Mind.

The Game of Master Mind is played as follows:

The computer has four slots, and each slot will contain a ball that is red (R),
yellow (Y), green (G) or blue (B). For example, the computer might have RGGB (
slot #1 is red, Slots #2 and #3 are green, Slot #4 is blue).

You, the user, are trying to guess the solution. You might, for example,
guess YRGB.

When you guess the correct color for the correct slot, you get a "hit." If you
guess a color that exists but is in the wrong slot, you get a "pseudo-hit." Note
that a slot is a hit can never count as a pseudo-hit.

For example, if the actual solution is RGBY and you guess GGRR, you have
one hit and one pseudo-hit. Write a method that, given a guess and a
solution, returns the number of hits and pseudo-hits.
'''

from random import uniform, randint, seed
from enum import Enum

class MasterMind():

    class Colors(Enum):
        Red = 1
        Blue = 2
        Green = 3
        Yellow = 4
    
    def to_guess(self, colors):

        guess = []
        
        for col in colors:
            guess.append(self.Colors(col))

        return guess

    def __init__(self, s=1234):
        seed(s)
        self.solution = self._gen_solution()

    def peek(self):
        return self.solution

    def _gen_solution(self):

        sln = []

        for _ in range(4):
            sln.append( self.Colors(randint(1, 4)) )
        
        return sln

    def guess(self, solution):
        
        hits = 0
        partial_candidates, remaining = [], []

        for index in range(4):
            
            current = solution[index]

            if self.solution[index] == current:
                hits += 1
            else:
                if current not in partial_candidates:
                    partial_candidates += [current]
                if self.solution[index] not in remaining:
                    remaining += [self.solution[index]]
                
        pseudos = 0

        for candidate in partial_candidates:

            if candidate in remaining:
                pseudos += 1

        return (hits, pseudos)