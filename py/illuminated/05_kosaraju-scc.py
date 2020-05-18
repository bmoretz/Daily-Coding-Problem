import os

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

data_dir = os.getcwd() + '\\data\\illuminated\\kosaraju\\'

submission_file_path = data_dir + 'SCC.txt'

import heapq
from collections import defaultdict

def gen_test_cases(root=os.getcwd()):
    cases = {}
    for case in range(1, 7):
        cases[case] = f'{data_dir}problem8.10test' + str(case) + '.txt'
    return cases

class Graph():

    ''' simple adjency list graph '''

    def __init__(self):
        self.vertices_ = defaultdict(list)

    def vertices(self):
        return self.vertices_.keys()

    def edges(self):
        edges = []
        for v in self.vertices_.keys():
            for u in self.vertices_[v]:
                edges += [u, v]
        return edges

    def __getitem__(self, key):
        return self.vertices_[key]

    def __setitem__(self, key, value):
        self.vertices_[key] = value

    def __delitem__(self, key):
        if key in self.vertices_.keys():
            del self.vertices_[ key ]

    def __len__(self):
        return len(self.vertices())

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

    n = len(graph.vertices()) + 1
    label = n

    topological = []
    seen = defaultdict(bool)

    for v in graph.vertices_.copy():
        
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

def run_test_cases():

    expected_output = {
        1 : [3, 3, 3, 0, 0],
        2 : [3, 3, 2, 0, 0],
        3 : [3, 3, 1, 1, 0],
        4 : [7, 1, 0, 0, 0],
        5 : [6, 3, 2, 1, 0],
        6 : [3, 1, 1, 0, 0],
    }

    for case in gen_test_cases().items():
        result = run_kosaraju(case[1])

        assert result == expected_output[case[0]]

# run_test_cases()

run_kosaraju(submission_file_path) # run submission