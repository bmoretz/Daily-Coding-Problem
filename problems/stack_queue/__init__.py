'''Stack.

push, pop, peek, is_empty.
'''
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

'''Queue.

enqueue, dequeue, peek, is_empty.
'''
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

Given a string of round, curly, and square opening and closing brackets, return whether the brackets are balanced (well-formed).

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
            if stack.is_empty(): 
                return False

            if braces.get(char) == stack.peek():
                stack.pop()

    return stack.is_empty()

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

from collections import deque 
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

'''Sort Stack.

Write a program to sort a stack such that the smallest items are on top. You can use an 
additional temporary stack, but you mat not copy the elements into any other data structure
(such as an array). The stack supports the following operations:

push, pop, peek, and is_empty.
'''

def sort_stack1(stack):

    def shift_min(stack, cutoff):
        temp, maximum, n = Stack(), None, 0

        while not stack.is_empty() and n < cutoff:
            
            current = stack.pop()

            if maximum is None or current > maximum:
                maximum = current

            temp.push(current)
            n += 1
        
        stack.push(maximum)

        while not temp.is_empty():

            current = temp.pop()

            if current == maximum:
                minimum = None
                continue

            stack.push(current)
        
        return stack

    def get_len(stack):

        temp, n = Stack(), 0

        while not stack.is_empty():
            temp.push(stack.pop())
            n += 1

        return (temp, n)

    if stack is None: return

    stack, n = get_len(stack)

    for index in reversed(range(1, n + 1)):
        stack = shift_min(stack, index)

    return stack

'''Animal Shelter.

An animal shelter, which holds only dogs and cats, operates on a strictly "first in, 
first out" basis. People must adopt either the "oldest" (based on arrival time) of 
all animals in the shelter, or they can select whether they would prefer a dog or a cat 
(and will receive the oldest animal of that type). They cannot select which specific 
animal they would like. 

Create the data structures to maintain this system and implement operations such as:

enqueue, dequeueAny, dequeueDog and dequeue cat.

You may use the built-in LinkedList data structure.
'''

''' common types for animal shelters. '''

from enum import Enum
from datetime import datetime

class Species(Enum):
    Dog = 1
    Cat = 2

class Node():

    def __init__(self, data, next=None):
        self.data = data
        self.next = None

class Animal():

    def __init__(self, name, species):
        self.name = name
        self.species = species
        self.arrival_time = datetime.now()

''' Solution 1:

Use a single linked-list to maintain all animals.

pros: single easily extendable for new animal species.
cons: the species specific dequeue methods are slightly less efficient than the two-queue approach.
'''
class AnimalShelter1():

    def __init__(self):
        self.head, self.tail = None, None
 
    def enqueue(self, animal : Animal):
        
        if animal == None: return None

        if not isinstance(animal, Animal):
            raise TypeError(f'Can only accept types of Animal, not {type(animal)}')

        node = Node(animal)

        if self.head == None:
            self.head, self.tail = node, node
        else:
            self.tail.next = node
            self.tail = node

    def dequeue_any(self):
        
        if self.head == None: return None

        adopted = self.head.data
        self.head = self.head.next
        return adopted

    def __dequeue_species(self, species):
        
        current, prev = self.head, None

        while current != None and current.data.species != species:
            prev =  current
            current = current.next

        if current == None: return None
        
        adopted = current.data

        if prev != None:
            prev.next = current.next
        else:
            self.head = current.next

        return adopted

    def dequeue_dog(self):
        return self.__dequeue_species(Species.Dog)

    def dequeue_cat(self):
        return self.__dequeue_species(Species.Cat)


''' Solution 2:

Implement an animal queue class, and composition pattern in the shelter such that
a shelter has N queues, where N is the number of species.

pros: efficient and maintable. Could be improved with a list of queues to be more extendable.
cons: the dequeue_any method could be cleaner.
'''

class AnimalQueue():

    def __init__(self):
        self.head, tail = None, None

    def enqueue(self, animal : Animal):
        node = Node(animal)

        if self.head == None:
            self.head, self.tail = node, node
        else:
            self.tail.next = node
            self.tail = node

    def dequeue(self):
        if self.head == None: return None

        item = self.head.data
        self.head = self.head.next
        return item
    
    def peek(self):
        return self.head.data if self.head != None else None

class AnimalShelter2():

    def __init__(self):
        self.cats, self.dogs = AnimalQueue(), AnimalQueue()
 
    def enqueue(self, animal : Animal):
        
        if animal == None: return

        if not isinstance(animal, Animal):
            raise TypeError(f'Can only accept types of Animal, not {type(animal)}')

        if animal.species == Species.Dog:
            self.dogs.enqueue(animal) 
        elif animal.species == Species.Cat:
            self.cats.enqueue(animal)

    def dequeue_any(self):
        
        if self.dogs.peek() == None and self.cats.peek() == None: return None

        queue = None

        if self.dogs.peek() != None and self.cats.peek() == None:
            queue = self.dogs
        elif self.dogs.peek() == None and self.cats.peek() != None:
            queue = self.cats
        elif self.dogs.peek() != None and self.cats.peek() != None:
            queue = self.dogs if self.dogs.peek().arrival_time < self.cats.peek().arrival_time else self.cats

        return queue.dequeue()

    def dequeue_dog(self):
        return self.dogs.dequeue()

    def dequeue_cat(self):
        return self.cats.dequeue()