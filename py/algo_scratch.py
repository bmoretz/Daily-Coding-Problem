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

import os

data_dir = os.getcwd() + '\\data\\illuminated\\median-maintenance\\'

submission_file_path = data_dir + 'Median.txt'
test_file_path = data_dir + 'problem11.3test.txt'

from collections import defaultdict
import heapq, time


BLACK = 'BLACK'
RED = 'RED'
NIL = 'NIL'

class OSTree():

    '''order statistic tree

    underlying is a minimal RB tree implementation,
    with only insert & supporting ops to get data into
    the tree in a balanced fashion. Nodes have been
    augmented to contain the size of their subtree
    (so root.size() == tree.count())
    '''

    class Node():
            
        def __init__(self, value, color, parent, left=None, right=None):
            self.value = value
            self.parent = parent
            self.left = left
            self.right = right
            self.color = color
            self.size = 1 # size is initially set to itself

        def total_children(self):
            return self.size

        def __repr__(self):
                return '{color} {val} Node'.format(color=self.color, val=self.value)

        def has_children(self) -> bool:
            return bool(self.get_children_count())

        def get_children_count(self) -> int:
            return 0 if self.color == NIL else sum([int(self.left.color != NIL), int(self.right.color != NIL)])
        
    NIL_LEAF = Node(value=None, color=NIL, parent=None)

    def __init__(self):
        self.root = None
        self.count = 0
    
    def __len__(self):
        return self.count

    def select(self, statistic):
        
        def sub_select(node, index):

            if not node: return None

            has_left = node.left and node.left.color != NIL
            has_right = node.right and node.right.color != NIL
            
            rank = node.size

            if has_left:
                rank = 1 + node.left.size
            elif has_right:
                rank = node.right.size

            if rank == index:
                return node.value
            elif index < rank:
                return sub_select(node.left, index)
            else:
                return sub_select(node.right, index - rank)

        return sub_select(self.root, statistic)

    def insert(self, value):
        
        if not self.root:
            self.root = self.Node(value, parent=None,
                color=BLACK, left = self.NIL_LEAF, right = self.NIL_LEAF)
            self.count += 1
            return
        
        # add 1 to all the nodes on the way to find
        # this new nodes parent.
        parent, node_dir = self._find_parent(value, 1)
        
        if node_dir is None:
            return  # value is in the tree
        
        new_node = self.Node(value=value, color=RED, parent=parent, 
            left=self.NIL_LEAF, right=self.NIL_LEAF)
        
        if node_dir == 'L':
            parent.left = new_node
        else:
            parent.right = new_node

        self._try_rebalance(new_node)
        self.count += 1

        assert self.count == self.root.size

    def _try_rebalance(self, node):
            '''
            Given a red child node, determine if there is a need to rebalance (if the parent is red)
            If there is, rebalance it
            '''

            parent = node.parent
            value = node.value

            if (parent is None  # what the fuck? (should not happen)
            or parent.parent is None  # parent is the root
            or (node.color != RED or parent.color != RED)):  # no need to rebalance
                return

            grandfather = parent.parent
            node_dir = 'L' if parent.value > value else 'R'
            parent_dir = 'L' if grandfather.value > parent.value else 'R'
            uncle = grandfather.right if parent_dir == 'L' else grandfather.left
            general_direction = node_dir + parent_dir

            if uncle == self.NIL_LEAF or uncle.color == BLACK:
                # rotate
                if general_direction == 'LL':

                    self._right_rotation(node, 
                        parent, 
                        grandfather, 
                        to_recolor=True)

                elif general_direction == 'RR':

                    self._left_rotation(node, 
                        parent, 
                        grandfather, 
                        to_recolor=True)

                elif general_direction == 'LR':

                    self._right_rotation(node=None, 
                        parent=node, 
                        grandfather=parent)
                    # due to the prev rotation, our node is now the parent
                    self._left_rotation(node=parent, 
                        parent=node, 
                        grandfather=grandfather, 
                        to_recolor=True)

                elif general_direction == 'RL':

                    self._left_rotation(node=None, 
                        parent=node, 
                        grandfather=parent)
                    # due to the prev rotation, our node is now the parent
                    self._right_rotation(node=parent, 
                        parent=node,
                        grandfather=grandfather,
                        to_recolor=True)
                else:
                    raise Exception("{} is not a valid direction!".format(general_direction))
            else:  # uncle is RED
                self._recolor(grandfather)

    def __update_parent(self, node, parent_old_child, new_parent):
        '''
        Our node 'switches' places with the old child
        Assigns a new parent to the node.
        If the new_parent is None, this means that our node becomes the root of the tree
        '''
        node.parent = new_parent

        if new_parent:
            # Determine the old child's position in order to put node there
            if new_parent.value > parent_old_child.value:
                new_parent.left = node
            else:
                new_parent.right = node
        else:
            self.root = node

    def _right_rotation(self, node, parent, grandfather, to_recolor=False):
        
        grand_grandfather = grandfather.parent
        
        self.__update_parent(node=parent, 
            parent_old_child=grandfather, 
            new_parent=grand_grandfather)

        old_right = parent.right
        parent.right = grandfather
        grandfather.parent = parent

        # save the old right values
        grandfather.left = old_right
        old_right.parent = grandfather

        # update node sizes
        if grandfather.right and grandfather.right.color != NIL:
           grandfather.size += parent.size
           parent.size -= grandfather.size
        else:
            grandfather.size -= parent.size
            parent.size += grandfather.size

        if to_recolor:
            parent.color = BLACK
            node.color = RED
            grandfather.color = RED

    def _left_rotation(self, node, parent, grandfather, to_recolor=False):

        grand_grandfather = grandfather.parent

        self.__update_parent(node=parent, 
            parent_old_child=grandfather, 
            new_parent=grand_grandfather)

        old_left = parent.left
        parent.left = grandfather
        grandfather.parent = parent

        # save the old left values
        grandfather.right = old_left 
        old_left.parent = grandfather

        # update node sizes
        if grandfather.left and grandfather.left.color != NIL:
            grandfather.size -= parent.size
            parent.size += grandfather.size
        else:
            grandfather.size -= parent.size
            parent.size += grandfather.size
            
        if to_recolor:
            parent.color = BLACK
            node.color = RED
            grandfather.color = RED

    def _recolor(self, grandfather):

        grandfather.right.color = BLACK
        grandfather.left.color = BLACK

        if grandfather != self.root:
            grandfather.color = RED
        
        self._try_rebalance(grandfather)

    def _find_parent(self, value, size_change=0):
        ''' Finds a place for the value in our binary tree. '''
        
        def inner_find(parent, size_change):

            '''
            Return the appropriate parent node for our new node as well as the side it should be on

            Additionally, as we walk the tree we update the size attribute of all the nodes
            we traverse to find the parent of a new node for insertion/deletion.
            '''

            parent.size += size_change

            if value == parent.value:
                return None, None

            elif parent.value < value:

                # no more to go

                if parent.right.color == NIL:
                    return parent, 'R'
                
                return inner_find(parent.right, size_change)

            elif value < parent.value:
                
                # no more to go
                if parent.left.color == NIL:
                    return parent, 'L'

                return inner_find(parent.left, size_change)

        return inner_find(self.root, size_change)

    def find_node(self, value):
        
        def inner_find(root):
            if root is None or root == self.NIL_LEAF:
                return None
            if value > root.value:
                return inner_find(root.right)
            elif value < root.value:
                return inner_find(root.left)
            else:
                return root

        found_node = inner_find(self.root)

        return found_node

    def _set_child_counts(self):

        node = self.root


