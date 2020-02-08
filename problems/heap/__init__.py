import heapq
from collections import defaultdict

'''Running Median

Compute the running median of a sequence of numbers. That is, given a stream of numbers, print out the median of the list so far after each new element.

For example, giveen the sequence [2, 1, 5, 7, 2, 0, 5],

Your algorithm should print out:

2
1.5
2
3.5
2
2
2
'''

'''Non-heap version'''
class RunningMedian1():

    def __init__(self):
        self._values = []

    '''O(1) median'''
    def median(self):
        if not self._values: return None
        
        n = len(self._values)
        ind = int(n / 2)

        return self._values[ind] if n % 2 == 1 else sum(self._values[ind-1:ind+1]) / 2

    '''O(n log n) insert'''
    def insert(self, value):

        self._values.append(value)
        self._values = sorted(self._values)

'''Heapify'd'''
def get_median(min_heap, max_heap):

    if len(min_heap) > len(max_heap):
        min_val = heapq.heappop(min_heap)
        heapq.heappush(min_heap, min_val)
        return min_val
    
    elif len(min_heap) < len(max_heap):
        max_val = heapq.heappop(max_heap)
        heapq.heappush(max_heap, max_val)
        return max_val
    
    else:
        min_val = heapq.heappop(min_heap)
        heapq.heappush(min_heap, min_val)
        max_val = heapq.heappop(max_heap)
        heapq.heappush(max_heap, max_val)
        return (min_val + max_val) / 2

def add(num, min_heap, max_heap):
    # If empty, jusjt add to the new max heap.
    if len(min_heap) + len(max_heap) <= 1:
        heapq.heappush(max_heap, num)
        return

    median = get_median(min_heap, max_heap)

    if num > median:
        # add it to the min heap
        heapq.heappush(min_heap, num)
    else:
        heapq.heappush(max_heap, num)

def rebalance(min_heap, max_heap):

    if len(min_heap) > len(max_heap) + 1:
        root = heapq.heappop(min_heap)
        heapq.heappush(max_heap, root)

    elif len(max_heap) > len(min_heap) + 1:
        root = heapq.heappop(max_heap)
        heapq.heappush(min_heap, root)

'''O(n log n)'''
def running_median2(stream):
    min_heap, max_heap, results = [], [], []
    
    for num in stream:
        add(num, min_heap, max_heap)
        rebalance(min_heap, max_heap)
        results.append(get_median(min_heap, max_heap))

    return results

'''Similar Websites.

You are given a list of (website, user) pairs that represent users visting websites.

Come up with a program that identifies the top k pairs of websites with the greatest similarity.

For example, suppose k = 1, and the list of tuples is:

[('google.com', 1), ('google.com', 3), ('google.com', 5),
('pets.com', 1), ('pets.com', 2), ('yahoo.com', 6), ('yahoo.com', 2), 
('yahoo.com', 3), ('yahoo.com', 4), ('yahoo.com', 5),
('wikipedia.org', 4), ('wikipedia.org', 5), ('wikipedia.org', 6),
('wikipedia.org', 7), ('bing.com', 1), ('bing.com', 3), ('bing.com', 5),
('bing.com', 6)]

To compute the similarity between two websites you should compute the number of users they have in common divided by the number of users who have visited either site in total. This is known as the Jaccard index.

For example, in this case, we would conclude that google.com and bing.com are the most similar, with a score of 3/4 or 0.75
'''

def similarity1(log, k):

    def jaccard_index(a, b, visitors):
        return len(visitors[a] & visitors[b]) / len(visitors[a] | visitors[b])

    visitors = defaultdict(set)

    for site, user in log:
        visitors[site].add(user)

    pairs = []
    sites = list(visitors.keys())

    for _ in range(k):
        heapq.heappush(pairs, (0, ('', '')))
    
    for i in range(len(sites) - 1):
        for j in range(i + 1, len(sites)):
            score = jaccard_index(sites[i], sites[j], visitors)
            heapq.heappushpop(pairs, (score, (sites[i], sites[j])))

    return [pair[1] for pair in pairs]

'''Regular Numbers.

A regular number in mathematics is defined as one which evenly divides some power of 60. Equivalently, we can say that a regular number is one whose only prime divisors are 2, 3, and 5.

These numbers have had many applications, from helping ancient Babylonians keep time to tuning instruments according to the diatonic scale.

Given an integer n, write a program that generates, in order, the first n regular numbers.
'''

'''O(n^3)'''
def regular_numbers1(n):
    
    twos = [2 ** i for i in range(n)]
    threes = [3 ** i for i in range(n)]
    fives = [5 ** i for i in range(n)]

    solution = set()

    for two in twos:
        for three in threes:
            for five in fives:
                solution.add(two * three * five)

    return sorted(solution)[:n]

'''O(n log n)'''
def regular_numbers2(n):

    solution = [1]
    last = 0; count = 0

    while count < n:
        x = heapq.heappop(solution)

        if x > last:
            yield x

            last = x; count += 1

            heapq.heappush(solution, 2 * x)
            heapq.heappush(solution, 3 * x)
            heapq.heappush(solution, 5 * x)


'''Huffman tree.

Huffman coding is a method of encoding characters based on their frequency. Each letter is assigned a variable-length binary string, where shorter lengths ccorrespond to more common letters. 

To accomplish this, a binary tree is built such that the path from the root to any leaf uniquely maps to a character. When traversing the path, descending to a left child corresponds to a 0 in the prefix,
while descending right corresponds to 1.

'''
class Node:
    def __init__(self, char, left=None, right=None):
        self.char = char
        self.left = left
        self.right = right

def huffman_coding1(value):

    def get_frequencies(value):
        freq = defaultdict(int)

        for val in value:
            freq[val] += 1

        return freq

    def build_tree(frequencies):
        nodes = []
        
        for char, frequency in frequencies.items():
            heapq.heappush(nodes, (frequency, Node(char)))

        while len(nodes) > 1:
            f1, n1 = heapq.heappop(nodes)
            f2, n2 = heapq.heappop(nodes)
            node = Node('*', left=n1, right=n2)
            heapq.heappush(nodes, (f1 + f2, node))

        root = nodes[0][1]

        return root

    def encode(root, string='', mapping={}):
        if not root:
            return

        if not root.left and not root.right:
            mapping[root.char] = string
        
        encode(root.left, string + '0', mapping)
        encode(root.right, string + '1', mapping)

        return mapping

    freq = get_frequencies(value)
    tree = build_tree(freq)
    encoded = encode(tree)

    return encoded