'''
In this assignment you will implement one or more algorithms for the traveling salesman problem, such as the dynamic programming 
algorithm covered in the video lectures. Here is a data file describing a TSP instance.

tsp.txt
The first line indicates the number of cities. Each city is a point in the plane, and each subsequent line indicates the x- and y-coordinates of a single city.

The distance between two cities is defined as the Euclidean distance --- that is, two cities at locations
(x, y)(x, y) and (z, w)(z, w) have distance \sqrt{(x-z)^2 + (y-w)^2}(x−z)^2+(y−w) 2 between them.

In the box below, type in the minimum cost of a traveling salesman tour for this instance, rounded down to the nearest integer.

OPTIONAL: If you want bigger data sets to play with, check out the TSP instances from around the world here. The smallest data set (Western Sahara) has 29 cities, and most of the data sets are much bigger than that. What's the largest of these data sets that you're able to solve --- using dynamic programming or, if you like, a completely different method?

HINT: You might experiment with ways to reduce the data set size. For example, trying plotting the points. Can you infer any structure of the optimal solution? Can you use that structure to speed up your algorithm?


'''

import os, math
import numpy as np
import matplotlib.pyplot as plt

from collections import defaultdict, namedtuple
from tqdm import tqdm
from itertools import permutations

City = namedtuple('City', 'x y id')

data_dir = os.getcwd() + '\\data\\illuminated\\tsp\\'

submission_file_paths = data_dir + 'tsp.txt'
test_file_path = data_dir + 'tsptest3.txt'

def read_cities(file_path):

    print(f'processing {file_path}')
    
    with open(file_path) as f:
        lines = f.readlines()

    n_cities = int(lines[0])
    
    print(f'number of cities: {n_cities}')

    cities = list()
    index = 0
    for line in lines[1:]:
        x, y = map(float, line.split())
        cities += [City(x=x, y=y, id=index)]
        index += 1

    assert len(cities) == n_cities, 'length of cities does not match'
    return cities

def calculate_distance_matrix(cities):

    n = len(cities)
    distances = [[None for _ in range(n)] for _ in range(n)]

    for i in range(n):
        outer = cities[i]
        for j in range(n):
            inner = cities[j]

            distances[i][j] = math.sqrt(pow(outer.x - inner.x, 2) + pow(outer.y - inner.y, 2))

    return distances

def lexicographical_permutation(input):
    results = set()
    for perm in [''.join(chars) for chars in permutations(input)]:
        results.add(perm)
    return results
    
test ='00000011'
perms = lexicographical_permutation(test)
print(perms)

def find_minimum_cost_tour(cities, distances):

    num_points = len(cities)
    num_subsets = 1 << num_points

    # build lookup table for all cities
    lookup_table = [[float('inf') for _ in range(num_points)] for _ in range(num_subsets)]
    # base case
    lookup_table[1][0] = 0

    for size in range(2, num_points):

        mask_str = str('1' * size) + str('0' * (num_points - size))

        mask_permutations = lexicographical_permutation(mask_str)

        for perm in mask_permutations:

            if perm[0] == '0':
                continue
            
            bitmask = 1

            for index in range(num_points):
                if mask_str[index] == '1':
                    bitmask = bitmask | 1 << index

            for index in range(1, num_points):

                if (((bitmask >> index) & 1) == 1):

                    rev_bitmask = bitmask ^ (2 << index)

                    min_cost = float('inf')

                    for k in range(num_points):

                        if (((rev_bitmask >> k) & 1) == 1):
                            a, b = lookup_table[rev_bitmask][k], distances[k][index]

                            min_cost = min(a + b, min_cost)

                lookup_table[bitmask][index] = min_cost

    min_cost = float('inf')
    complete_set = num_subsets - 1

    for index in range(2, num_points):
        min_cost = min(lookup_table[complete_set][index] + distances[index][0], min_cost)

    return min_cost

def plot_cities(cities):

    data = np.array([[c.x, c.y, c.id] for c in cities])

    fig, ax = plt.subplots()

    scatter = ax.scatter(data[:, 0], data[:, 1], label=data[:, 2])

    ax.grid()
    plt.show()

cities = read_cities(test_file_path)

# plot_cities(cities)

distances = calculate_distance_matrix(cities)

min_cost_tour = find_minimum_cost_tour(cities, distances)
print(min_cost_tour)