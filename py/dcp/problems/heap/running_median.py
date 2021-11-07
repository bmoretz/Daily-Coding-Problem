'''
Running Median

Compute the running median of a sequence of numbers. That is, given a stream of numbers, print out the median of the list so far after each new element.

For example, given the sequence [2, 1, 5, 7, 2, 0, 5],

Your algorithm should print out:

2
1.5
2
3.5
2
2
2
'''

import heapq

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
        min_val = min_heap[-1]
        return min_val
    
    elif len(min_heap) < len(max_heap):
        max_val = heapq.heappop(max_heap)
        heapq.heappush(max_heap, max_val)
        return max_val
    
    else:
        min_val = min_heap[-1]
        max_val = heapq.heappop(max_heap)
        heapq.heappush(max_heap, max_val)
        
        return (min_val + max_val) / 2

def add(num, min_heap, max_heap):
    # If empty, just add to the new max heap.
    if len(min_heap) + len(max_heap) <= 1:
        heapq.heappush(max_heap, num)
        return

    median = get_median(min_heap, max_heap)

    if num < median:
        # add it to the min heap
        heapq.heappush(min_heap, num)
    else:
        heapq.heappush(max_heap, num)

def rebalance(min_heap, max_heap):

    if len(min_heap) > len(max_heap) + 1:
        root = min_heap.pop()
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
        results += [get_median(min_heap, max_heap)]

    return results