'''Best Line.

Given a two-dimensional graph with points on it, find a line
which passes the most number of points.
'''

class BestLine():
    
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

