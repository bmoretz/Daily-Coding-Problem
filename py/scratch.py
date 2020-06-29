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

from random import randint

'''selection rank O(N)'''
def smallest_k3(arr, k):

    def rank_pivot(arr, left, right, rank):
        r = randint(left, right)
        pivot = arr[r]

        left_end = partition(arr, left, right, pivot)
        left_size = left_end - left + 1

        if rank == left_size - 1:
            return max(arr[left], arr[left_end])
        elif rank < left_size:
            return rank_pivot(arr, left, left_end, rank)
        else:
            return rank_pivot(arr, left_end + 1, right, rank - left_size)

    def rank(arr, r):
        return rank_pivot(arr, 0, len(arr) - 1, r)

    def swap(arr, l, r):
        arr[l], arr[r] = arr[r], arr[l]

    def partition(arr, left, right, pivot):
        
        while left <= right:
            if arr[left] > pivot:
                swap(arr, left, right)
                right -= 1
            elif arr[right] <= pivot:
                swap(arr, left, right)
                left += 1
            else:
                left += 1
                right -= 1

        return left - 1
        
    if arr == None: return None

    threshold = rank(arr, k)
    take = min(len(arr) - 1, k)

    return arr[:take]


arr = [2, 1, 5, 7, 9, 11, 3, 0, 8, 15, -1, 18]
k = 3

actual = smallest_k3(arr, k)
print(actual)
