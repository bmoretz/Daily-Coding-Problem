'''Karatsuba's algorithm.

So: what's the product of the following two 64-digit numbers?

3141592653589793238462643383279502884197169399375105820974944592

2718281828459045235360287471352662497757247093699959574966967627
'''

from math import ceil

def karatsuba(x, y):

    def zero_pad(value, digits, left = True):

        for pad in range(digits):
            if left:
                value = '0' + value
            else:
                value = value + '0'

        return value

    def split(value):
        n = len(value)

        mid =  ceil(n / 2)

        return (int(value[:mid]), int(value[mid:]))

    x, y = str(x), str(y)

    nx, ny = len(x), len(y)

    n = max(nx, ny)
    j = n//2

    if n % 2 != 0:
        j += 1

    b_pad = n - j
    a_pad = b_pad * 2

    if nx == 1 and ny == 1:
        return int(x) * int(y)

    x, y = zero_pad(x, ny - nx), zero_pad(y, nx - ny)

    a, b = split(x)
    c, d = split(y)

    p = a + b
    q = c + d

    ac = karatsuba(a, c)
    bd = karatsuba(b, d)
    pq = karatsuba(p, q)

    abcd = pq - ac - bd

    A = int(zero_pad( str(ac), a_pad, left=False))
    B = int(zero_pad( str(abcd), b_pad, left=False))
    C = bd

    return A + B + C

'''
This file contains all of the 100,000 integers between 1 and 100,000 (inclusive) in some order, with no integer repeated.

Your task is to compute the number of inversions in the file given, where the ith row of the file indicates the ith entry of an array.

Because of the large size of this array, you should implement the fast divide-and-conquer algorithm covered in the video lectures.

The numeric answer for the given input file should be typed in the space below.

So if your answer is 1198233847, then just type 1198233847 in the space provided without any space / commas / any other punctuation marks.
'''

def count_inversions(arr):

    def ci(arr):

        n = len(arr)
        
        if n <= 1:
            return (0, arr)

        mid, inversions = n//2, 0

        # parse out results from left call
        left_inversions, left_set = ci(arr[:mid])
        inversions += left_inversions

        # parse results from right call
        right_inversions, right_set = ci(arr[mid:])
        inversions += right_inversions
        
        # merge results
        left_index, right_index = 0, 0

        result = []

        for index in range(n):
            
            left  = left_set[left_index] if left_index < len(left_set) else None
            right = right_set[right_index] if right_index < len(right_set) else None

            if not right or (left and left <= right):
                result += [left]
                left_index += 1
            else:
                result += [right]
                right_index += 1

                if left: inversions += len(left_set[left_index:])

        return (inversions, result)

    if arr == None:
        return (0, None)
    
    inversions, results = ci(arr)

    return inversions

'''
The file contains all of the integers between 1 and 10,000 (inclusive, with no repeats) in unsorted order. 

The integer in the i^{th} row of the file gives you the i^{th} entry of an input array.

Your task is to compute the total number of comparisons used to sort the given input file by QuickSort. As you know, the number of comparisons depends on which elements are chosen as pivots, 
so we'll ask you to explore three different pivoting rules.

You should not count comparisons one-by-one. Rather, when there is a recursive call on a subarray of length mm, you should simply add m-1m−1 to your running total of comparisons.
(This is because the pivot element is compared to each of the other m-1m−1 elements in the subarray in this recursive call.)

WARNING: The Partition subroutine can be implemented in several different ways, and different implementations can give you differing numbers of comparisons. For this problem, you should implement the 
Partition subroutine exactly as it is described in the video lectures (otherwise you might get the wrong answer).
'''

def get_sort_data():
    from os import getcwd    
    
    file_path = getcwd() + '\py\\data\\QuickSort.txt'

    def read_numbers():
        with open(file_path, 'r') as f:
            lines = f.read().splitlines()
            numbers = [int(line) for line in lines]
        return numbers

    return read_numbers()

''' quick sort with pivot statically set at 0 '''

