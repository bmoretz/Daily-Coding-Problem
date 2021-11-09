"""
Tower of Hanoi.

The Tower of Hanoi is a puzzle game with three rods and n disks, each with a different size.

All the disks start off on the first rod in a stack. They are ordered by size, with the largest disk on the bottom and the smallest
one at the top.

The goal of this puzzle is to move all the disks from the first rod to the last rod while following these rules:

- You can only move one disk at a time.

- A move consists of taking the uppermost disk from one of the stacks and placing it on top of another stack.

- You cannot place a larger disk on top of a smaller disk.

Write a function that prints out all the steps necessary to complete the Tower of Hanoi. You should assume that the rods are numbered,
with the first rod being 1, the second (aux) being 2, and the last (goal) being 3.
"""

def tower_of_hanoi(n, a='1', b='2', c='3'):
    if n >= 1:
        tower_of_hanoi(n-1, a, c, b)
        move_disk(a, c)
        tower_of_hanoi(n-1, b, c, a)

def move_disk(fp, tp):
    print("moving disk from", fp, "to", tp)


class Tower():
    
    def __init__(self, id, items=[]):
        self._disks = []
        self._id = id

        for item in items:
            self.push(item)

    def push(self, item):
        self._disks = self._disks + [item]

    def peek(self):
        
        return self._disks[0] if self._disks else 0

    def id(self):
        return self._id

    def disks(self):
        return len(self._disks)

    def empty(self):
        return not self._disks

    def top(self):
        return self._disks.pop()

    def moveTop(self, dest):
        disk = self.top()
        print(f'\nmoving {disk} from to tower {dest.id()}')
        dest.push(disk) 

    def moveDisks(self, n, dest, alt):
        if n > 0:
            print(f'\n{self}\n{alt}\n{dest}')
            self.moveDisks(n - 1, alt, dest)
            self.moveTop(dest)
            alt.moveDisks(n - 1, dest, self)

    def __str__(self):

        result = f'tower {self._id} : '
        
        if self._disks:
            n = len(self._disks)
            for index in range(n - 1):
                result += f'{self._disks[index]} | '
            result += str(self._disks[n - 1])
        else:
            result += 'empty'

        return result