'''Smallest K.

Design an algorithm to find the smallest K numbers in an array.
'''

import heapq

''' O(n log n) brute force '''
def smallest_k1(arr, k):
    if not arr: return None

    n = len(arr) - 1
    s = sorted(arr)

    return s[:k] if k < n else s[:n]

'''O(n log m)'''
def smallest_k2(arr, k):

    if not arr: return None

    heapq.heapify(arr)
    n = len(arr) - 1

    results = []

    for _ in range(min(k, n)):
        results.append(arr[0])
        heapq.heappop(arr)
    
    return results