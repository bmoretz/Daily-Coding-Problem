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

    '''O(1) max element'''
    def max(self):
        if self._max == None:
            return ValueError("Stack is empty so there is no max value.")

        return self._max[-1]

'''4.2

Given a string of round, curly, and square opening and closing brackers, return whether the brackets are balanced (well-formed).

For example, 

given the string "([])[]({})", return true.
Given the string "([)]" or "((()", you should return false.
'''

def bracket_balanced1(instr):
    braces = {'}' : '{', ')' : '(', ']' : '['}
    stack = Stack()
    
    for char in instr:

        if char in braces.values():
            stack.push(char)
        elif char in braces.keys():
            if stack.length() == 0: 
                return False

            if braces.get(char) == stack.peek():
                stack.pop()

    return stack.length() == 0

def bracket_balanced2(instr):
    stack = []

    for char in instr:
        if char in ["(", "[", "{"]:
            stack.append(char)
        else:
            # Check character is not unmatched
            if not stack:
                return False
        
            # Character is a closing bracket. Check top of stack  matches.
            if (char == ")" and stack[-1] != "(") or \
                (char == "]" and stack[-1] != "[") or \
                (char == "}" and stack[-1] != "{"):
                return False
            stack.pop()

    return len(stack) == 0