'''Three in one.

Use a single array to implement three stacks.
'''

class tristack():

    def __init__(self):
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

stack = tristack()

assert stack.is_empty(0) == True
assert stack.is_empty(1) == True

assert stack.peek(0) == None

stack.push(0, "A")

assert stack.pop(0) == "A"

assert stack.is_empty(0) == True

stack.push(1, "B")
stack.push(0, "A")

assert stack.is_empty(1) == False
assert stack.peek(0) == "A"
assert stack.peek(1) == "B"
assert stack.is_empty(2) == True

stack.push(0, "D")
stack.push(1, "B")
stack.push(2, "C")

assert stack.peek(2) == "C"

assert stack.pop(2) == "C"

stack.push(0, "D")

assert stack.pop(0) == "D"

assert len(stack.data) == 6
