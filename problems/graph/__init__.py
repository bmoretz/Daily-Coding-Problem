from collections import defaultdict, deque

from interface import Interface

class InvalidState(ValueError):
    '''Exception raised when the state is invalid.'''
    
    def __repr__(self):
        return 'The state of the graph is invalid for this operation.'

class IGraph(Interface):

    def vertices(self):
        ''' returns the verticies of the graph.''' 
        pass

    def edges(self):
        ''' return the edges of the graph. '''
        pass
    
    def isolated(self):
        ''' returns isolated nodes in the graph. '''

    def neighbors(self, vertex):
        """ return the neighbors of a given vertex. """
        pass
    
    def add_vertex(self, vertex):
        ''' If the vertex, "vertex", is not in
        the graph, a new "vertex" with an empty
        association is added to the dictionary.
        '''
        pass
    
    def add_edge(self, edge):
        '''
        '''
        pass

    def root(self):
        ''' return root node '''
        pass

def search(graph : IGraph, vertex, visited, parent):
    ''' depth-first search the given graph.'''

    visited[vertex] = True

    for neighbor in graph.neighbors(vertex):

        if not visited[neighbor]:
            if search(graph, neighbor, visited, vertex):
                return True

        elif parent != neighbor:
            return True

    return False

'''Determine if a cycle exists.

Given an undirected graph, determine if it contains a cycle.
'''

def has_cycle(graph : IGraph):
    ''' determine if the graph contains a cycle '''
    visited = { v : False for v in graph.vertices()}

    for vertex in graph.vertices():
        if not visited[vertex]:
            if search(graph, vertex, visited, None):
                return True

    return False


def find_path(graph : IGraph, start, end, path=[]):
    ''' finds a path (if exists) from start -> end '''

    path = path + [start]

    if start == end:
        return path

    for neighbor in graph.neighbors(start):
        if neighbor not in path:
            newpath = find_path(graph, neighbor, end, path)

            if newpath: return newpath

    return None

''' Remove edges to create even trees.

You are given a tree with an even number of nodes. Consider each connection between a parent and child node to be an "edge". You
would like to remove some of these edges, such that the disconnected subtrees that remain each have an even number of nodes.

For example, suppose your input is the following tree:

        1
      /   \
    2      3
          /  \
         4    5
       / | \
      6  7  8

In this case, if we remove the edge (3, 4), both resulting subtrees will be even.

Write a function that returns the maximum number of edges you can remove while still satisfying this requirement.
'''

def max_edges1(graph):

    def traverse(graph : IGraph, curr, result):
        descendants = 0

        for child in graph.neighbors(curr):
            num_nodes, result = traverse(graph, child, result)

            result[child] += num_nodes - 1
            descendants += num_nodes

        return descendants + 1, result

    start = graph.root()
    vertices = defaultdict(int)

    _, descendants = traverse(graph, start, vertices)

    return len([val for val in descendants.values() if val % 2 == 1])

''' Create stepword chain.

Given a start word, an end word, and a dictionary of valid words, find the shortest transformation sequence from start to end
such that only one letter is changed at each step of the sequence, and each transformed word exists in the dictionary. If
there is no possible transformation, return null. Each word in the dictionary has the same length as start and end and is lowercase.

For example, 

given start = "dog", end = "cat", and dictionary = {"dot", "dop", "dat", "cat"},

return ["dog", "dot", "dat", "cat"]

given start = "dog", end = "cat", and dictionary = {"dot", "tod", "dat", "dar"},
return null as there is no possible transformation from "dog" to "cat".
'''

def word_ladder1(start, end, words):
    from problems.graph.adj_mat_graph import AMGraph

    all_words = set(words) | set([start, end])

    def are_similar(word1, word2):
        ''' return true if words are seperated by only 1 character '''
        n1, n2 = len(word1), len(word2)

        if n1 != n2: 
            return False

        differences = 0

        for index in range(n1):
            if word1[index] != word2[index]:
                differences += 1

        return differences <= 1

    def gen_links(words):
        ''' returns dictionary of words seperated by 1 char or less '''
        links = defaultdict(list)

        for word1 in all_words:
            for word2 in all_words:

                if word1 == word2: 
                    continue

                if are_similar(word1, word2):
                    links[word1].append(word2)
        return links

    links = gen_links(all_words)

    graph = AMGraph(links)

    path = find_path(graph, start, end)

    return path