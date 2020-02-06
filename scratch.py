from collections import defaultdict

'''Longest substring.

Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.

For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".
'''

s, k = "abcba", 2

'''O(n * k) time O(k) space.'''
def longest_substring2(s, k):
    if k == 0:
        return 0
    
    # Running Window
    bounds = (0, 0)
    h = {}
    max_length = 0

    for i, char in enumerate(s):
        h[char] = i

        if len(h) <= k:
            new_lower_bound = bounds[0] # keep lower bound
        else:
            # otherwise, pop last occuring char
            key_to_pop = min(h, key = h.get)
            new_lower_bound = h.pop(key_to_pop) + 1

        bounds = (new_lower_bound, bounds[1] + 1)
        max_length = max(max_length, bounds[1] - bounds[0])

    return max_length

longest_substring2(s, k)
