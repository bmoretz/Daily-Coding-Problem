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
    1e0 : '',
    1e1 : 'Teen',
    1e2 : 'Hundred',
    1e3 : 'Thousand',
    1e6 : 'Million'
}

tens = {
    10 : "Ten",
    20 : "Twenty",
    30 : "Thirty",
    40 : "Forty",
    50 : "Fifty",
    60 : "Sixty",
    70 : "Seventy",
    80 : "Eighty",
    90 : "Ninety"
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
            
        else:
        
            result[ position ] = places[ position ] + digits[ digit ]

        prior = current

    return ' '.join(result.values())