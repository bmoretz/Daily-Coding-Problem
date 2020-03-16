'''Stack of Plates.

Imagine a (literal) stack of plates. If the stack gets too high, it might topple. Therefore, in real life,
we would likely start a new stack when the previous stacks exceeds some threshold.

Implement a data structure SetOfStacks that mimics this. SetOfStacks should be composed of several stacks
and should create a new stack once the previous one exceeds capacity.

SetOfStacks should behave identically to a single stack (that is, pop() should return the same
values as it would if there were just a single stack).

Follow-up:

Implement a function popAt(index) which performs a pop operation on a specific sub-stack.
'''

from math import ceil

class set_stack():

    def __init__(self, n = 5):
        self.data = []
        self.max_len = n

    def pop(self):
        return self.pop_at(0)

    def push(self, item):
        if item != None:
            if self.data and len(self.data[0]) == self.max_len:
                self.data.insert(0, [])

            if not self.data: self.data = [[]]

            self.data[0] = [item] + self.data[0]

    def pop_at(self, index):
        
        if len(self.data) <= index: return None
        if len(self.data[index]) <= 0: return None

        value = self.data[index][0]
        
        data = []
        for row, items in enumerate(self.data[index:]):

            for col, val in enumerate(items):
                if row == 0 and col == 0:
                    continue
                data += [val]
        
        new_rows = ceil(len(data) / self.max_len)
        newdata = [[] * self.max_len] * new_rows

        for row in range(0, new_rows):
            begin, end = row * (self.max_len), min(self.max_len * (row + 1), len(data))
            newdata[row] = data[begin:end]

        self.data[index:] = newdata

        return value

    def peek(self):
        return self.data[0][0] if not self.is_empty() else None

    def is_empty(self):
        return len(self.data) == 0

stack = set_stack(3)

stack.push(4)
stack.push(2)
stack.push(-1)

stack.push(5)
stack.push(2)
stack.push(0)

stack.push(3)
stack.push(8)
stack.push(7)

assert stack.is_empty() == False

assert stack.pop_at(1) == 0
assert stack.pop_at(2) == 2

assert stack.pop() == 7

assert stack.pop_at(2) == None

assert stack.pop_at(1) == 5

assert stack.pop() == 8

assert stack.pop_at(1) == 4

assert stack.pop() == 3
assert stack.pop() == 2
assert stack.pop() == -1

assert stack.pop_at(1) == None
