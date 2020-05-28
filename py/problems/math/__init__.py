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