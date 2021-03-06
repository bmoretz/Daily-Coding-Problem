from collections import defaultdict, deque

from abc import ABC

class InvalidState(ValueError):
    '''Exception raised when the state is invalid.'''
    
    def __repr__(self):
        return 'The state of the graph is invalid for this operation.'

class IGraph(ABC):

    def vertices(self):
        ''' returns the vertices of the graph.''' 
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

    def traverse(graph : IGraph, cur, result):
        descendants = 0

        for child in graph.neighbors(cur):
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

    from py.problems.graph.adj_mat_graph import AMGraph

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

''' Beat snakes and ladders.

Snakes and Ladders is a game played on a 10x10 board, the goal of which is getting from square 1 to square 100. On each turn
players will roll a six-sided die and move forward a number of spaces equal to the result. If they land on a square that represents
a snake or ladders, they will be transported ahead or behind, respectively, to a new square.

Find the smallest number of turns it takes to play snakes and ladders.

For convenience, here are the squares representing snakes and ladders, and their outcomes:
'''

def minimum_turns1(snakes, ladders, n_squares):

    def build_board(snakes, ladders, n_squares):
        board = {square : square for square in range(1, n_squares + 1)}

        for start, end in snakes.items():
            board[start] = end

        for start, end in ladders.items():
            board[start] = end

        return board

    board = build_board(snakes, ladders, n_squares)
    
    start, end = 0, 100
    turns = 0

    path = deque([(start, turns)])
    visited = set()

    while path:
        square, turns = path.popleft()

        for move in range(square + 1, square + 7):
            if move >= end:
                return turns + 1

            if move not in visited:
                visited.add(move)
                path.append((board[move], turns + 1))

'''Topological sort.

We are given a hasmap associating each courseId key with a list of courseIds values, which tells us that the prerequisites of courseId
are course Ids. Return a sorted ordering of courses such that we can complete the curriculum.

Return null if there is no such ordering.

For example, given the following prerequisites:

{
    'CSC300' : ['CSC100', 'CSC200'],
    'CSC200' : ['CSC100'],
    'CSC100' : []
}

You should return ['CSC100', 'CSC200', 'CSC300'].
'''

def find_order1(courses_to_prereqs : dict):

    # Copy list values into a set for faster removal
    course_to_prereqs = {c : set(p) for c, p in courses_to_prereqs.items()}

    # Start off our list with all courses without prerequisites.
    todo = deque([c for c, p in course_to_prereqs.items() if not p])

    # Create a new data structure to map prereqs to successor courses.
    prereq_to_courses = defaultdict(list)

    for course, prereqs in course_to_prereqs.items():
        for prereq in prereqs:
            prereq_to_courses[prereq].append(course)

    result = []

    while todo:
        prereq = todo.popleft()
        result.append(prereq)

        # Remove this prereq from all successor courses.
        # If any course now does not have any prereqs, add it to todo.

        for c in prereq_to_courses[prereq]:
            course_to_prereqs[c].remove(prereq)

            if not course_to_prereqs[c]:
                todo.append(c)

    # Circular dependency
    if len(result) < len(course_to_prereqs):
        return None

    return result

'''Route Between Nodes.

Given a directed graph, design an algorithm to find out whether there is a route between two nodes.
'''

def has_route1(graph, node1, node2):

    def has_route(graph, node1, node2, visited = []):
    
        if node1 == node2:
            return True

        for neighbor in graph[node1]:

            if neighbor not in visited:
                visited.append(neighbor)

                if has_route(graph, neighbor, node2, visited): return True
        
        return False

    if graph == None: return None
    if node1 == None or node2 == None: return None
    if node1 not in graph or node2 not in graph: return False

    return has_route(graph, node1, node2)


'''Build Order.

You are given a list of projects and a list of dependencies (which is
a list of pairs of projects, where the second project is dependent on
the first project). All of a project's dependencies must be built before
the project is. Find a build order that will allow the projects to be built. If
there is no valid build order, return an error.

EXAMPLE

Input:
    projects: a, b, c, d, e, f
    dependencies: (a, d), (f, b), (b, d), (f, a), (d, c)
Output:
    f, e, a, b, d, c
'''


class Builder1():

    class CircularReferenceError(ReferenceError):

        def __init__(self):
            pass

    def __init__(self, projects, dependencies):
        self.projects = {}

        if projects is None: return

        for proj in projects:
            self.__add_project(proj)

        if dependencies is None: return

        for dep in dependencies:
            self.__add_dependency(dep[0], dep[1])

    def __add_project(self, project):
        self.projects[project] = []

    def __add_dependency(self, project, dep):
        self.projects[project].append(dep)

    def __get_dependencies(self, project, prior=[], pending=[]):
        dependencies, subprojects = [project], self.projects[project]
        
        if subprojects != []:
            for sub in subprojects:
                if sub in pending:
                    raise self.CircularReferenceError()

                if sub not in prior:
                    dependencies += self.__get_dependencies(sub, prior, pending)

        return dependencies

    def build_project(self, project):
        
        dependencies = [project]
        built = []

        for proj in self.projects[project]:
            dep = self.__get_dependencies(proj, built, dependencies)

            dependencies += dep

            built.append(dependencies)
            # reset the build list after completion
            dependencies = [project]        
        return dependencies

    def dep_list(self):
        dep_list = {}

        for proj in projects:
            dep_list[proj] = len(self.build_project(proj)) - 1

        return dep_list

    def build_all(self):
        
        to_build = list(self.projects.keys())

        if to_build == []: return None

        built = []

        while len(to_build) > 0:

            current = to_build.pop()

            dependencies = self.build_project(current)

            for dep in dependencies:

                if dep in to_build: 
                    to_build.remove(dep)

                if dep not in built:
                    built = built + [dep]

        return built


class BabyNames():

    from collections import defaultdict
    
    class Node():

        def __init__(self, name, count):
            self.name = name
            self.count = count
            self.edges = []

        def add_edge(self, other):
            self.edges += [other]

        def __hash__(self):
            return hash(self.name) + self.count

    def __init__(self):
        self.names = defaultdict(self.Node)
        
    def add_name(self, name, count=0):
        self.names[name] = self.Node(name, count)

    def add_synonym(self, primary, secondary):

        if primary not in self.names:
            self.add_name(primary)
        
        if secondary not in self.names:
            self.add_name(secondary)

        a, b = self.names[primary], self.names[secondary]

        a.add_edge( b )
        b.add_edge( a )

    def get_unique(self):

        totals = defaultdict(int)
        seen = set()

        for name in self.names:

            to_visit = [self.names[name]]

            while to_visit:
                
                node = to_visit.pop()

                if node in seen:
                    continue

                for neighbor in node.edges:
                    to_visit += [neighbor]

                totals[name] += node.count
                seen.add(node)

        return totals