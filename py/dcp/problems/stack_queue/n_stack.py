"""
Three in one.

Use a single array to implement three stacks.
"""

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