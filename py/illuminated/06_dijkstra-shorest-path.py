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

from utility import get_test_file

submission_file_path = get_test_file('dijkstra', 'dijkstraData.txt')
test_file_path = get_test_file('dijkstra', 'problem9.8test.txt')

from collections import defaultdict
import heapq, time

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

def run_test_cases():

    g = read_weighted_graph(test_file_path)

    p1 = shortest_path_fast(g, 1)
    print(p1)

    p2 = shortest_path_slow(g, 1)
    print(p2)
    
def dsp_submission():

    g = read_weighted_graph(submission_file_path)

    dist = shortest_path_fast(g, 1)
    req_dist = [ 7, 37, 59, 82, 99, 115, 133, 165, 188, 197 ]
    
    result = []

    for d in req_dist:
        result += [dist[d]]

    print(','.join([ str(r) for r in result ]))

run_test_cases()

#g = read_weighted_graph(test_file_path)
# dsp_submission()

def benchmark_dsp(g, dsp):

    results = []

    for _ in range(0, 10):

        start = time.time()
        dsp(g, 1)
        
        end = time.time()

        results += [end - start]

    print(f'Avg Run-time: {sum(results) / len(results)}')

g = read_weighted_graph(submission_file_path)

benchmark_dsp(g, shortest_path_slow)
benchmark_dsp(g, shortest_path_fast)

# slow: Avg Run-time: 3.1510524988174438
# fast: Avg Run-time: 0.011552953720092773