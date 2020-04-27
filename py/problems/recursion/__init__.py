from collections import defaultdict

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

'''Triple Step.

A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time.

Implement a method to count how many possible ways the child can run up the stairs.
'''

def triple_step1(n):

    def triple_step(n):
        if n < 0:
            return 0
        if n == 0:
            return 1
        else:
            return triple_step(n - 3) + triple_step(n - 2) + triple_step(n - 1)

    return triple_step(n)

def triple_step2(n):

    def triple_step(n, step_counts=[]):
        if step_counts == []:
            step_counts = [0] * (n + 1)

        if n < 0:
            return 0
        elif n == 0:
            return 1
        elif step_counts[n] != 0:
            return step_counts[n]
        else:
            total = 0

            total += triple_step(n - 3, step_counts)
            total += triple_step(n - 2, step_counts)
            total += triple_step(n - 1, step_counts)

            step_counts[n] = total

            return step_counts[n]

    return triple_step(n)

'''Robot in a Grid.

Imagine a robot sitting on the upper left corner of grid with r rows and c columns.

The robot can only move in two directions, right and down, but certain cells are "off limits" such
that the robot cannot step on them. Design an algorithm to find a path for the robot from the top
left to the bottom right.
'''

def build_grid(rows, columns, obsticals):

    grid = [[0 for x in range(rows)] for x in range(columns)] 

    for coord in obsticals:
        grid[coord[0]][coord[1]] = 1

    return grid

def robot_walk1(grid):

    def walk(grid, path=None):

        def step(path, x, y):
            return path + [(x, y)]

        if path == None:
            path = [(0, 0)]

        x, y = path[-1][0], path[-1][1]

        rows, columns = len(grid), len(grid[0])

        if x == rows - 1 and y == columns - 1:
            return path

        walk_right = y < columns - 1 and grid[x][y+1] == 0

        if walk_right:
            path = walk(grid, step(path, x, y + 1))

            if path[-1] == (rows - 1, columns - 1):
                return path

        walk_down = x < rows - 1 and grid[x+1][y] == 0

        if walk_down:
            path = walk(grid, step(path, x + 1, y))

            if path[-1] == (rows - 1, columns - 1):
                return path
        
        if not (walk_right or walk_down):
            path = step(path, -1, -1) # stuck

        return path
    return walk(grid)

'''Magic Index.

A magic index in an array A[0...N-1] is defined to be an index such that A[i] = i.

Given a sorted array of distinct integers, write a method to find a magic index, 
if one exists, in array A.

FOLLOW UP:

What if the values are not distinct?
'''

def magic_index1(values):
    
    def check_index(values, start, stop):
        if stop < start: return None

        mid = (start + stop) // 2
        val = values[mid]

        if val == mid:
            return mid

        if mid < val:
            return check_index(values, start, mid - 1)
        else:
            return check_index(values, mid + 1, stop)

    if values == None: return None

    n = len(values) - 1

    return check_index(values, 0, n)

'''
this approach handles duplicate values
'''
def magic_index2(values):
    
    def check_index(values, start, stop):
        if stop < start: return None

        midIndex = (start + stop) // 2
        val = values[midIndex]

        if val == midIndex:
            return midIndex
        
        leftIndex = min(midIndex - 1, val)
        left = check_index(values, start, leftIndex)

        if left:
            return left

        rightIndex = max(midIndex + 1, val)
        right = check_index(values, rightIndex, stop)

        return right
        
    if values == None: return None

    n = len(values) - 1

    return check_index(values, 0, n)

'''Power Set.

Write a method to return all subsets of a set.
'''

def power_sets1(data):
    
    def subsets(seq):
        if len(seq) <= 1:
            yield seq
            yield []
        else:
            for item in subsets(seq[1:]):
                yield [seq[0]] + item
                yield item

    return list(subsets(data))

'''Recursive Multiply.

Write a recursive function to multiply two positive integers without 
using the * operator. You can use addition, subtraction, and bit shifting, 
but you should minimize the number of those operations.

'''

def rec_multiply1(a, b):

    def mult(a, b):  

        if b == 1:
            return a
        else:
            return a + mult(a, b - 1)

    if not (a or b): return None
    
    if a == 0 or b == 0: return 0      

    return mult(a, b)

