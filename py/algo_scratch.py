'''
In this assignment you will implement one or more algorithms for the all-pairs shortest-path problem. Here are data files describing three graphs:

The first line indicates the number of vertices and edges, respectively. Each subsequent line describes an edge (the first two numbers are its tail and head, respectively) and its length (the third number). NOTE: some of the edge lengths are negative. NOTE: These graphs may or may not have negative-cost cycles.

Your task is to compute the "shortest shortest path". Precisely, you must first identify which, if any, of the three graphs have no negative cycles. For each such graph, you should compute all-pairs shortest paths and remember the smallest one (i.e., compute \min_{u,v \in V} d(u,v)min 
u,v∈V
​	
 d(u,v), where d(u,v)d(u,v) denotes the shortest-path distance from uu to vv).

If each of the three graphs has a negative-cost cycle, then enter "NULL" in the box below. If exactly one graph has no negative-cost cycles, then enter the length of its shortest shortest path in the box below. If two or more of the graphs have no negative-cost cycles, then enter the smallest of the lengths of their shortest shortest paths in the box below.

OPTIONAL: You can use whatever algorithm you like to solve this question. If you have extra time, try comparing the performance of different all-pairs shortest-path algorithms!

OPTIONAL: Here is a bigger data set to play with.
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