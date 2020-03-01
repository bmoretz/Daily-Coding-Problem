import heapq

'''Running Median

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


values = [2, 1, 5, 7, 2, 0, 5]

medians = running_median2(values)

assert medians == [2.0, 1.5, 2.0, 3.5, 2.0, 2.0, 2.0]

