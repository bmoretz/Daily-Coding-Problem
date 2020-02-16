'''Fenwick tree.

You are given an array of length 24, where each element represents the number of new subscribers during the corresponding hour. 
Implement a data structure that efficiently supports the following:

update (hour, value): increment the element at index hour by value.

query(start, end) retrieve the numbner of subscribers that have signed up between start and end (inclusive).

You can assume that all values get cleared at the end of the day, and that you will not be asked for start and end values
that wrap around midnight.
'''

'''naive O(N) solution. '''
class Subscribers1():

    def __init__(self, nums):

        self.counter = {index : value for index, value in enumerate(nums)}

    def update(self, hour, value):
        
        self.counter[hour] += value

    def query(self, start, end):
        values = [self.counter[index] for index in range(start, end + 1)]
        return sum( values )


class BIT:
    def __init__(self, nums):
        # Prepend a zero to our array to use lowest set bit trick.
        self.tree = [0 for _ in range(len(nums) + 1)]
        for i, num in enumerate(nums):
            self.update(i + 1, num)

    def update(self, index, value):
        while index < len(self.tree):
            self.tree[index] += value
            index += index & -index

    def query(self, index):
        total = 0
        while index > 0:
            total += self.tree[index]
            index -= index & -index
        return total

'''O(log n) solution. '''
class Subscribers2:
    
    def __init__(self, nums):
        self.bit = BIT(nums)
        self.nums = nums

    def update(self, hour, value):
        self.bit.update(hour, value - self.nums[hour])
        self.nums[hour] = value

    def query(self, start, end):
        # Shift start and end indices forward as our array is 1-based.
        return self.bit.query(end + 1) - self.bit.query(start)