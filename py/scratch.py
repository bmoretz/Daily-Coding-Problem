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
    def intersect(line1, line2):

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

        int_point = line_intersect1.Point(x, y)

        line_int = point_between(start1, int_point, end1) and \
            point_between(start2, int_point, end2)

        return int_point if line_int else None

li = line_intersect1

l1 = li.make_line(-3, -5, 12, 4)
l2 = li.make_line(3, 4, -12, 15)

result = li.intersect(l1, l2)

print(result)