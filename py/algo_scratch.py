'''
In this programming problem and the next you'll code up the knapsack algorithm from lecture.

Let's start with a warm-up. Download the text file below.

This file describes a knapsack instance, and it has the following format:

[knapsack_size][number_of_items]

[value_1] [weight_1]

[value_2] [weight_2]

...

For example, the third line of the file is "50074 659", indicating that the second item has value 50074 and size 659, respectively.

You can assume that all numbers are positive. You should assume that item weights and the knapsack capacity are integers.

In the box below, type in the value of the optimal solution.

ADVICE: If you're not getting the correct answer, try debugging your algorithm using some small test cases. And then post them to the discussion forum!
'''

import os
import heapq
from copy import copy
from collections import defaultdict, namedtuple
from ast import literal_eval as make_tuple

data_dir = os.getcwd() + '\\data\\illuminated\\knapsack\\'

submission_file_path = data_dir + 'knapsack1.txt'
big_submission_file_path = data_dir + 'knapsack_big.txt'

test_file_path = data_dir + 'problem16.7test.txt'

Item = namedtuple("Item", 'value size')

def read_knapsack(file_path):

    def parse_line(line):
        return [int(x) for x in line.split(' ')]

    def make_item(line):
        v, s = parse_line(line)
        return Item(value = v, size = s)
        
    with open(file_path, 'r') as f:

        lines = f.read().splitlines()

        s, c = parse_line(lines[0])

        items, index = [None] * c, 0

        for line in lines[1:]:
            items[index] = make_item(line)
            index += 1

        assert len(items) == c

    return (s, c, items)

def knapsack_fast(knapsack):
    
    capacity, count, items = knapsack

    optimal, weights = [0] * (capacity), [0] * (capacity)

    for index, item in enumerate(items):

        weights[item.size] = optimal[item.size]

        for x in range(item.size, capacity):
            exclude = optimal[x]

            include = optimal[x-item.size] + item.value

            if include > exclude:
                weights[x] = include
        
        optimal = copy(weights)

    return optimal[-1]

def knapsack_brute(knapsack):
    capacity, count, items = knapsack

    solutions = [[None for c in range(capacity)] for n in range(count)]

    for index in range(capacity):
        solutions[0][index] = 0

    for index in range(1, count):
        for storage in range(capacity):
            item = items[index]

            if item.size > storage:
                solutions[index][storage] = solutions[index - 1][storage]
            else:
                case1, case2 = solutions[index - 1][storage], solutions[index - 1][storage - item.size] + item.value
                solutions[index][storage] = max(case1, case2)

    return solutions[count - 1][capacity - 1]

knapsack = read_knapsack(submission_file_path)
result = knapsack_fast(knapsack)
print(result)