from collections import deque

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
        
'''Max stack.

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

'''Is Well-Formed?

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

'''Compute maximum of k-length subarrays.

Given an array of integers and a number k, where 1 <= k <= array length, compute the maximum value of each subarray of lengh k.

For example, let's say the array is 

[10, 5, 2, 7, 8, 7] and k = 3. 

We should get [10, 7, 8, 8]

Since,

10 = max(10, 5, 2),
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)

Do this in O(n) time and O(k) space. You can modify the input array in-place and you do not need to store the results. You can simply print them out as you compute them.
'''

'''O(n * k) Solution'''
def max_subarray1(arr, k):
    start, end, results = 0, k, []

    while end < ( len(arr) + 1 ):
        sub = arr[start:end]
        results.append(max(sub))

        start, end = start + 1, end + 1

    return results

'''O(n * k) Solution'''
def max_subarray2(arr, k):
    results = []
    for i in range(len(arr) - k + 1):
        results.append(max(arr[i:i + k]))
    return results

'''O(n) Solution'''
def max_subarray3(arr, k):
    q, result = deque(), []
    
    for i in range(k):
        while q and arr[i] >= arr[q[-1]]:
            q.pop()
        q.append(i)

    # Loop invariant: q is a list of indices where their
    # corresponding values are in descending order.
    for i in range(k, len(arr)):
        result.append( arr[q[0]] )

        while q and q[0] <= i - k:
            q.popleft()

        while q and arr[i] >= arr[q[-1]]:
            q.pop()
        q.append(i)

    result.append( arr[q[0]] )

    return result

'''Three in one.

Use a single array to implement three stacks.
'''

'''Approach #1.

This approach uses a single array with empty elements
to offset each individual stacks elements inside the single
backing array.

pros: simple, easily extendable relatively efficient.
cons: potentially lots of empty space unused.
'''

class nstack1():

    def __init__(self, n = 3):
        self.n_stacks = n
        self.data = []
        self.lengths = [0] * self.n_stacks
    
    def pop(self, index):
        self.__check_index_range(index)

        if self.is_empty(index): return None

        value = self.__top()[index]
        self.data[index] = None
        self.lengths[index] -= 1

        if all(v is None for v in self.__top()):
            self.data = self.data[self.n_stacks:]

        return value

    def push(self, index, item):
        self.__check_index_range(index)
        
        capacity = len(self.data) / self.n_stacks

        if self.lengths[index] >= capacity:
            values = [None] * self.n_stacks
            values[index] = item

            self.data = values + self.data

            self.lengths[index] += 1
        else:
            offset = self.lengths[index] + index
            self.data[offset] = item
            self.lengths[index] += 1

    def peek(self, index):
        self.__check_index_range(index)

        if self.lengths[index] <= 0:
            return None

        return self.__top()[index]

    def is_empty(self, index):
        self.__check_index_range(index)

        return self.lengths[index] == 0

    def __check_index_range(self, index):
        if index < 0 or index > self.n_stacks: 
            raise IndexError(f'{index} is not a valid index.')

    def __top(self):
        return self.data[:self.n_stacks]

'''Approach #2.

This approach uses a single array to hold all the
elements of the substacks and lengths of each
individual substack to rotate the array for push and pop
operations, such that the currently modified substack
is always at the tail of the array.

pros: space efficient, 
cons: rotate is
'''
class nstack2():

    def __init__(self, n = 3):
        self.n_stacks = n
        self.data = []
        self.lengths = [0] * self.n_stacks
        self.current = 0

    def pop(self, index):
        self.__check_index_range(index)

        if self.is_empty(index): return None

        if index != self.current:
            self.__rotate(index)
        
        value = self.data[0]
        self.data = self.data[1:]
        self.lengths[index] -= 1

        return value

    def push(self, index, item):
        self.__check_index_range(index)
        
        if self.current != index and self.lengths[index] != 0:
            self.__rotate(index)
        
        self.current = index
        self.data = [item] + self.data
        self.lengths[index] += 1

    def peek(self, index):
        self.__check_index_range(index)

        if self.lengths[index] == 0: return None

        if self.current != index:
            rotations = self.__get_rotations(index)

            return self.data[rotations:][0]
        else:
            return self.data[0]

    def is_empty(self, index):
        self.__check_index_range(index)

        return self.lengths[index] <= 0

    def __check_index_range(self, index):
        if index < 0 or index > self.n_stacks: 
            raise IndexError(f'{index} is not a valid index.')

    def __get_rotations(self, index):
        return sum([element for i, element in enumerate(self.lengths) if i != index])

    def __rotate(self, index):
        
        places = self.__get_rotations(index)

        self.data = self.data[places:] + self.data[:places]

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