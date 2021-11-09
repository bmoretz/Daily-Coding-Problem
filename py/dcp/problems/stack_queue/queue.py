"""
Queue.

enqueue, dequeue, peek, is_empty.
"""

class Queue:

    def __init__(self):
        self.data = []

    def enqueue(self, item):
        self.data = [item] + self.data

    def dequeue(self):
        if len(self.data) == 0: return None

        return self.data.pop()
        
    def peek(self):
        return self.data[-1] if len(self.data) > 0 else None

    def is_empty(self):
        return len(self.data) == 0