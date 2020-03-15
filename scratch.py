'''Three in one.

Use a single array to implement three stacks.
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
        return sum([element for i, element in enumerate(self.lengths) if i != self.current])

    def __rotate(self, index):
        
        places = self.__get_rotations(index)

        self.data = self.data[places:] + self.data[:places]

stack = nstack2()

stack.push(0, 'A')
stack.push(0, 'A')
stack.push(0, 'A')

stack.push(1, 'B')

stack.push(2, 'C')

stack.push(0, 'A')

assert stack.pop(0) == 'A'

assert stack.pop(1) == 'B'

assert stack.pop(2) == 'C'

assert stack.pop(0) == 'A'
assert stack.pop(0) == 'A'
assert stack.pop(0) == 'A'

assert stack.is_empty(0)
assert stack.is_empty(1)
assert stack.is_empty(2)

assert stack.data == []