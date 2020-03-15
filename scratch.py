'''Three in one.

Use a single array to implement three stacks.
'''

class nstack():

    def __init__(self, n = 3):
        self.n_stacks = 3
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

stack = nstack(3)

stack.push(0, 'A')
stack.push(1, 'B')
stack.push(2, 'C')

stack.push(0, 'B')

assert stack.pop(0) == 'B'

assert len(stack.data) == 3

assert nstack.data == ['C', 'B', 'A']
