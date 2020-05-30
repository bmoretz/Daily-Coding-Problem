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
    
    data_dir = getcwd() + '\\data\\illuminated\\quick-sort\\'
    file_path = data_dir + 'QuickSort.txt'

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

        for k, v in g.items():
            graph[ k ] = v
        
        return graph

    ''' simple adjency list graph '''
    def __init__(self):
        self.vertices = defaultdict(list)

    def vertices(self):
        return self.vertices.keys()

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

    '''karger's minimum cut

    this algorithm chooses an edge at random, and merges one vertex into the other, 
    to form a new "super node" that is the union of all edges in both nodes 
    (excluding self-references). We then delete both of the chosen nodes and update 
    all references to them to point to the new "super node". We repeat this process until
    there are more than 2 vertices in the graph.
    '''
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

'''
The file contains the edges of a directed graph. Vertices are labeled as positive integers from 1 to 875714. Every row indicates an edge, 
the vertex label in first column is the tail and the vertex label in second column is the head (recall the graph is directed, and the edges are 
directed from the first column vertex to the second column vertex). So for example, the 11^th row looks like : "2 47646". 
This just means that the vertex with label 2 has an outgoing edge to the vertex with label 47646

Your task is to code up the algorithm from the video lectures for computing strongly connected components (SCCs), and to run this algorithm on the given graph.

Output Format: You should output the sizes of the 5 largest SCCs in the given graph, in decreasing order of sizes, separated by commas (avoid any spaces). So if your 
algorithm computes the sizes of the five largest SCCs to be 500, 400, 300, 200 and 100, then your answer should be "500,400,300,200,100" (without the quotes). If your 
algorithm finds less than 5 SCCs, then write 0 for the remaining terms. Thus, if your algorithm computes only 3 SCCs whose sizes are 400, 300, and 100, then your 
answer should be "400,300,100,0,0" (without the quotes). 

(Note also that your answer should not have any spaces in it.)

WARNING: This is the most challenging programming assignment of the course.

Because of the size of the graph you may have to manage memory carefully. The best way to do this depends on your programming language and environment, and we strongly 
suggest that you exchange tips for doing this on the discussion forums.
'''

import heapq

def read_graph(file_path):
    ''' read graph

    this function reads a graph definition from disk and
    generates two copies: one forward (per the definition)
    and one in reversed order. This approach uses double
    the initial memory, however, we don't need to reverse
    the graph later, so this approach effectively cuts the
    cost of rev(G) to O(1).
    '''
    g, rev = Graph(), Graph()

    with open(file_path, 'r') as f:
        lines = f.read().splitlines()

        for line in lines:
            
            if len(line) == 0: continue
            
            u, v = [int(x) for x in line.strip().split(' ')]

            g[ u ].append( v )
            rev[ v ].append( u )

    return (g, rev)

def dfs_path(graph : Graph, node, seen):

    ''' dfs path

    depth-first search of the passed in graph starting
    at the specified node. We need to keep track of all
    nodes seen globally, so we pass in the seen nodes
    every iteration so we keep track of the state of the
    traversal.
    '''

    path, stack = [], [node]

    while stack:

        v = stack.pop()

        for u in graph[v]:

            if not seen[u]:
                stack += [u]
                seen[u] = True

        path += [v]
        seen[v] = True

    return path

def topological_path(graph : Graph):

    ''' topological path
    
    This function generates a topological path
    from the passed in graph using a depth-first
    search. The labels are assigned in decrementing
    order when seen, and then the resulting set is
    ordered accending upon full traversal.
    '''

    n = len(graph) + 1
    label = n

    topological = []
    seen = defaultdict(bool)

    for v in graph.vertices.copy():
        
        if not seen[v]:
            
            path = dfs_path(graph, v, seen)

            while path:
                node = path.pop()
                topological.append((label, node))
                label -= 1
    
    # final traversal order.
    top_order = sorted(topological, key= lambda t: t[0])

    # project out only the nodes.
    final_path = [v[1] for v in top_order]

    return final_path

def compute_scc(graph : Graph, path):
    
    ''' compute strongly-connected components

    This function takes a graph and a topological path
    to traverse. Each set of strongly-connected components
    get assigned to values in a dictionary with the index
    being the i-th set of components.
    '''
    
    num_ssc = 0

    components = defaultdict(list)
    seen = defaultdict(bool)
    assigned = defaultdict(bool)

    for v in path:
        
        if not seen[v]:
            # new component
            num_ssc += 1

            # traverse the path,
            # this will generate a connected set
            # of components.
            path = dfs_path(graph, v, seen)
            
            for node in path:
                # nodes can only belong to
                # one component, so we track
                # all the nodes that have been
                # previously assigned and ignore
                # any duplicate entries.              
                if not assigned[node]:
                    components[num_ssc] += [node]
                    assigned[node] = True
                        
    return components

