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
        self._data = []
        self._id = id

        for item in items:
            self.push(item)

    def push(self, item):
        self._data = [item] + self._data

    def peek(self):
        
        return self._data[0] if self._data else 0

    def id(self):
        return self._id

    def empty(self):
        return not self._data

    def top(self):
        return self._data.pop()

    def __str__(self):

        result = f'tower {self._id} : '
        
        if self._data:
            n = len(self._data)
            for index in range(n - 1):
                result += f'{self._data[index]} | '
            result += str(self._data[n - 1])
        else:
            result += 'empty'

        return result

def hanoi(src, alt, dest):
    
    def move(src, dest):
        disk = src.top()
        print(f'\nmoving {disk} from tower {src.id()} to tower {dest.id()}')
        dest.push(disk)

    print(f'\n{src} \n {alt} \n {dest}')

    if src.peek() > dest.peek():
        move(src, dest)
    elif src.peek() > alt.peek():
        move(src, alt)

    if not src.empty():
        hanoi(src, alt, dest)
    else:
        print('done')
        print(f'\n{src} \n {alt} \n {dest}')

src, alt, dest = Tower(1, [1, 2]), Tower(2), Tower(3)

hanoi(src, alt, dest)