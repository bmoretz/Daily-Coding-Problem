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

'''Sorted Search, No Size.

You are given an array-like data structure Listy, which lacks a size method. It does,
however, have an elementAt(i) method that returns the element at index i in O(1) time. If
i is beyond the bounds of the data structure, it returns -1. (For this reason, the 
data structure only supports positive integers). Given a Listy which contains sorted,
positive integers, find the index at which an element x occurs multiple times, you
may return any index.
'''

class Listy():

    def __init__(self, values):
        assert [x >= 0 for x in values]
        self.data_ = list(sorted(values))

    def element_at(self, index):

        if index < 0 or index >= len(self.data_): 
            return -1
        else:
            return self.data_[index]

def sorted_find1(lst, element):

    def get_length(lst):

        power = 0

        while lst.element_at( 2**power ) != -1:
            power += 1

        if power == 0: return 0

        lower = 2**(power-1)

        for index in range(power, -1, -1):
            j = 2**index

            if lst.element_at(lower + j) != -1:
                lower += j 

        return lower + 1
        
    def find(lst, element, start, stop):
        
        if start > stop: return -1

        mid = start + (stop - start)//2

        cur = lst.element_at( mid )

        if cur == element:
            return mid
        elif element < element:
            return find(lst, element, start, mid - 1)
        else:
            return find(lst, element, mid + 1, stop) 

    if lst == None: return None

    n = get_length(lst) - 1

    return find(lst, element, 0, n - 1)

'''Sparse Search.

Given a sorted array of strings that is interspersed with empty strings, write
a method to find the location of the given string.

EXAMPLE

Input: ball, {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""}
Output: 4
'''

def sparse_search(arr, element):
    
    def compare(left, right):
        
        return 0 if left == right else -1 if right < left else 1

    def find(arr, element, left, right):
        
        if left > right: return -1

        mid = left + (right - left)//2
        
        l, r = mid, mid

        while arr[ l ] == '' and arr[ r ] == '':
            l -= 1
            r += 1

        mid = l if arr[ l ] != '' else r
        
        cmp_val = compare( arr[ mid ], element )

        if cmp_val == 0:
            return mid
        elif cmp_val < 0:
            return find( arr, element, left, mid - 1 )
        else:
            return find( arr, element, mid + 1, right )

    if arr == None or element == None: return None

    if element == '': return -1 # searching for spaces not allowed
    
    n = len(arr) - 1

    return find(arr, element, 0, n)

'''Sorted Matrix.

Given an M x N matrix in which each row and each column is sorted in ascending order,
write a method to find an element.
'''

def mat_search(mat, element):

    def find(arr, element, left, right):
        
        if left > right: return - 1

        mid = left + (right - left)//2

        if element == arr[mid]:
            return mid
        elif element < arr[mid]:
            return find( arr, element, left, mid - 1 )
        else:
            return find( arr, element, mid + 1, right )
    
    def find_row(mat, element, bottom, top):

        if bottom > top: return -1

        mid = top + (bottom - top)//2

        n = len(mat[mid]) - 1

        minimum, maximum = mat[mid][0], mat[mid][n]

        if element >= minimum and element <= maximum:
            return mid
        elif element <= minimum:
            return find_row(mat, element, bottom, mid - 1)
        else:
            return find_row(mat, element, mid  + 1, top)

    if mat == None or element == None: return None

    position = find_row(mat, element, 0, len(mat) - 1)

    if position == -1: return -1

    row = mat[position]

    return (position, find( row, element, 0, len(row) -1 ))

def build_mat(n):
    return [[( (y * 10) + x ) for x in range(1, n + 1)] for y in range(n)]

'''Rank from Stream.

Imagine you are reading in a stream of integers. Periodically, you wish to be
able to look up the rank of a number x (the number of values less than or equal
to x). Implement the data structures and algorithms to support these operations.
That is, implement the method track (int x), which is called when each number is
generated, and the method getRankOfNumber (int x), which returns the number of
values less than or equal to x (not including x itself).

EXAMPLE:

Stream (in order of appearance): 5, 1, 4, 4, 5, 9, 7, 13, 3

getRankOfNumber(1) = 0
getRankOfNumber(3) = 1
getRankOfNumber(4) = 3
'''

class RankStream():

    def __init__(self):
        self.root = None

    @staticmethod
    def track_values(values):
        
        rs = RankStream()

        if values:
            for value in values:
                rs.track( value )

        return rs
        
    class Node():
        def __init__(self, data, left=None, right=None):
            self.data = data
            self.left = left
            self.right = right

    def track(self, data):

        if self.root == None:
            self.root = self.Node(data)
        else:
            
            node, prev = self.root, None

            while node != None:
                
                prev = node

                if data <= node.data and node.right != None:
                    node = node.left
                else:
                    node = node.right
            
            node = prev

            if node.left == None:
                node.left = self.Node(data)

                if node.data < data:
                    node.data, node.left.data = node.left.data, node.data

            else:
                node.right = self.Node(data)

                if node.data > data:
                    node.data, node.right.data = node.right.data, node.data
            
    def get_rank(self, num):

        def count_children(parent, value):

            if parent == None:
                return 0

            result = 1 if parent.data <= value else 0

            if value < parent.data:
                return result + count_children(parent.left, value)
            else:
                return result + count_children(parent.left, value) \
                    + count_children(parent.right, value)

        if num == None: return None
        if self.root == None: return None

        return count_children(self.root, num)

'''Peaks and Valleys.

In an array of integers, a "peak" is an element which is greater than or equal to 
the adjacent integers and a "valley" is an element which is less than or equal to
the adjacent integers. For example, in the array [5, 8, 6, 2, 3, 4, 6], {5, 8} and
{6, 2} are valleys. Given an array of integers, sort the array into an alternating
sequence of peaks and valleys.

EXAMPLE:
Input: {5, 3, 1, 2, 3}
Output: {5, 1, 3, 2, 3}
'''

def alt_sort1(arr):
    
    if arr == None: return None

    n = len(arr)

    if n == 0: return []

    s = list(reversed(sorted(arr)))

    mid = n//2

    high, low = s[:mid], list(reversed(s[mid:]))
    h, l = 0, 0

    result = []

    while h < len(high) or l < len(low):
        
        if h < len(high):
            result.append(high[h])
            h += 1
        
        if l < len(low):
            result.append(low[l])
            l += 1

    return result

def alt_sort2(arr):

    if arr == None: return None

    n = len(arr)

    if n == 0: return []

    s = sorted(arr)

    mid = n//2

    high, low = s[mid:], s[:mid]
    h, l = len(high) - 1, 0

    result = []

    while h >= 0 or l < len(low):
        
        if h >= 0:
            result.append(high[h])
            h -= 1
        
        if l < len(low):
            result.append(low[l])
            l += 1

    return result