def pivot_0(arr, left, right):
    return left

''' quick sort with pivot statically set at n '''

def pivot_n(arr, left, right): 
    return right

''' quick sort with pivot calculated to be the median value '''
def pivot_m(arr, left, right):
    
    mid = 0 if (right - left) == 1 else ((right - left)) // 2 + left
    
    candidate = sorted([arr[left], arr[mid], arr[right]])

    return arr.index(candidate[1])

def quick_sort(arr, left=0, right=None, choose_pivot=None, comp=0):
    
    def partition(arr, left, right, pivot):

        assert left <= pivot <= right

        p = arr[pivot]

        arr[left], arr[pivot] = arr[pivot], arr[left]

        j = left + 1

        for index in range(left + 1, right + 1):

            if arr[index] < p:
                arr[index], arr[j] = arr[j], arr[index]
                j += 1

        j -= 1

        arr[left], arr[j] = arr[j], arr[left]
    
        return j
    
    if right == None: right = len(arr) - 1

    n = right - left

    if n < 1: return 0

    comp = n

    pivot = choose_pivot(arr, left, right)

    j = partition(arr, left, right, pivot)

    comp += quick_sort(arr, left, j - 1, choose_pivot)
    comp += quick_sort(arr, j + 1, right, choose_pivot)

    return comp

'''
The file contains the adjacency list representation of a simple undirected graph. There are 200 vertices labeled 1 to 200. 

The first column in the file represents the vertex label, and the particular row (other entries except the first column) tells all the vertices that the vertex is adjacent to. 
So for example, the 6^{th} row looks like : "6	155	56	52	120	......". This just means that the vertex with label 6 is adjacent to (i.e., shares an edge with) the vertices with labels 155,56,52,120,......, etc.

Your task is to code up and run the randomized contraction algorithm for the min cut problem and use it on the above graph to compute the min cut. 

(HINT: Note that you'll have to figure out an implementation of edge contractions. Initially, you might want to do this naively, creating a new graph from the old every time there's an edge contraction. 
But you should also think about more efficient implementations.) 

(WARNING: As per the video lectures, please make sure to run the algorithm many times with different random seeds, and remember the smallest cut that you ever find.)

Write your numeric answer in the space provided. 

So e.g., if your answer is 5, just type 5 in the space provided.
'''

from collections import defaultdict
class Graph():

    @staticmethod
    def from_dict(g):
        graph = Graph()

        for v in g.keys():
            graph.add_vertex( v )

        for k, v in g.items():
            for e in v:
                graph.add_edge(k, e)
        
        return graph

    ''' simple adjency list graph '''
    def __init__(self):
        self.vertices = defaultdict(list)

    def add_vertex(self, vertex):
        self.vertices[ vertex ]

    def add_edge(self, a, b):
        self.vertices[a].append(b)

    def edges(self):

        edges = []

        for vertex in self.vertices.keys():
            for connection in self.vertices[vertex]:
                edges.append((vertex, connection))

        return edges

    def __getitem__(self, key):
        return self.vertices[key]

    def __setitem__(self, key, value):
        self.vertices[key] = value

    def __delitem__(self, key):
        if key in self.vertices.keys():
            del self.vertices[ key ]

    def __len__(self):
        return len(self.vertices.keys())

from random import uniform, seed, choice

def kargerMinCut(graph):

    while len(graph) > 2:

        # list of all edges
        edges = graph.edges()

        # choose one at random
        u, v = choice(edges)

        # merge u and v into a "super node"
        s_id, s = v, []

        for m in graph[ v ] + graph[ u ]:
            
            # no loops
            if m == u or m == v: 
                continue
            
            s.append( m )

        # remove the old nodes
        del graph[ v ]
        del graph[ u ]

        # update any old references of u and v
        for k in graph.vertices.keys():
            
            graph[ k ] = [ s_id if edge == v or edge == u else edge \
                 for edge in graph[ k ] ]
        
        # insert the super node
        graph[ s_id ] = s
        
    return len( graph.edges() ) / 2