from problems.stack_queue import Stack, MaxStack

from collections import deque

'''4.3

Compute maximum of k-length subarrays

Given an array of integers and a number k, where 1 <= k <= array length, compute the maximum value of each subarray of lengh k.

For example, let's say the array is 

[10, 5, 2, 7, 8, 7] and k = 3. 

We should get [10, 7, 8, 8]

Since,

10 = max(10, 5, 2),
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)

Do this in O(n) time and O(k) space. You can modify the input array in-place and you do not need to store the results. You can simply print them out as you compute them.
'''

arr, k = [10, 5, 2, 7, 8, 7], 3

def max_subarray3(arr, k):
    q, result = deque(), []
    
    for i in range(k):
        while q and arr[i] >= arr[q[-1]]:
            q.pop()
        q.append(i)

    # Loop invariant: q is a list of indices where their
    # corresponding values are in descending order.
    for i in range(k, len(arr)):
        result.append( arr[q[0]] )

        while q and q[0] <= i - k:
            q.popleft()

        while q and arr[i] >= arr[q[-1]]:
            q.pop()
        q.append(i)

    result.append( arr[q[0]] )

    return result

print( max_subarray3(arr, k) )