'''Towers of Hanoi.

In the classic problem of the Towers of Hanoi, you have 3 towers
and N disks of different sizes which can slide onto any tower. The
puzzle starts with disks sorted in ascending order of size from
top to bottom (i.e., each disk sits on top of an even larger one).

You have the following constraints:

1.) Only one disk can be moved at a time.
2.) A disk is slid off the top of one tower onto another tower.
3.) A disk cannot be placed on top of a smaller disk.

Write a program to move the disks from the first tower to the last using stacks.
'''

class Tower():
    
    def __init__(self, id, items=[]):
        self._disks = []
        self._id = id

        for item in items:
            self.push(item)

    def push(self, item):
        self._disks = self._disks + [item]

    def peek(self):
        
        return self._disks[0] if self._disks else 0

    def id(self):
        return self._id

    def disks(self):
        return len(self._disks)

    def empty(self):
        return not self._disks

    def top(self):
        return self._disks.pop()

    def moveTop(self, dest):
        disk = self.top()
        print(f'\nmoving {disk} from to tower {dest.id()}')
        dest.push(disk) 

    def moveDisks(self, n, dest, alt):
        if n > 0:
            print(f'\n{self}\n{alt}\n{dest}')
            self.moveDisks(n - 1, alt, dest)
            self.moveTop(dest)
            alt.moveDisks(n - 1, dest, self)

    def __str__(self):

        result = f'tower {self._id} : '
        
        if self._disks:
            n = len(self._disks)
            for index in range(n - 1):
                result += f'{self._disks[index]} | '
            result += str(self._disks[n - 1])
        else:
            result += 'empty'

        return result

'''Permutations without duplicates.

Write a method to compute all permutations of a string of unique characters.
'''

def permutations1(chars):

    def get_perms(chars):
        n = len(chars)

        if n == 1: return chars
        
        results = []

        for index in range(len(chars)):

            cur, rem = chars[index], ''.join([c for i, c in enumerate(chars) if i != index])

            perms = get_perms(rem)

            for perm in perms:
                results.append(str(perm + cur))

        return results
    
    return get_perms(chars)

'''Parens: Implement an algorithm to print all valid (e.g., properly opened and closed) combinations
of n pairs of parentheses.

EXAMPLE:

Input: 3
Output: ((())), (()()), (())(), ()(()), ()()()
'''

def gen_parens1(n):

    def gen(n):
        def wrap(p=''):
            return '(' + p + ')'

        if n == 1: return [wrap()]

        results = []

        for par in list(gen(n-1)):
            results.append(wrap(par))
            results.append(wrap() + par)

        return results
    
    if n == None: return None
    if n == 0: return ''

    return gen(n)

'''Paint fill.

Implement the "paint fill" function that one might see on many image editing
programs. That is, given a screen (represented by a two-dimensional array of 
colors), a point, and a new color, fill in the surrounding area until the color
changes from the original color.

'''

from enum import Enum

class Color(Enum):
    BLACK = 0
    WHITE = 1
    RED = 2
    GREEN = 3
    BLUE = 4

def fill_rect(grid, point, col):
    
    def fill(grid, point, old_col, new_col):

        col, row = point

        n_row, n_col = len(grid) - 1, len(grid[0]) - 1

        if row < 0 or row > n_row: return False
        if col < 0 or col > n_col: return False
        
        old_col = grid[row][col]

        if grid[row][col] == old_col:

            grid[row][col] = new_col

            fill(grid, (row-1, col), old_col, new_col)
            fill(grid, (row+1, col), old_col, new_col)
            fill(grid, (row, col-1), old_col, new_col)
            fill(grid, (row, col+1), old_col, new_col)

        return True

    old_col = grid[point[0]][point[1]]

    fill(grid, point, old_col, col)

'''Paint fill.

Implement the "paint fill" function that one might see on many image editing
programs. That is, given a screen (represented by a two-dimensional array of 
colors), a point, and a new color, fill in the surrounding area until the color
changes from the original color.

'''

from enum import Enum

class Color(Enum):
    BLACK = 0
    WHITE = 1
    RED = 2
    GREEN = 3
    BLUE = 4

