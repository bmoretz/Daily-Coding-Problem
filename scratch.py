from problems.stack_queue import Stack, MaxStack

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

arr, k = [1, 2, 3, 4, 5, 6, 7, 8, 9], 3

def max_subarray2(arr, k):
    results = []
    for i in range(len(arr) - k + 1):
        results.append(max(arr[i:i + k]))
    return results

print(max_subarray2(arr, k))