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

#file_path = os.getcwd() + '\py\\data\\kargerMinCut.txt'
#file_path = os.getcwd() + '\py\\data\\minGraph.txt'

file_path = os.getcwd() + '\py\\data\\minGraph_test_case1.txt'

from copy import deepcopy
from collections import defaultdict
from random import uniform, seed, choice

class Graph():
    ''' simple adjency list graph '''
    def __init__(self):
        self.vertices = defaultdict(list)

    def add_vertex(self, vertex):
        self.vertices[vertex]

    def add_edge(self, a, b):
        self.vertices[a].append(b)

    def edges(self):

        edges = []

        for vertex in self.vertices.keys():
            for connection in self.vertices[vertex]:
                edges.append((vertex, connection))

        return edges

    def contract(self):

        while True:
            
            edges = self.edges()

            if len(edges) <= 2:
                break

            u, v = choice(edges)

            for m in self.vertices[u]:
                if m != v and m not in self.vertices[v]: 
                    self.vertices[v].append(m)

            for conn in self.vertices[u]:
                if u in self.vertices[conn]:
                    self.vertices[conn].remove(u)

            del self.vertices[u]

def read_graph():

    g = Graph()
    
    with open(file_path, 'r') as f:
        lines = f.read().splitlines()

        for line in lines:

            items = line.split(' ')

            vertex = int(items[0])

            for edge in items[1:]:

                if edge == '': continue

                g.add_edge(vertex, int(edge))

    return g

# seed 9 = 1 
seed(90)

graph = read_graph()

iterations = 1000

mins = []

for _ in range(iterations):

    cpy = deepcopy(graph)

    cpy.contract()

    rem = cpy.edges()

    mins.append( rem )

uniques = set(mins)

print(uniques)

print(f'\n\nExecuted {iterations} of graph contraction, the minimum number of edges found was: {min(mins)}')