def fill_rect(grid, point, col):
    
    def fill(grid, point, old_col, new_col):

        row, col = point

        n_row, n_col = len(grid) - 1, len(grid[0]) - 1

        if row < 0 or row > n_row: return False
        if col < 0 or col > n_col: return False
        
        old_col = grid[row][col]

        if grid[row][col] == old_col:

            grid[row][col] = new_col

            fill(grid, (row-1, col), old_col, new_col)
            fill(grid, (row+1, col), old_col, new_col)
            fill(grid, (row, col-1), old_col, new_col)
            fill(grid, (row, col+1), old_col, new_col)

        return True

    row, col = point
    
    n_row, n_col = len(grid) - 1, len(grid[0]) - 1

    if row < 0 or row > n_row: return False
    if col < 0 or col > n_col: return False
    
    old_col = grid[row][col]

    fill(grid, point, old_col, col)

'''Coins.

Given an infinite number of quarters (25 cents), 10 dimes (10 cents),
nickels (5 cents), and pennies (1 cent), write code to calculate the number
of ways of representing n cents.
'''

''' brute force, O(N!) '''
def coin_ways1(n):

    def coin_ways(n):
        if n <= 0: return 0

        total = 0

        for denom in (25, 10, 5, 1):
            
            if denom <= n:            
                total += 1 + coin_ways(n - denom)

        return total

    if n == None: return None

    return coin_ways(n)

''' dynamic N(n log n)'''
def coin_ways2(n):

    seen_ways = {}

    def coin_ways(n):
        if n <= 0: return 0

        if n in seen_ways: return seen_ways[n]

        total = 0

        for denom in (25, 10, 5, 1):
            
            if denom <= n:

                cur = n - denom
                total += 1

                if cur in seen_ways:
                    total += seen_ways[cur]
                else:
                    total += coin_ways(cur)

        seen_ways[n] = total

        return total

    if n == None: return None

    return coin_ways(n)

'''Eight Queens.

Write an algorithm to print all ways of arranging eight queens on an 8x8 chess
board so that none of them share the same row, column, or diagonal. In this case,
"diagonal" means all diagonals, not just the two that bisect the board.
'''

def get_board(n):
    return [[0 for col in range(n)] for row in range(n)]
 
def place_queens(board):

    def try_place(board, row, col):

        colsum = 0
        
        for r in range(n_row):
            colsum += board[r][col]

        rowsum = sum(board[row])

        diagsum = 0

        if row < n_row - 1:
            if col < n_col - 1:
               diagsum += board[row + 1][col + 1]
            if col > 0:
                diagsum += board[row + 1][col - 1]

        if colsum == 0 and rowsum == 0 and diagsum == 0:
            board[row][col] = 1

        return board[row][col]

    if board == None: return None

    n_row, n_col = len(board), len(board[0])

    placed = 0

    for row in range(n_row)[::-1]:

        for col in range(n_col)[::-1]:

           if try_place(board, row, col):
               placed += 1
               break


    return board if placed == n_col else None

'''Boxes.

You have a stack of n boxes, with widths w_1, heights h_1, and depths d_1. The 
boxes cannot be rotated and can only be stacked on top of one another if each box
in the stack is strictly larger than the box above it in width, height and depth.

Implement a method to compute teh height of the tallest possible stack.

The height of a stack is the sum of the heights of each box.
'''

class Box():

    def __init__(self, w, h, d):
        self.width = w
        self.height = h
        self.depth = d

    def __eq__(self, other):
        
        equal = False

        if isinstance(other, Box):
            equal = self.width == other.width and \
                self.height == other.height and \
                    self.depth == other.depth

        return equal

    def __lt__(self, other):

        lt = False

        if isinstance(other, Box):
            lt = self.width < other.width and \
                self.height < other.height and \
                    self.depth < other.depth

        return lt

    def __gt__(self, other):
        return not self.__lt__(other)

    def __str__(self):
        return f'[{self.width}, {self.height}, {self.depth}]'

def stack_boxes1(boxes):
    
    n = len(boxes)

    if n == 0: return None
    if n == 1: return [boxes[0]]

    s = list(sorted(boxes))

    return stack_boxes1(s[:n - 1]) + [s[n - 1]]