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

'''Disjoint-set.

A classroom consists of n students, whose friendships can be represented in an adjacency list. For example, the following describes
a situation where 0 is friends with 1 and 2, 3 is friends with 6, and so on.

{ 0: [1, 2],
  1: [0, 5],
  2: [0],
  3: [6],
  4: [],
  5: [1],
  6: [3]
}

Each student can be placed in a friend group, which can be defined as the transitive closure of that student's relations. In other words,
this is the smallest set such that no student in the group has any friends outside this group. For the example above, the friend group
would be:

{0, 1, 2, 5}, {3, 6}, {4}

Given a friendship list such as the one above, determine the number of friend groups in the class.
'''


class DisjointSet:

    def __init__(self, n):
        self.sets = list(range(n))
        self.sizes = [1] * n
        self.count = n

    def union(self, x, y):
        x, y = self.find(x), self.find(y)

        if x != y:
            # Union by size: always add students to the bigger set.

            if self.sizes[x] < self.sizes[y]:
                x, y = y, x

            self.sets[y] = x
            self.sizes[x] += self.sizes[y]
            self.count -= 1

    def find(self, x):
        group = self.sets[x]

        while group != self.sets[group]:
            group = self.sets[group]

        # Path compression: reassign x to the correct group.
        self.sets[x] = group

        return group

def friend_groups(students):

    groups = DisjointSet(len(students))

    for student, friends in students.items():
        for friend in friends:
            groups.union(student, friend)

    return groups.count