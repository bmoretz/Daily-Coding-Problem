'''Queue of Stacks.

Implement a MyQueue class which implements a queue using two stacks.
'''

class my_queue1():

    def __init__(self):
        self.stack = []

    def enqueue(self, item):
        
        if item == None: return

        self.stack = [item] + self.stack

    def dequeue(self):
        
        if self.stack == []: return None

        top = self.stack.pop()

        queue = []

        while self.stack:
            queue.append(self.stack.pop())
        
        stack = []

        for item in queue:
            stack = [item] + stack

        self.stack = stack

        return top

    def peek(self):
        return self.stack[len(self.stack) - 1] if self.stack else None

    def is_empty(self):
        return self.stack == []

queue = my_queue1()

queue.enqueue(1)

assert queue.dequeue() == 1

assert queue.is_empty() == True

queue.enqueue(2)

assert queue.peek() == 2

queue.enqueue(3)

assert queue.peek() == 2

queue.enqueue(4)

assert queue.peek() == 2

queue.enqueue(5)

assert queue.peek() == 2

assert queue.is_empty() == False