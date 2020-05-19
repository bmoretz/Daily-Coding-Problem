import os

'''
The file contains an adjacency list representation of an undirected weighted graph with 200 vertices labeled 1 to 200. Each row consists of the node tuples that are 
adjacent to that particular vertex along with the length of that edge. For example, the 6th row has 6 as the first entry indicating that this row corresponds to the vertex
labeled 6. The next entry of this row "141,8200" indicates that there is an edge between vertex 6 and vertex 141 that has length 8200. The rest of the pairs of this row 
indicate the other vertices adjacent to vertex 6 and the lengths of the corresponding edges.

Your task is to run Dijkstra's shortest-path algorithm on this graph, using 1 (the first vertex) as the source vertex, and to compute the shortest-path distances between 1 
and every other vertex of the graph. If there is no path between a vertex vv and vertex 1, we'll define the shortest-path distance between 1 and vv to be 1000000.

You should report the shortest-path distances to the following ten vertices, in order: 7,37,59,82,99,115,133,165,188,197. You should encode the distances as a comma-separated 
string of integers. So if you find that all ten of these vertices except 115 are at distance 1000 away from vertex 1 and 115 is 2000 distance away, then your answer should be 
1000,1000,1000,1000,1000,2000,1000,1000,1000,1000. Remember the order of reporting DOES MATTER, and the string should be in the same order in which the above ten vertices are 
given. The string should not contain any spaces. Please type your answer in the space provided.

IMPLEMENTATION NOTES: This graph is small enough that the straightforward O(mn)O(mn) time implementation of Dijkstra's algorithm should work fine. OPTIONAL: For those of you seeking an 
additional challenge, try implementing the heap-based version. Note this requires a heap that supports deletions, and you'll probably need to maintain some kind 
of mapping between vertices and their positions in the heap.
'''

data_dir = os.getcwd() + '\\data\\illuminated\\median-maintenance\\'

submission_file_path = data_dir + 'Median.txt'
test_file_path = data_dir + 'problem11.3test.txt'

from collections import defaultdict
import heapq, time

class HeapMin():

    def __init__(self):
        self.lower = [] # max heap
        self.upper = [] # min heap

    def push(self, num):
    
        # populate the low (max) heap first.
        if len(self.lower) <= len(self.upper):
            heapq.heappush(self.lower, -num)
        else:
            heapq.heappush(self.upper, num)

        if self.lower and self.upper:

            # if the lower heap top is greater than
            # the pushed number, we need to swap the
            # heap values.

            if -self.lower[0] > self.upper[0]:
                # pop & invert the lower (max) heap
                x, y = -heapq.heappop(self.lower), heapq.heappop(self.upper)

                heapq.heappush(self.lower, -y)
                heapq.heappush(self.upper, x)
            
            # invariant that every element in the lower heap
            # is less than or equal to the min element in the
            # upper (min) heap.

            assert -self.lower[0] <= self.upper[0]

    def median(self):
        return -self.lower[0]

def median_arr(arr):
    ''' median arr
    
    brute force approach for benchmarking purposes.
    '''

    tally, medians = [], []

    for num in arr:
        tally.append(num)
        tally = sorted(tally)

        n = len(tally)

        position = n//2 if n % 2 == 0 else (n+1)//2

        medians.append(tally[position - 1])

    total = sum(medians)

    return total % 10000

def median_heap(arr):
    ''' median heap
    
    heapify'd approach for median maintenance problem.
    '''

    tally, medians = HeapMin(), []

    for num in arr:
        tally.push(num)
        
        medians.append(tally.median())

    total = sum(medians)

    return total % 10000

def read_median_data(file_path):
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

def run_test_file(approach):

    numbers = read_median_data(test_file_path)

    return approach(numbers)

def run_submission(approach):

    numbers = read_median_data(submission_file_path)

    return approach(numbers)

def run_benchmark(iters=30):

    data = read_median_data(submission_file_path)

    for approach in [median_arr, median_heap]:
    
        times = []

        for _ in range(iters):

            start = time.time()
            
            approach(data)

            end = time.time()

            times += [end - start]

        avg_time = sum(times)/len(times)

        print(f'{approach.__name__} - Results: Ran {iters} iterations with average execution time: {avg_time}.')
        
# result = run_test_file(median_arr)

a1, a2 = run_submission(median_arr), run_submission(median_heap)

assert a1 == a2

result = run_test_file(median_heap)

run_benchmark()