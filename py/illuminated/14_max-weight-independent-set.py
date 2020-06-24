'''
In this programming problem you'll code up the dynamic programming algorithm for computing a maximum-weight independent set of a path graph.

This file describes the weights of the vertices in a path graph (with the weights listed in the order in which vertices appear in the path). It has the following format:

[number_of_vertices]

[weight of first vertex]

[weight of second vertex]

...

For example, the third line of the file is "6395702," indicating that the weight of the second vertex of the graph is 6395702.

Your task in this problem is to run the dynamic programming algorithm (and the reconstruction procedure) from lecture on this data set. 

The question is: of the vertices 1, 2, 3, 4, 17, 117, 517, and 997, which ones belong to the maximum-weight independent set? 

(By "vertex 1" we mean the first vertex of the graph---there is no vertex 0.) In the box below, enter a 8-bit string, where the ith 
bit should be 1 if the ith of these 8 vertices is in the maximum-weight independent set, and 0 otherwise. For example, if you think 
that the vertices 1, 4, 17, and 517 are in the maximum-weight independent set and the other four vertices are not, then you should enter
the string 10011010 in the box below.
'''

import os
import heapq
from collections import defaultdict, namedtuple

data_dir = os.getcwd() + '\\data\\illuminated\\max-weight-independent-set\\'

submission_file_path = data_dir + 'mwis.txt'
test_file_path = data_dir + 'problem16.6test.txt'

def read_max_weight_independent(file_path):

    with open(file_path, 'r') as f:

        lines = f.read().splitlines()

        total = int(lines[0])

        weights = [None] * total
        index = 0

        for line in lines[1:]:
            weights[index] = int(line)
            index += 1

        assert len(weights) == total

    return weights

def maximum_weighted_independent_set(path):
    A = [0, path[0]]

    for i in range(2, len(path) + 1):
        a1, a2 = A[i-1], A[i-2] + path[i-1]

        A.append(max(a1, a2))

    return reconstruct(path, A)

def reconstruct(path, A):
    S = []
    i = len(A) - 1

    while i > 1:
        a1, a2 = A[i-1], A[i-2] + path[i-1]

        if a1 >= a2:
            i -= 1
        else:
            S.append(i)
            i -= 2
    
    if i == 1:
        S.append(1)

    return S

def get_test_bits(S):
    test_bits = [1, 2, 3, 4, 17, 117, 517, 997]
    
    ans = ''.join([str(int(bit in S)) for bit in test_bits])

    return ans

def mwis():

    weights = read_max_weight_independent(submission_file_path)

    max_weights = maximum_weighted_independent_set(weights)

    result = get_test_bits(max_weights)

    print(result)

mwis()