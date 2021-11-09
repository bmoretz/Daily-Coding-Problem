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

'''
Solution 1:

This implementation uses a list of lists for the underlying data structure in
order to satisfy the requirement of having no underlying stack having a length
greater than the specified n.

pros: the mem size of no individual stack is ever greater than what is specified in the instance
constructor.

cons: the runtime complexity of adding and removing elements from the substacks are linear in total stack size.
'''

from math import ceil
class set_stack1():

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

'''
Solution 2:

This implementation uses a single array to old the data of the
individual stacks. This satisfies the requirement of having a pop_at(index)
method avaliable.

pros: straight forward implementation using index/offset array look-up.

cons: the memory complexity is not broken up into different segments.
'''
class set_stack2():

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