'''
The goal of this problem is to implement a variant of the 2-SUM algorithm covered in this week's lectures.

The file contains 1 million integers, both positive and negative (there might be some repetitions!).This is your array of integers, with the i^th row of the file specifying the i^th entry of the array.

Your task is to compute the number of target values tt in the interval [-10000,10000] (inclusive) such that there are distinct numbers x,y in the input file that satisfy x+y=t, x+y=t. 
(NOTE: ensuring distinctness requires a one-line addition to the algorithm from lecture.)

Write your numeric answer (an integer between 0 and 20001) in the space provided.

OPTIONAL CHALLENGE: If this problem is too easy for you, try implementing your own hash table for it. For example, you could compare performance under the chaining and open addressing approaches to resolving collisions.
'''

import os

data_dir = os.getcwd() + '\\data\\illuminated\\two-sum\\'

submission_file_path = data_dir + 'algo1-programming_prob-2sum.txt'
test_file_path = data_dir + 'problem12.4test.txt'

from collections import defaultdict
from time import time

def read_two_sum_data(file_path):
    ''' read numbers

    this function simply reads the passed in test data file and
    converts the lines to integers.
    '''

    result = []

    with open(file_path, 'r') as f:

        lines = f.read().splitlines()

        for line in lines:
            result.append(int(line))

    return result

def two_sum(arr, lower, upper):

    results = set()

    rank = defaultdict(int)

    s_arr = sorted(arr)

    index = 0
    for element in s_arr:
        if element in rank:
            continue

        rank[element] = index
        index += 1

    processed = set()

    for index in range(len(arr)):

        x = s_arr[index]

        if x in processed or x in results:
            continue

        l, u = lower - x, upper - x
        
        for sub in range(u, l):
            result.add( s_arr[sub] )

        processed.add(x)

    return result

def run_test_file(approach):

    lower, upper = 3, 10

    numbers = read_two_sum_data(test_file_path)

    return approach(numbers, lower, upper)

def run_submission(approach):

    lower, upper = -10000, 10000

    numbers = read_two_sum_data(submission_file_path)

    return approach(numbers, lower, upper)

def run_benchmark(iters=30):

    data = read_two_sum_data(submission_file_path)

    for approach in [two_sum]:
    
        times = []

        for _ in range(iters):

            start = time.time()
            
            approach(data)

            end = time.time()

            times += [end - start]

        avg_time = sum(times)/len(times)

        print(f'{approach.__name__} - Results: Ran {iters} iterations with average execution time: {avg_time}.')
        


# a1, a2 = run_submission(median_arr), run_submission(median_heap)

# assert a1 == a2

# result = run_test_file(median_heap)

# run_benchmark()

#

lower, upper = 3, 10

arr = numbers = read_two_sum_data(test_file_path)

l_bounds, u_bounds = defaultdict(int), defaultdict(int)

n, s_arr = len(arr), sorted(arr)

for index, element in enumerate(s_arr):
    l_bounds[element] = n - index
    u_bounds[element] = index

total = 0

for index in range(len(s_arr)):

    x = s_arr[index]

    l, u = lower - x, upper - x

    total += l_bounds[ l ] - u_bounds[ u ]