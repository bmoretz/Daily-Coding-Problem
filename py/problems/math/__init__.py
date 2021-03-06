'''Intersection.

Given two straight line segments (represented as a start point and and end point),
compute the point of intersection, if any.
'''

class line_intersect1():

    class Point():
        def __init__(self, x, y):
            self.x = x
            self.y = y

        def __str__(self):
            return f'({round(self.x, 2)}, {round(self.y, 2)})'
        
        def __eq__(self, value):
            if isinstance(value, line_intersect1.Point):
                return self.x == value.x and self.y == value.y
            else:
                return super().__eq__(value)

        def __ne__(self, value):
            if isinstance(value, line_intersect1.Point):
                return not self.__eq__(value)
            else:
                return super().__ne__(value)
            
    class Line():
        def __init__(self, p1, p2):
            self.p1 = p1
            self.p2 = p2
        
        def slope(self):
            return (self.p2.y - self.p1.y) / (self.p2.x - self.p1.x)

        def yintecept(self):
            return self.p2.y - self.slope() * self.p2.x

    @staticmethod
    def make_line(p1, p2, p3, p4):

        start = line_intersect1.Point(p1, p2)
        end = line_intersect1.Point(p3, p4)

        return line_intersect1.Line(start, end)

    @staticmethod
    def intersect(line1, line2, dig=2):

        def is_between(start, middle, end):
            if start > end:
                return end <= middle and middle <= start
            else:
                return start <= middle and middle <= end

        def point_between(start, mid, end):
            return is_between(start.x, mid.x, end.x) and \
                    is_between(start.y, mid.y, end.y)

        if line1 == None or line2 == None: return None

        if line1.p1.x < line1.p2.x:
            start1, end1 = line1.p1, line1.p2
        else:
            start1, end1 = line1.p2, line1.p1

        if line2.p1.x < line2.p2.x:
            start2, end2 = line2.p1, line2.p2
        else:
            start2, end2 = line2.p2, line2.p1
            
        l1 = line_intersect1.Line(start1, end1)
        l2 = line_intersect1.Line(start2, end2)

        s1, s2 = l1.slope(), l2.slope()
        yi1, yi2 = l1.yintecept(), l2.yintecept()

        if s1 == s2:
            if yi1 == yi2 and point_between(start1, start2, end1):
                return start2
            else:
                return None
        
        x = (yi2 - yi1) / (s1 - s2)
        y = x * s1 + yi1

        int_point = line_intersect1.Point(round(x, dig), round(y, dig))

        line_int = point_between(start1, int_point, end1) and \
            point_between(start2, int_point, end2)

        return int_point if line_int else None

'''Factorial Zeros.

Write an algorithm which computes the number of trailing zeros in n factorial.
'''

def factorial_zeros1(n):

    from math import log, ceil, floor

    def factorial(n, fact={}):

        if n == 1: return 1

        if n not in fact:
            fact[n] = n * factorial(n - 1)

        return fact[n]

    if n == None: return None

    if n < 0: return -1

    fact = factorial(n)

    zeros = 0
    
    for div in range(1, ceil(log(n, 5))):
        
        zeros += floor(n / (5**div))

    return zeros

'''English Int.

Given an integer, print an English phrase that describes the integer (e.g., 
"One Thousand, Two Hundred Thirty-Four").
'''

digits = {
    0 : "",
    1 : "One",
    2 : "Two",
    3 : "Three",
    4 : "Four",
    5 : "Five",
    6 : "Six",
    7 : "Seven",
    8 : "Eight",
    9 : "Nine",
}

special = {
    11 : "Eleven",
    12 : "Twelve",
    13 : "Thirteen",
}

suffix = {
    10 : "teen",
    20 : "twenty",
    30 : "thirty"
}

places = {
    0 : '',
    1e0 : '',
    1e1 : 'Teen',
    1e2 : 'Hundred',
    1e3 : 'Thousand',
    1e4 : 'Ten Thousand',
    1e6 : 'Million'
}

tens = {
    0 : "",
    1 : "Ten",
    2 : "Twenty",
    3 : "Thirty",
    4 : "Forty",
    5 : "Fifty",
    6 : "Sixty",
    7 : "Seventy",
    8 : "Eighty",
    9 : "Ninety"
}

def english_int(num):

    from collections import defaultdict

    def separate_digits(number):
        from math import log, ceil, floor

        num_digits = ceil(log(num, 10))

        values = []

        for index in range(num_digits):

            position = pow(10, index)
            place = num % pow(10, index + 1)
            digit = floor(place / position)

            values += [(position, digit)]
        
        return values

    if num == None: return None
    if num == 0: return 'Zero'

    values = separate_digits(num)

    result = defaultdict(str)

    prior = (0, 0)

    for index in range(len(values)):
        current = values[index]

        position, digit = current

        compound = position + prior[1]

        if compound in special:

            result[position] = special[compound]
            result[prior[0]] = ''

        elif position == 10:

            p = tens[ digit ]

            result[ position ] = p
        else:
            
            p = places[ position ]
            d = digits[ digit ]
            
            result[ position ] = d + ' ' + p

        prior = current

    eng = ''

    for value in sorted(result.keys(), key=lambda x:-x):
        eng += result[value] + ' '

    return eng.strip()

