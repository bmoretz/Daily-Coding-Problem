import unittest

from py.problems.sorting import merge_sort1
class Test_MergeSort1(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_case1(self):

        values = [5, 4, 1, 8, 7, 2, 6, 3, 9]

        actual = merge_sort1(values)

        expected = sorted(values)
        
        assert actual == expected

    def test_case2(self):

        values = [23, 44, 19, 2, 17, 14, 16, 31]

        actual = merge_sort1(values)

        expected = sorted(values)
        
        assert actual == expected

    def test_case3(self):

        values = [1, 2, 3]

        actual = merge_sort1(values)

        expected = sorted(values)
        
        assert actual == expected

    def test_case4(self):

        values = [-1, -2, -3, -4, -3]

        actual = merge_sort1(values)

        expected = sorted(values)
        
        assert actual == expected

    def test_case5(self):

        values = [23, 44, 19, 2, 17, 14, 16, 31]

        actual = merge_sort1(values)

        expected = sorted(values)
        
        assert actual == expected

from py.problems.sorting import sorted_merge1
class Test_SortedMerge1(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_none(self):

        A = [None]
        B = [None]

        A = A + [None] * len(B)

        actual = sorted_merge1(A, B)

        expected = [None, None]
        
        assert actual == expected

    def test_empty(self):

        A = None
        B = None

        actual = sorted_merge1(A, B)

        expected = None
        
        assert actual == expected

    def test_case1(self):

        A = [1, 3, 5, 9, 10, 15]
        B = [2, 4, 6, 8, 12, 13]

        A = A + [None] * len(B)

        actual = sorted_merge1(A, B)

        expected = [1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 13, 15]
        
        assert actual == expected

    def test_case2(self):

        A = [3, 8, 9]
        B = [0, 1, 2]

        A = A + [None] * len(B)

        actual = sorted_merge1(A, B)

        expected = [0, 1, 2, 3, 8, 9]
        
        assert actual == expected

    def test_case3(self):

        A = [0, 1, 2]
        B = [3, 8, 9]

        A = A + [None] * len(B)

        actual = sorted_merge1(A, B)

        expected = [0, 1, 2, 3, 8, 9]
        
        assert actual == expected

from py.problems.sorting import group_anagrams1
class Test_GroupAnagrams1(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_case1(self):

        words = None

        actual = group_anagrams1(words)

        expected = None
        
        assert actual == expected

    def test_case1(self):

        words = ['quiet', 'real fun', 'dog', 'listen', 'glisten', 'cat', 'silent', 'funeral']

        actual = group_anagrams1(words)

        expected = ['cat', 'dog', 'quiet', 'listen', 'silent', 'funeral', 'real fun', 'glisten']
        
        assert actual == expected

    def test_case2(self):

        words = ['A gentleman', 'quiet', 'real fun', 'dog', 'Elegant man', 'glisten', 'cat', 'silent', 'funeral']

        actual = group_anagrams1(words)

        expected = ['cat', 'dog', 'quiet', 'silent', 'funeral', 'real fun', 'glisten', 'A gentleman', 'Elegant man']
        
        assert actual == expected

    def test_case3(self):

        words = ['A gentleman', 'quiet', 'real fun', 'Dormitory', 'dog', 'Elegant man', 'glisten', 'cat', 'silent', 'funeral', 'Dirty room']

        actual = group_anagrams1(words)

        expected = ['cat', 'dog', 'quiet', 'silent', 'funeral', 'real fun', 'glisten', 'Dirty room', 'Dormitory', 'A gentleman', 'Elegant man']
        
        assert actual == expected

    def test_case4(self):

        words = ['A gentleman', 'Conversation', 'quiet', 'real fun', 'Dormitory', 'dog', 'Elegant man', 'glisten', 'cat', 'silent', 'funeral', 'Dirty room', 'Voices rant on']

        actual = group_anagrams1(words)

        expected = ['cat', 'dog', 'quiet', 'silent', 'funeral', 'real fun', 'glisten', 'Dirty room', 'Dormitory', 'A gentleman', 'Elegant man', 'Conversation', 'Voices rant on']
        
        assert actual == expected

    def test_case5(self):

        words = ['A gentleman', 'The eyes', 'Conversation', 'quiet', 'real fun', 'Dormitory', 'dog', 'Elegant man', 'glisten', 'They see', 'cat', 'silent', 'funeral', 'Dirty room', 'Voices rant on']

        actual = group_anagrams1(words)

        expected = ['cat', 'dog', 'quiet', 'silent', 'funeral', 'real fun', 'glisten', 'The eyes', 'They see', 'Dirty room', 'Dormitory', 'A gentleman', 'Elegant man', 'Conversation', 'Voices rant on']
        
        assert actual == expected

from py.problems.sorting import group_anagrams2
class Test_GroupAnagrams2(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_case1(self):

        words = None

        actual = group_anagrams2(words)

        expected = None
        
        assert actual == expected

    def test_case1(self):

        words = ['quiet', 'real fun', 'dog', 'listen', 'glisten', 'cat', 'silent', 'funeral']

        actual = group_anagrams2(words)

        expected = ['quiet', 'real fun', 'funeral', 'dog', 'listen', 'silent', 'glisten', 'cat']
        
        assert actual == expected

    def test_case2(self):

        words = ['A gentleman', 'quiet', 'real fun', 'dog', 'Elegant man', 'glisten', 'cat', 'silent', 'funeral']

        actual = group_anagrams2(words)

        expected = ['A gentleman', 'Elegant man', 'quiet', 'real fun', 'funeral', 'dog', 'glisten', 'cat', 'silent']
        
        assert actual == expected

    def test_case3(self):

        words = ['A gentleman', 'quiet', 'real fun', 'Dormitory', 'dog', 'Elegant man', 'glisten', 'cat', 'silent', 'funeral', 'Dirty room']

        actual = group_anagrams2(words)

        expected = ['A gentleman', 'Elegant man', 'quiet', 'real fun', 'funeral', 'Dormitory', 'Dirty room', 'dog', 'glisten', 'cat', 'silent']
        
        assert actual == expected

    def test_case4(self):

        words = ['A gentleman', 'Conversation', 'quiet', 'real fun', 'Dormitory', 'dog', 'Elegant man', 'glisten', 'cat', 'silent', 'funeral', 'Dirty room', 'Voices rant on']

        actual = group_anagrams2(words)

        expected = ['A gentleman', 'Elegant man', 'Conversation', 'Voices rant on', 'quiet', 'real fun', 'funeral', 'Dormitory', 'Dirty room', 'dog', 'glisten', 'cat', 'silent']
        
        assert actual == expected

    def test_case5(self):

        words = ['A gentleman', 'The eyes', 'Conversation', 'quiet', 'real fun', 'Dormitory', 'dog', 'Elegant man', 'glisten', 'They see', 'cat', 'silent', 'funeral', 'Dirty room', 'Voices rant on']

        actual = group_anagrams2(words)

        expected = ['A gentleman', 'Elegant man', 'The eyes', 'They see', 'Conversation', 'Voices rant on', 'quiet', 'real fun', 'funeral', 'Dormitory', 'Dirty room', 'dog', 'glisten', 'cat', 'silent']
        
        assert actual == expected

from py.problems.sorting import find_rotated1
class Test_FindRotated1(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_none(self):

        arr = None

        actual = find_rotated1(arr, 1)
        expected = None

        assert actual == expected

    def test_empty(self):

        arr = []

        actual = find_rotated1(arr, 5)
        expected = -1
        
        assert actual == expected

    def test_case1(self):

        arr = [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14]

        actual = find_rotated1(arr, 5)
        expected = 8
        
        assert actual == expected

    def test_case2(self):

        arr = [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14]

        actual = find_rotated1(arr, 19)
        expected = 2
        
        assert actual == expected

    def test_case3(self):

        arr = [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14]

        actual = find_rotated1(arr, 15)
        expected = 0
        
        assert actual == expected

    def test_case4(self):

        arr = [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14]

        actual = find_rotated1(arr, 14)
        expected = 11
        
        assert actual == expected

    def test_case5(self):

        arr = [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14]

        actual = find_rotated1(arr, 3)
        expected = 6
        
        assert actual == expected

from py.problems.sorting import Listy
from py.problems.sorting import sorted_find1
class Test_SortedFind1(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_none(self):

        values = None

        actual = sorted_find1(values, 1)
        expected = None

        assert actual == expected

    def test_case1(self):

        values = Listy( [0] * 32 + [1, 1, 1, 1, 2, 3, 10, 12, 15] )

        actual = sorted_find1(values, 12)
        expected = 39

        assert actual == expected

    def test_case2(self):

        values = Listy( [1, 1, 1, 1, 2, 3, 10, 12, 15] )

        actual = sorted_find1(values, 1)
        expected = 3

        assert actual == expected

    def test_case3(self):

        values = Listy( [1, 1, 1, 1, 2, 3, 10, 12, 15] )

        actual = sorted_find1(values, 10)
        expected = 6

        assert actual == expected

    def test_case4(self):

        values = Listy( [1, 1, 1, 1, 2, 3, 10, 12, 15] )

        actual = sorted_find1(values, 10)
        expected = 6

        assert actual == expected

    def test_case5(self):

        values =  Listy( [0] * 128 + [1, 1, 1, 1, 2, 3, 10, 12, 15] )

        actual = sorted_find1(values, 10)
        expected = 134

        assert actual == expected
    
from py.problems.sorting import sparse_search
class Test_SparseSearch1(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_none(self):

        values = None

        actual = sparse_search(values, '')
        expected = None

        assert actual == expected

    def test_empty(self):

        values = ["at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""]

        actual = sparse_search(values, '')
        expected = -1

        assert actual == expected

    def test_case1(self):

        values = ["at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""]

        actual = sparse_search(values, 'ball')
        expected = 4

        assert actual == expected

    def test_case2(self):

        values = ["at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""]

        actual = sparse_search(values, 'at')
        expected = 0

        assert actual == expected

    def test_case3(self):

        values = ["at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""]

        actual = sparse_search(values, 'car')
        expected = 7

        assert actual == expected

    def test_case4(self):

        values = ["at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""]

        actual = sparse_search(values, 'dad')
        expected = 10

        assert actual == expected

    def test_case5(self):

        values = ["at", "", "", "", "ball", "", "", "car", "", "", "dad", "", "", "elf"]

        actual = sparse_search(values, 'elf')
        expected = 13

        assert actual == expected