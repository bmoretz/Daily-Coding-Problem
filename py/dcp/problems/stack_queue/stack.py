"""
Stack.

push, pop, peek, is_empty.
"""

class Stack():
    
    def __init__(self):
        self.data = []
    
    def push(self, item):
        self.data.append(item)

    def pop(self):
        return self.data.pop() if len(self.data) > 0 else None

    def peek(self):
        return self.data[-1] if len(self.data) > 0 else None

    def is_empty(self):
        return len(self.data) == 0