'''Vanilla Stack'''
class Stack:

    def __init__(self):
        self._stack = []
        self._length = 0

    '''N(1) insert item'''
    def push(self, val):
        self._stack.append(val)
        self._length = self._length + 1

    '''N(1) Remove and return top element'''
    def pop(self):
        if self._length > 0:
            self._length = self._length - 1
            return self._stack.pop()
        else:
            return IndexError("Empty stack, cannot pop element.")

    '''O(1) peek current element'''
    def peek(self):
        return self._stack[-1]

    def length(self):
        return self._length
        
'''4.1

Implement a max stack that has the following methods.

push(val): push val onto the stack
pop: pop off and return the topmost element of the stack. If there are no elements in the stack, throw an error.
max: return the maximum value in the stack currently. If there are no elements in the stack, throw an error.

Each method should run in N(1) time.
'''

class MaxStack(Stack):

    def __init__(self):
        super().__init__()
        self._max = []

    def push(self, val):
        super().push(val)

        if self._max:
            self._max.append(max(val, self._max[-1]))
        else:
            self._max.append(val)

    def pop(self):
        return super().pop()

    def max(self):
        if self._max == None:
            return ValueError("Stack is empty so there is no max value.")

        return self._max[-1]