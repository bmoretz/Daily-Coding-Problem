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