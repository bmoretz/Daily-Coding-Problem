"""Circus Tower.

A circus is designing a tower routine consisting of people standing
atop one another's shoulders. For practical and aesthetic reasons,
each person must be both shorter and lighter than the person below
him or her. Given the heights and weights of each person in the circus,
write a method to compute the largest possible number of people in such
a tower.

EXAMPLE

Input (ht, wt): 

(65, 100), (70, 150), (56, 90), (75, 190), (60, 95), (68, 110)

Output: The longest tower is length 6 and includes from top to bottom:

(56, 90) (60, 95), (65, 100), (68, 110), (70, 150), (75, 190)
"""

import copy

class CircusTower():
    
    class Person():
        def __init__(self, height, weight):
            self.height = height
            self.weight = weight

        def __lt__(self, other):
            return self.height < other.height and \
                self.weight < other.weight
        
        def __format__(self, format_spec):
            return f'({self.height}, {self.weight})'

        def __repr__(self):
            return f'({self.height}, {self.weight})'

    def __init__(self):
        self.people = []

    def to_tuple(self, values):
        return [(p.height, p.weight) for p in values]

    def max_tower(self):
        
        tower = []

        height_order = sorted(self.people, key=lambda p: p.height)
        
        solutions, best = [], None

        for index in range(len(height_order)):
            longest = self.best_seq(height_order, solutions, index)
            solutions += [(index, longest)]
            best = longest if not best or len(best) < len(longest) else best

        return self.to_tuple(best) if best else None

    def best_seq(self, people, solutions, index):

        current = people[index]
        bestSeq = []

        for i in range(index):
            _, prev = solutions[i]

            if prev[-1] < current:
                bestSeq = prev if not bestSeq or len(prev) > len(bestSeq) else bestSeq

        best = copy.copy(bestSeq)
        best += [current]

        return best

    def add_person(self, weight, height):
        self.people +=[self.Person(weight, height)]