'''Operations.

Write methods to implement the multiply, subtract and divide operations for integers. The
results of all these are integers. Use only the add operator.
'''

class Ops():

    @staticmethod
    def mult(a, b):
        
        result = 0

        for i in range(b):
            result += a

        return result

    @staticmethod
    def sub(a, b):
        return a + -b

    @staticmethod
    def div(a, b):

        result = 0

        while a >= b:

            a = a + -b
            result += 1

        return result

'''Bisect Squares.

Given two squares on a two-dimensional plane, find
a line that would cut these two squares in half. Assume
that the top and the bottom sides of the square run
parallel to the x-axis.
'''

class BisectSquares():
        
    class Square():

        class Line():
            
            def __init__(self, p1, p2):
                self.p1 = p1
                self.p2 = p2

            def __repr__(self):
                return (self.p1, self.p1)

            def __str__(self):
                return f'[{self.p1}, {self.p2}]'

        class Point():

            def __init__(self, x, y):
                self.x = x
                self.y = y

            def __str__(self):
                return f'({self.x}, {self.y})'

        def __init__(self, left, top, bottom, right):
            self.top = top
            self.left = left
            self.bottom = bottom
            self.right = right

        def size(self) -> Point:
            return (self.right - self.left) * (self.top - self.bottom)

        def mid(self) -> Point:
            return self.Point((self.left + self.right) / 2.0,
                    (self.top + self.bottom) / 2.0)

        def extend(self, mid1, mid2,  size):
            xdir = -1 if mid1.x < mid2.x else 1
            ydir = -1 if mid1.y < mid2.y else 1

            if mid1.x == mid2.x:
                return self.Point(mid1.x, mid1.y + ydir * size / 2.0)

            slope = (mid1.y - mid2.y) / (mid1.x - mid2.x)

            y1, y2 = 0, 0

            if abs(slope) == 1:
                x1 = mid1.x + xdir * size / 2.0
                y1 = mid1.y + ydir * size / 2.0
            elif abs(slope) < 1:
                x1 = mid1.x + xdir * size / 2.0
                y1 = slope * (x1 - mid1.x) + mid1.y
            else:
                y1 = mid1.y + ydir * size / 2.0
                x1 = (y1 - mid1.y) / slope + mid1.x

            return Point(x1, y1)

        def cut(self, other) -> Line:
            
            p1 = self.extend(self.mid(), other.mid(), self.size())
            p2 = self.extend(self.mid(), other.mid(), -1 * self.size())
            p3 = self.extend(other.mid(), self.mid(), other.size())
            p4 = self.extend(other.mid(), self.mid(), -1 * other.size())

            start, end = p1, p1

            for point in [p2, p3, p4]:

                if point.x < start.x or \
                    point.x == start.x and point.y < start.y:
                    start = point
                elif point.x > end.x or \
                    point.x == end.x and point.y > end.y:
                    end = point

            return self.Line(start, end)

'''Contiguous Sequence.

You are given an array of integers (both positive and negative). Find the
contiguous sequence with the largest sum. Return the sum.

EXAMPLE:

Input: 2, -8, 3, -2, 4, -10
Output: 5 (i.e., {3, -2, 4})
'''

def contiguous_seq1(arr):

    if not arr: return None

    total, elements = 0, []

    best = []

    for index, num in enumerate(arr):

        total += num

        if total < 0:
            if len(elements) > 1:
                best = elements
            total, elements = 0, []
        else:
            elements += [num]

    if sum(best) < total:
        best = elements

    return sum(best) if best else None

'''Sum Swap.

Given two arrays of integers, find a pair of values (one value from
each array) that you can swap to give the two arrays the same
sum.

EXAMPLE
Input: {4, 1, 2, 1, 1, 2} and {3, 6, 3, 3}
Output: {1, 3}
'''

def sum_swap(arr1, arr2):

    if not (arr1 and arr2): return None
    
    sumA, sumB = sum(arr1), sum(arr2)

    delta = (sumB - sumA)/2

    ys, results = set(arr2), set()

    for x in arr1:

        t = x + delta

        if t in ys:
            results.add(( int(x), int(t) ))

    return results

'''Rand7 from Rand5.

Implement a method rand7() given rand5(). That is, given a
method that generates a random number between 0 and 4 (inclusive),
write a method that generates a random number between 0 and 6
(inclusive).
'''

from random import randrange
from collections import defaultdict

def rand5():
    return randrange(0, 5)

'''
rand7 1

simple / deterministic, does not generate a uniform
distribution though.
'''
def rand7_1():
    a, b = rand5(), rand5()
    n = (a + b) % 7
    return n

'''
rand7 2

somewhat more complicated, and also non-deterministic (unknown loops
before we get a result, but it will complete). we generate a number
between 0-8 using rand5, then scale it by 5. we discard anything >
20 (21 values inc zero), and then mod the result to put it in the 
range. Produces uniform range.
'''
def rand7_2():
    
    while True:
        a, b = rand5(), rand5()
        n = 5 * a + b

        if n < 21:
            return n % 7

