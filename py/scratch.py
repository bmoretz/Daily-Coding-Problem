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


Square = BisectSquares.Square

s1, s2 = Square(2, 5, 2, 5), Square(5, 2, 5, 2)
res = s1.cut(s2)

print(res)