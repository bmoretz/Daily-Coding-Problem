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

file_path = os.getcwd() + '\py\\data\\problem8.10test5.txt'
# file_path = os.getcwd() + '\py\\data\\minGraph.txt'
# file_path = os.getcwd() + '\py\\data\\minGraph_test_case1.txt'

from copy import deepcopy
from collections import defaultdict

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

def read_graph():

    g = Graph()
    
    with open(file_path, 'r') as f:
        lines = f.read().splitlines()

        for line in lines:
            
            if len(line) == 0: continue

            u, v = [int(x) for x in line.split(' ')]
            g[ u ].append( v )

    return g

def reverse_graph(graph):

    if graph == None: return None

    rev = Graph()

    for v in graph.vertices():
        for u in graph[v]:
            rev[u] += [ v ]
        
        if not rev[v]:
            rev[v] = []
    return rev

def topological_path(graph : Graph):

    if graph == None: return None

    n = len(graph.vertices())
    label = n

    topological = []
    assigned = []

    for v in list(graph.vertices()):
        
        # if the vertex is already ordered, skip it
        if v in assigned:
            continue
        
        # current path results
        path = []

        # dfs the adjacent vertices
        seen = [v]

        while seen:
            # push path
            w = seen.pop()

            if w in path: 
                continue
            
            for u in graph[w]:
                if u in assigned:
                    continue

                seen += [u]

            path += [w]
        
        assigned += path

        while path:
            topological.append((label, path.pop()))
            label -= 1
    
    top_order = sorted(topological, key= lambda t: t[0])

    missing = [x for x in graph.vertices() if x not in assigned]

    return [v[1] for v in top_order]

def compute_ssc(graph, path):
    
    num_ssc = 0
    components = {}

    assigned = []

    for v in path:
            
        if v in assigned:
            continue
        
        num_ssc += 1
        seen = [v]
        component = []

        while seen:
            u = seen.pop()

            if u in component:
                break

            for w in graph[u]:
                if w in assigned:
                    continue
                seen += [w]

            component += [u]
        
        components[num_ssc] = component
        assigned += component

    return components

def top_5_len(components):

    result = []
    n = len(components)

    for index in range(1, 6):

        if index <= n:
            result += [len(components[index])]
        else:
            result += [0]

    return ','.join([ str(l) for l in sorted(result, key=lambda x:-x)])

print('\n\n')

graph = read_graph()
print(f'Read {len(graph)} vertices from file: {file_path}.')

rev = reverse_graph(graph)
print(f'Reversed Input Graph')

assert len(graph) == len(rev)

print(f'len graph {len(graph)} len rev {len(rev)}')
print(f'len graph {len(graph.edges())} len rev {len(rev.edges())}')

path = topological_path(rev)
print(f'Found topological path: {path}')

components = compute_ssc(graph, path)
print(f'Total Strongly Connected Components Found: {len(components)}')

result = top_5_len(components)
print(f'Length of top 5 SSCs: {result}\n')