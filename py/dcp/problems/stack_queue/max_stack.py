"""Max stack.

Implement a max stack that has the following methods.

push(val): push val onto the stack
pop: pop off and return the topmost element of the stack. If there are no elements in the stack, throw an error.
max: return the maximum value in the stack currently. If there are no elements in the stack, throw an error.

Each method should run in N(1) time.
"""

from .stack import Stack

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

    '''O(1) max element'''
    def max(self):
        if self._max == None:
            return ValueError("Stack is empty so there is no max value.")

        return self._max[-1]