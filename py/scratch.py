'''Towers of Hanoi.

In the classic problem of the Towers of Hanoi, you have 3 towers
and N disks of different sizes which can slide onto any tower. The
puzzle starts with disks sorted in ascending order of size from
top to bottom (i.e., each disk sits on top of an even larger one).

You have the following constraints:

1.) Only one disk can be moved at a time.
2.) A disk is slid off the top of one tower onto another tower.
3.) A disk cannot be placed on top of a smaller disk.

Write a program to move the disks from the first tower to the last using stacks.
'''

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
        print(f'\nmoving {disk} from tower {src.id()} to tower {dest.id()}')
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

def hanoi(src, dest, alt):
    
    print(f'\n{src}\n{alt}\n{dest}')
    src.moveDisks(src.disks(), alt, dest)
    print(f'\n{src}\n{alt}\n{dest}')

src, alt, dest = Tower(1, [3, 2, 1]), Tower(2), Tower(3)

hanoi(src, alt, dest)