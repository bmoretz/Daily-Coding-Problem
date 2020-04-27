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

def stack_boxes2(boxes):
    
    n = len(boxes)

    if n == 0: return None
    if n == 1: return [boxes[0]]

    s = list(sorted(boxes))

    return stack_boxes2(s[:n - 1]) + [s[n - 1]]

boxes = []

for dim in range(5, 0, -1):
    boxes.append(Box(dim, dim, dim))

stacked = stack_boxes2(boxes)

print(stacked)