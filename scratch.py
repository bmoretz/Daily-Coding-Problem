'''Minstack.

How would you design a stack that, in addition to push and pop, has a function min which returns the minimum element?

Push, Pop and Min should all operate in O(1) time.
'''

class minstack():

    def __init__(self, n = 3):
        self.data = []
        self.minval = []

    def pop(self):

        if self.is_empty(): return None

        value = self.data[0]
        self.data = self.data[1:]
        
        if value == self.minval[0] and len(self.minval) > 0:
            self.minval = self.minval[1:]

        return value

    def push(self, item):
        if item != None:
            self.data = [item] + self.data
            
            if len(self.minval) == 0 or item < self.minval[0]:
                self.minval = [item] + self.minval

    def peek(self):
        return self.data[0] if not self.is_empty() else None

    def min(self):
        return self.minval[0] if not self.is_empty() else None

    def is_empty(self):
        return len(self.data) == 0

stack = minstack()

stack.push(4)
stack.push(2)
stack.push(-1)
stack.push(5)
stack.push(2)
stack.push(0)

assert stack.is_empty() == False
assert stack.min() == -1
assert stack.peek() == 0

assert stack.pop() == 0
assert stack.min() == -1

assert stack.pop() == 2
assert stack.min() == -1

assert stack.pop() == 5
assert stack.min() == -1

assert stack.pop() == -1
assert stack.min() == 2

assert stack.pop() == 2
assert stack.min() == 4
assert stack.pop() == 4

assert stack.is_empty() == True