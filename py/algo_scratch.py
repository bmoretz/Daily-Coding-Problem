import os

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

file_path = os.getcwd() + '\py\\data\\kargerMinCut.txt'
# file_path = os.getcwd() + '\py\\data\\minGraph.txt'
# file_path = os.getcwd() + '\py\\data\\minGraph_test_case1.txt'

from copy import deepcopy
from collections import defaultdict
from random import uniform, seed, choice

class Graph():
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

def kargerMinCut(graph):

    while len(graph) > 2:

        # list of all edges
        edges = graph.edges()

        # choose one at random
        u, v = choice(edges)

        s_id = v
        s = []

        # merge u and v into a "super node"
        for m in graph[ v ] + graph[ u ]:

            if m == u or m == v: continue

            s.append( m )

        # no loops
        #s.remove( s_id )

        del graph[ v ]
        del graph[ u ]

        # update any old references of u and v
        for k in graph.vertices.keys():
            
            tmp = []

            for edge in graph[ k ]:
                if edge == v or edge == u:
                    tmp.append( s_id )
                else:
                    tmp.append( edge )
            
            graph[ k ] = tmp
        
        graph[ s_id ] = s
        
    return len( graph.edges() ) / 2
    
def read_graph():

    g = Graph()
    
    with open(file_path, 'r') as f:
        lines = f.read().splitlines()

        for line in lines:
            
            items = line.split('\t')

            vertex = int(items[0])

            for edge in items[1:]:

                if edge == '': continue

                g.add_edge(vertex, int(edge))

    return g

# seed(392)
seed(5520)
# seed(130)
# seed(20)
# seed(90)

graph = read_graph()

iterations = 500

mins = []

for _ in range(iterations):

    g = deepcopy(graph)

    minCut = kargerMinCut( g )

    mins.append( minCut )

print(mins)
print(f'\n\nExecuted {iterations} of graph contraction, the minimum number of edges found was: {min(mins)}')