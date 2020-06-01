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

def two_sum_brute(arr, lower, upper):
    '''
    brute force approach to the 2-sum problem

    (...will probably never finish in my life-time for
    challenge dataset.)

    this is just an overall blue-print for the strategy
    for solving the challenge set.
    '''

    targets = set(range(lower, upper + 1))
    solutions = set()

    for index in range(len(arr)):

        x = arr[index]

        for sub in range(index + 1, len(arr)):

            y = arr[sub]

            t = x + y

            if t in targets:
                solutions.add( t )

    return len(solutions)

def find(arr, target, start, end):
    '''
    find - a binary search based search routine.

    this is a utility method to help us in the binary
    version of the two-sum algorithm. It takes a target
    number and returns the index of it if it's found,
    if it's not found, it returns the last index searched.

    The important thing in this method is that the following
    invariant will always hold after a search is performed:

    Given an array A and a value v, find(A, v) <= the the index
    of v if it existed in the array.

    This basically means that we can search for a value, and even
    if it doesn't exists in the array, the returned result will
    be the absolute minimum possible location of the value.
    '''
    if start >= end: return start

    mid = start + (end - start)//2

    if arr[mid] == target:
        return mid
    if target < arr[mid]:
        return find(arr, target, start, mid)
    else:
        return find(arr, target, mid + 1, end)

def two_sum_bin(arr, lower, upper):
    '''
    binary two-sum

    this approach leverages a binary search method
    to drastically cut-down on the number of values
    to search the solution set for.

    the overall idea is to:

        sort the array smallest to biggest
        build a lookup of all possible solutions -> (lower, upper)
        a look-up of arr values to their location in the sorted version of the array
        
        start with a given element

        in order for y to be a solution to t = x + y, where t in (lower, upper)
        the lowest possible value for y is upper - x and the highest possible
        value for y is upper - x.

        So we limit the search range of y in the sub loop to the indices that
        correspond to those values in the array. If any of them match (t in 
        solution set) we add t to the solution set.

        finally, return the length of the unique solution set.
    '''

    s_arr = sorted(arr)
    targets = set(range(lower, upper + 1))
    solutions = set()
    index_lookup = defaultdict(int)

    n = len(arr)

    for index in range(len(arr)):

        x = arr[index]

        l, u = lower - x, upper - x

        if l not in index_lookup:
            index_lookup[l] = find(s_arr, l, 0, n)

        if u not in index_lookup:
            index_lookup[u] = find(s_arr, u, 0, n)

        start_loc, end_loc = index_lookup[l], index_lookup[u]

        for sub in range(start_loc, end_loc + 1):
            
            if sub == n:
                continue
            
            y = s_arr[sub]

            t = x + y

            if t in targets:
                solutions.add( t )

    return len(solutions)

def two_sum_hash(arr, lower, upper):
    '''
    two-sum hash

    this is an upgraded version of the brute force approach that
    leverages a hash set to keep track of the solution sets. Still
    slow as molasses.
    '''
    ys = set(arr)
    solutions = defaultdict(set)
    targets = set(range(lower, upper + 1))

    for x in arr:
        for t in targets:
            if x - t in ys:
                if x == t - x:
                    continue
            solutions[t] = set([tuple(sorted([x, t - x]))])

    return len(solutions)

def run_test_file(approach):

    lower, upper = 3, 10

    numbers = read_two_sum_data(test_file_path)

    return approach(numbers, lower, upper)

def run_submission(approach):

    lower, upper = -10000, 10000

    numbers = read_two_sum_data(submission_file_path)

    return approach(numbers, lower, upper)

def run_benchmark(iters=1):

    data = read_two_sum_data(test_file_path)

    for approach in [two_sum_hash, two_sum_bin]:
    
        times = []

        for _ in range(iters):

            start = time.time()
            
            approach(data)

            end = time.time()

            times += [end - start]

        avg_time = sum(times)/len(times)

        print(f'{approach.__name__} - Results: Ran {iters} iterations with average execution time: {avg_time}.')

run_benchmark()