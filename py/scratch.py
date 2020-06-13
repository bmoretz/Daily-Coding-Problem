'''Letters and Numbers.

Given an array filled with letters and numbers, find the longest subarray
with an equal number of letters and numbers.
'''

'''
brute force O(n^2)
'''
def letters_numbers1(arr) -> int:
    
    if not arr: return -1

    n = len(arr)

    encoded = [-1 if isinstance(e, int) else 1 for e in arr]

    min_set, sub_arr = (-1, None), None

    for i in range(n):
        for j in range(i + 1, n):
            
            value, length = sum(encoded[i:j]), j - i - 1

            if not min_set[1] or (value < min_set[0] and min_set[1] < length):
                min_set, sub_arr = (value, length), arr[i:j]

    return sub_arr

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
    
    return arr[start-1:end]

arr = ['a', 'b', 1, 'c', 'd', 'e', 3, 5, 6, 'g', 'h', 7]

val1 = letters_numbers1(arr)
print(val1)

val2 = letters_numbers2(arr)
print(val2)