'''
rand7 3

most complicated and also non-deterministic. Generate the even
numbers between 0 and 9 (2*rand5), and then an additional rand
that must be between 0 and 3 (to maintain the distribution),
then mod b to get a 1 or a zero. finally, n will be in range 0-9,
so we discard > 7.
'''
def rand7_3():

    while True:
        a, b = 2 * rand5(), rand5()

        if b != 4:
            r = b % 2
            n = a + r
            if n < 7:
                return n

def get_freq_table(fn, iters : int):
    
    freq = defaultdict(int)

    for _ in range(int(iters)):
        freq[fn()] += 1

    for index in range(len(freq)):
        freq[index] /= iters

    return freq

'''Calculator.

Given an arithemetic equation consisting of positive integers, +, -,
*, and / (no parenthesis), compute the result.

EXAMPLE:

Input: 2*3+5/6*3+15
Output: 23.5
'''

def calculate1(expr):
    
    def tokenize(expr):
        ops = {
            '+' : [ lambda x, y: x + y ],
            '-' : [ lambda x, y: x - y ],
            '*' : [ lambda x, y: x * y ],
            '/' : [ lambda x, y: x / y ]
        }

        tokens, cur = [], ''
        
        mults, adds = 0, 0

        for c in expr:
            if c in ops:
                tokens += [int(cur)]
                tokens += [(c, ops[c])]

                if c in ['+', '-']:
                    adds += 1
                else:
                    mults += 1
                
                cur = ''
            else:
                cur += c
        
        tokens += [int(cur)]

        return (tokens, mults, adds)

    def process(tokens, op_type):

        for index, token in enumerate(tokens):

            if type(token) == tuple:
                if token[0] in op_type:
                    func, x, y = token[1][0], \
                        tokens[index - 1], tokens[index + 1]

                    left = tokens[:index - 1]
                    result = [func(x, y)]
                    right = tokens[index + 2:]

                    return left + result + right

        return tokens

    if not expr: return None

    tokens, mults, adds = tokenize(expr)

    for _ in range(mults):
        tokens = process(tokens, '*/')
    
    for _ in range(adds):
        tokens = process(tokens, '+-')

    return tokens[0]

'''Count of 2's.

Write a method to count the number of 2's that appear in all the 
numbers between 0 and n (inclusive).

EXAMPLE:
Input: 25
Output: 9 (2, 12, 20, 21, 22, 23, 24 and 25. Note that 22 counts for two 2's)
'''

def count_twos1(n):
    from math import floor

    def num_twos(n):
        count = 0

        while n > 0:
            if n % 10 == 2:
                count += 1
            n = floor(n / 10)
        
        return count
    
    if n == None: return 0

    total = 0

    for index in range(n + 1):
        total += num_twos(index)
    
    return total

def count_twos2(n):
    from math import floor

    def twos_in_range(number, d) -> int:
        powers = pow(10, d)
        next_power = powers * 10
        right = number % powers

        round_down = number - number % next_power
        round_up = round_down + next_power

        digit = floor((number / powers) % 10)

        ans = 0

        if digit < 2:
            ans = round_down / 10
        elif  digit == 2:
            ans = round_down / 10 + right + 1
        else:
            ans = round_up / 10

        return floor(ans)

    if n == None: return 0
    
    count = 0
    length = len(str(n))

    for digit in range(length):
        count += twos_in_range(n, digit)

    return count

'''Kth Multiple.

Design an algorithm to find the kth number such that the only prime
factors are 3, 5, and 7. Note that 3, 5 and 7 do not have to be
factors, but it should not have any other prime factors. For
example, the first several multiples would be (in order)
1, 3, 5, 7, 9, 15, 21.
'''

'''brute force O(k^3)'''
def kth_smallest1(k):

    def all_possible(k):
        solutions = []

        for a in range(k):
            for b in range(k):
                for c in range(k):
                    solutions += [3**a * 5**b * 7**c]
        
        return solutions

    if k == None: return None
    if k < 0: return 0

    possible = all_possible(k)

    possible = sorted(possible)

    return possible[k - 1]

'''O(K) solution'''
def kth_smallest2(k):
    
    from collections import deque

    def front_or_default(queue):
        return queue[0] if len(queue) > 0 else float('inf')

    if k == None: return None
    if k < 0: return 0
    
    val = 0

    q3, q5, q7 = deque(), deque(), deque()
    
    q3.append(1)

    for index in range(k):

        v3 = front_or_default(q3)
        v5 = front_or_default(q5)
        v7 = front_or_default(q7)

        val = min(v3, min(v5, v7))

        if val == v3:
            q3.popleft()
            q3.append(3 * val)
            q5.append(5 * val)
        elif val == v5:
            q5.popleft()
            q5.append(5 * val)
        elif val == v7:
            q7.popleft()

        q7.append(7 * val)

    return val