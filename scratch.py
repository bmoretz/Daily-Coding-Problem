from problems.stack_queue import Stack, MaxStack

from random import randint

'''4.1

Implement a max stack that has the following methods.

push(val): push val onto the stack
pop: pop off and return the topmost element of the stack. If there are no elements in the stack, throw an error.
max: return the maximum value in the stack currently. If there are no elements in the stack, throw an error.

Each method should run in N(1) time.
'''

stack = MaxStack()

for _ in range(0, 10):
    stack.push( randint(0, 100) )

for _ in range(stack.length()):
    print( stack.max() )

print(stack.length())