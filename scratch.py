'''Queue of Stacks.

Implement a MyQueue class which implements a queue using two stacks.
'''

from problems.stack_queue import Stack


class my_queue1():

  def __init__(self):
    self.data = Stack()
    self.top = None

  def enqueue(self, item):
    
    if item is None: return

    self.data.push(item)

    if self.top == None:
      self.top = item
  
  def dequeue(self):
    
    if self.data.is_empty() : return None

    temp = Stack()

    while not self.data.is_empty():
      temp.push(self.data.pop())

    item = temp.pop()
    self.top = temp.peek()

    while not temp.is_empty():
      self.data.push(temp.pop())

    return item

  def peek(self):
    return self.top

  def is_empty(self):
    return self.data.is_empty()

queue = my_queue1()

assert queue.is_empty()

queue.enqueue(1)
queue.enqueue(2)
queue.enqueue(3)
queue.enqueue(4)
queue.enqueue(5)

assert queue.peek() == 1
assert queue.dequeue() == 1

assert queue.peek() == 2
assert queue.dequeue() == 2

assert queue.peek() == 3
assert queue.dequeue() == 3

queue.enqueue(6)
queue.enqueue(7)
queue.enqueue(8)

assert queue.peek() == 4
assert queue.dequeue() == 4

assert queue.peek() == 5
assert queue.dequeue() == 5

assert queue.peek() == 6
assert queue.dequeue() == 6

assert queue.peek() == 7
assert queue.dequeue() == 7

assert queue.peek() == 8
assert queue.dequeue() == 8

assert queue.is_empty()
