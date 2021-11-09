"""
Queue of Stacks.

Implement a MyQueue class which implements a queue using two stacks.
"""

from .stack import Stack

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