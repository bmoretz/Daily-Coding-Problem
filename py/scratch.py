'''Letters and Numbers.

Given an array filled with letters and numbers, find the longest subarray
with an equal number of letters and numbers.
'''

'''
O(N) solution

steps:

1.) encode the values isn the array as 1 for letters, -1 for numbers
2.) calculate the consecutive sums of the values
3.) find the largest adjacent sum (the two largest consecutive opposite sums)
    this has to be the middle of the sum
4.) tack on the trailing ends while we can append characters while maintaining the
    sum invariant that all sums must equal 0.
5.) return the values in the array that correspond to those index locations.
'''
def letters_numbers2(arr) -> int:

    def encode_values(arr):
        return [-1 if isinstance(e, int) else 1 for e in arr]

    def get_consecutive_sums(encoded):
        consecutive = []
        index, prev = 1, encoded[0]
        counter, n = 1, len(arr)

        while index < n:
            cur = encoded[index]

            if cur == prev:
                counter += cur
            else:
                consecutive += [counter]
                counter = cur

            prev = cur
            index += 1

        consecutive += [counter]

        return consecutive

    def get_max_adjacent(consecutive):
        adj_indices, min_adj = None, consecutive[0]

        for index in range(1, len(consecutive)):
            a, b = consecutive[index-1], consecutive[index]
            cur_adj = abs(a + b)

            if cur_adj < min_adj:
                adj_indices = (index - 1, index)
                min_adj = cur_adj
        
        return adj_indices

    if not arr: return -1

    encoded = encode_values(arr)
    consecutive = get_consecutive_sums(encoded)
    adj_indices = get_max_adjacent(consecutive)

    start = sum([abs(i) for i in consecutive[:adj_indices[0]]])
    end = start + abs(adj_indices[0]) + abs(adj_indices[1])
    
    leading, trailing = start - 1, end + 1
    n = len(arr)

    while (leading > 0 and trailing < n):
        if encoded[leading] + encoded[trailing] == 0:
            start, end = start - 1, end + 1
        
        leading, trailing = leading - 1, trailing + 1
    
    while trailing < n and encoded[trailing-1] + encoded[trailing] == 0:
        trailing += abs(consecutive[trailing])

    return arr[leading:trailing-1]

arr = ['a', 'b', 1, 'c', 'd', 'e', 3, 5, 6, 'g', 4, 7, 'a', 'b', 1, 'c', 'd', 'e', 3, 5, 6, 'g', 'h', 7]

def letters_numbers1(arr):

    def encode(arr):
        return [-1 if isinstance(e, int) else 1 for e in arr]

    def is_balanced(encoded):
        return sum(encoded) == 0

    if not arr: return -1
    
    n = len(arr)
    encoded = encode(arr)

    for end in range(n, 0, -1):
        for begin in range(n - end):
            if is_balanced(encoded[begin:end+1]):
                return arr[begin-1:end]

print(letters_numbers1(arr))
print(letters_numbers2(arr))
