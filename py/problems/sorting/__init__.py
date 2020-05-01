'''
basic implementation of merge sort 
'''

def merge_sort1(values):

    def merge_sort(values):
        n = len(values)

        if n <= 1:
            return values

        mid = int(n/2)

        left = values[:mid]
        left = merge_sort(left)

        right = values[mid:]
        right = merge_sort(right)

        left_ptr, right_ptr = 0, 0

        result = []

        for index in range(n):

            if left_ptr == len(left):
                # left set empty, fill from right
                while right_ptr < len(right):
                    result += [right[right_ptr]]
                    right_ptr += 1

            elif right_ptr == len(right):
                # right set empty, fill from left
                while left_ptr < len(left):
                    result += [left[left_ptr]]
                    left_ptr += 1

            # take min element from both sides
            elif left[left_ptr] <= right[right_ptr]:
                result += [left[left_ptr]]
                left_ptr += 1
            else:
                result += [right[right_ptr]]
                right_ptr += 1

        return result
    
    if values == None: return None

    return merge_sort(values)

'''Sorted Merge.

You are given two sorted arrays, A and B, where A has a large enough
buffer at the end to hold B. Write a method to merge B into A in sorted order.
'''

A = [1, 3, 5, 9, 10, 15]
B = [2, 4, 6, 8, 12, 13]

A = A + [None] * len(B)

def sorted_merge1(A, B):

    if A == None or B == None:
        return None

    a_pos = sum( [1 for num in A if num != None] ) - 1
    b_pos = len(B) - 1

    place = len(A) - 1

    for index in range(len(A) - 1, -1, -1):

        if a_pos != -1 and (b_pos == -1 or A[a_pos] >= B[b_pos]):
            A[index], A[a_pos] = A[a_pos], A[index]
            
            a_pos -= 1
        elif b_pos != -1:
            A[index], B[b_pos] = B[b_pos], None
            
            b_pos -= 1

    return A

'''Group Anagrams.

Write a method to sort an array of strings so that all the anagrams are
next to each other.
'''

'''O(N logN ) solution. '''
def group_anagrams1(words):

    from string import ascii_lowercase

    def get_word_value(word):

        value = 0

        for letter in word.lower():
            
            if letter == ' ': continue

            value += ord(letter)

        return value

    if words == None: return None

    lookup = {}

    for word in words:
        lookup[word] = get_word_value(word)

    position = sorted((value, key) for (key, value) in lookup.items())

    return [value for (key, value) in position]

''' O(n) solution'''
def group_anagrams2(words):
    from collections import defaultdict
    from string import ascii_lowercase

    def get_word_value(word):

        value = 0

        for letter in word.lower():
            
            if letter == ' ': continue

            value += ord(letter)

        return value

    if words == None: return None

    lookup = defaultdict(list)

    for word in words:
        key = get_word_value(word)

        lookup[key].append( word )

    ordered = [ item for sublist in lookup.values() for item in sublist ]

    return ordered

'''Search in Rotated Array.

Given a sorted array of n integers that has been rotated an unknown number of times,
write code to find an element in the array. You may assume that the array was originally
sorted in increasing order.

EXAMPLE:

Input: Find 5 in [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14]
Output: 8 (the index of the array)
'''

def find_rotated1(arr, search):

    def find_pivot(arr, left, right):

        while left < right:

            mid = left + (right - left) // 2

            if arr[mid] > arr[right]:
                left = mid + 1
            else:
                right = mid

        return mid + 1

    def find_element(arr, search, left, right):

        n = right - left

        if left  > right: return -1

        mid = left + n // 2

        if arr[ mid ] == search:
            return mid
        elif search < arr[ mid ]:
            return find_element( arr, search, left, mid )
        else:
            return find_element( arr, search, mid + 1, right )

    if arr == None or search == None: return None
    
    n = len(arr) - 1

    if n <= 0: return -1

    pivot = find_pivot(arr, 0, n)

    if search == arr[ pivot ]:
        return pivot
    elif search > arr[ pivot ] and search <= arr[ n ]:
        return find_element( arr, search, pivot + 1, n )
    else:
        return find_element( arr, search, 0, pivot )