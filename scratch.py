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

class set_stack():

    def __init__(self, n = 5):
        self.data = []
        self.max_len = n

    def pop(self):
        
        if self.is_empty(): return None

        value = self.data[0]

        self.data = self.data[1:]

        return value

    def push(self, item):
        
        if item != None:
            self.data = [item] + self.data

    def pop_at(self, index):
        
        offset = self.max_len * index
        
        if offset >= len(self.data): return None

        value = self.data[offset]

        self.data = self.data[:offset] + self.data[offset + 1:]

        return value

    def peek(self):
        return self.data[0] if not self.is_empty() else None

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