class HeapMin():

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

def median_tree(arr):

    ''' median tree
    
    approach that uses an AVL tree to ensure a balanced
    tree during the building of the tree through the insertions
    and then a select procedure to return the median (n/2th order statistic)
    '''

    tally, medians = OSTree(), []

    for num in arr:
        
        tally.insert(num)

        n = len(tally)

        position = n//2 if n % 2 == 0 else (n+1)//2

        medians.append(tally.select(position))

    print(medians)
    total = sum(medians)

    return total % 10000
    
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
    
    print(medians)

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

def run_test_file(approach):

    numbers = read_median_data(test_file_path)

    return approach(numbers)

def run_submission(approach):

    numbers = read_median_data(submission_file_path)

    return approach(numbers)

def run_benchmark(iters=30):

    data = read_median_data(submission_file_path)

    for approach in [median_arr, median_heap]:
    
        times = []

        for _ in range(iters):

            start = time.time()
            
            approach(data)

            end = time.time()

            times += [end - start]

        avg_time = sum(times)/len(times)

        print(f'{approach.__name__} - Results: Ran {iters} iterations with average execution time: {avg_time}.')
        


# a1, a2 = run_submission(median_arr), run_submission(median_heap)

# assert a1 == a2

# result = run_test_file(median_heap)

# run_benchmark()

#


result = run_test_file(median_arr)
print(result)
result = run_test_file(median_tree)

print(result)

tree = OSTree()

for i, e in enumerate([2, 1, 3, 4, 5, 0, -1, 1]):

    tree.insert(e)

print(tree)