def kosaraju(graphs):

    '''kosaraju
    
    this function takes 2 graphs as input, one forward and one
    reversed. The algorithm returns the strongly connected
    components in the forward graph.
    '''

    forward, reverse = graphs

    path = topological_path( reverse )

    components = compute_scc( forward, path )

    return components

def top_N(components, n=5):

    ''' top n
    
    this function find the top n components defined by the number
    of nodes in the specified component. We use a heap to get the
    size of the component keys in linear time (O(N)), then there is a
    constant time (n) operation to generate
    '''

    for index in range(len(components) + 1, n + 1):
        components[index] = []

    sorted_components = heapq.nlargest(n, components.items(), key=lambda x: len(x[1]))
    
    result = [ len(c[1]) for c in sorted_components ]

    return result

def run_kosaraju(file_path):

    print('\n\n')

    print('Running file:', file_path)

    g = read_graph(file_path)

    print(f'Read {len(g[0])} vertices from file: {file_path}.')
    print(f'Running kosaraju on graph...')

    components = kosaraju(g)
    print(f'Total Strongly Connected Components Found: {len(components)}')

    result = top_N(components,n=5)
    formatted_result = ','.join([ str(l) for l in sorted(result, key=lambda x:-x)])

    print(f'Length of top 5 SCCs: {formatted_result}\n')

    return result

class WeightedGraph():

    ''' adjency list weighted graph '''

    class Node():
        
        def __init__(self, id, weight):
            self.id = id
            self.weight = weight

    def __init__(self):
        self.nodes_ = defaultdict(list)

    def vertices(self):
        return self.nodes_.copy()

    def __getitem__(self, key):
        return self.nodes_[key]

    def add_node(self, u, v, c):
        self.nodes_[u].append( self.Node(v, c) )

    def __setitem__(self, key, value):
        self.nodes_[key] = value

    def __delitem__(self, key):
        del self.nodes_[key]

    def __len__(self):
        return len(self.nodes_.keys())

def read_weighted_graph(file_path):
    ''' read weighted graph

    this function reads a weighted graph definition from disk 
    and generates a graph type for ease of use.
    '''
    g = WeightedGraph()

    with open(file_path, 'r') as f:
        lines = f.read().splitlines()

        for line in lines:
            
            if len(line) == 0: continue
            
            pieces = line.strip().split('\t')

            vertex = int(pieces[0])

            for piece in pieces[1:]:

                edge, weight = [int(x) for x in piece.split(',')]
                
                g.add_node(vertex, edge, weight)

    return g

def shortest_path_slow(graph : WeightedGraph, s, def_dist=1e6):

    ''' naive dijkstra

    O(n*m)

    this is a naive implementation of dijkstra's shortest path
    algorithm. We use a stack to traverse the graph, pushing each
    adjacent edge from the source vertex on the stack, along with the
    associated cost of getting to the node (the cumulative cost from
    the source). After we visit a node, we return to the stack, sort
    it by total cost, and pick the next node with the shortest path.
    We keep track of nodes we have already visited with a dictionary
    of node id's, and only mark a node visited when we have the final
    cost of reaching that node, that way, if we encounter the node
    again while traversing the graph we won't overwrite the previous
    (shorter) distance.
    '''

    dist = defaultdict(int)
    visited, stack = defaultdict(bool), [ (s,0) ]

    for v in graph.vertices():
        
        if v != s:
            dist[v] = def_dist
            visited[v] = False
        else:
            visited[v] = True

    while stack:

        stack = sorted(stack, key=lambda p: -p[1])

        node, cost = stack.pop()

        for v in graph[ node ]:

            if not visited[ v.id ]:
                stack += [( v.id, cost + v.weight )]

        if not visited[node]:
            dist[node] = cost
            visited[node] = True

    return dist

def shortest_path_fast(graph : WeightedGraph, s, def_dist=1e6):

    ''' efficient dijkstra

    O(n + m)

    This is more performant implementation of dijkstra's shortest
    path algorithm. In this approach we maintain the same overall
    logic as the naive version, we push the start node with a
    0 cost (x->x == 0), push that nodes neighbors on the path
    heap with the cost to visit it as the heap key with maintains
    the heap invariant of the min cost as the first (top) element.
    '''
    dist = defaultdict(int)
    visited, path = defaultdict(bool), [ (0, s) ]

    for v in graph.vertices():
        
        if v != s:
            dist[v] = def_dist
            visited[v] = False
        else:
            visited[v] = True

    while path:

        cost, node = heapq.heappop(path)
        
        for v in graph[ node ]:

            if not visited[ v.id ]:
                heapq.heappush( path, (cost + v.weight, v.id ) )

        if not visited[ node] :
            dist[ node ] = cost
            visited[ node ] = True
    
    return dist

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

class HeapMin():

    '''
    heap based solution

    this approach uses two heaps (one min, one max) to
    split the data set in half, and to keep track of the
    highest value in the lower heap and the lowest number
    in the max heap, so that we can get constant access
    to the median.
    '''
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