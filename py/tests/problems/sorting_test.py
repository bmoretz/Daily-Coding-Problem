import unittest

from problems.sorting import merge_sort1
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

from problems.sorting import sorted_merge1
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

from problems.sorting import group_anagrams1
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

from problems.sorting import group_anagrams2
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

from problems.sorting import find_rotated1
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

from problems.sorting import Listy
from problems.sorting import sorted_find1
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
    
from problems.sorting import sparse_search
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
    
from problems.sorting import build_mat
from problems.sorting import mat_search
class Test_MatrixSearch1(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_none(self):

        values = None

        actual = mat_search(values, 34)
        expected = None

        assert actual == expected

    def test_case1(self):

        values = build_mat(10)

        actual = mat_search(values, 36)
        expected = (3, 5)

        assert actual == expected

    def test_case2(self):

        values = build_mat(10)

        actual = mat_search(values, 1)
        expected = (0, 0)

        assert actual == expected

    def test_case3(self):

        values = build_mat(10)

        actual = mat_search(values, 100)
        expected = (9, 9)

        assert actual == expected

    def test_case4(self):

        values = build_mat(10)

        actual = mat_search(values, 72)
        expected = (7, 1)

        assert actual == expected

    def test_case5(self):

        values = build_mat(10)

        actual = mat_search(values, 27)
        expected = (2, 6)

        assert actual == expected

from problems.sorting import RankStream
class Test_RankStream1(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_none(self):

        values = None

        rs = RankStream.track_values(values)

        actual = rs.get_rank(0)
        expected = None

        assert actual == expected

    def test_empty(self):

        values = []

        rs = RankStream.track_values(values)

        actual = rs.get_rank(0)
        expected = None

        assert actual == expected

    def test_case1(self):

        values = [5, 1, 4, 4, 5, 9, 7, 13, 3]

        rs = RankStream.track_values(values)

        actual = rs.get_rank(0)
        expected = 0

        assert actual == expected

    def test_case2(self):

        values = [5, 1, 4, 4, 5, 9, 7, 13, 3]

        rs = RankStream.track_values(values)

        actual = rs.get_rank(1)
        expected = 1

        assert actual == expected

    def test_case3(self):

        values = [5, 1, 4, 4, 5, 9, 7, 13, 3]

        rs = RankStream.track_values(values)

        actual = rs.get_rank(5)
        expected = 6

        assert actual == expected

    def test_case4(self):

        values = [5, 1, 4, 4, 5, 9, 7, 13, 3]

        rs = RankStream.track_values(values)

        actual = rs.get_rank(4)
        expected = 4

        assert actual == expected

    def test_case5(self):

        values = [5, 1, 4, 4, 5, 9, 7, 13, 3]

        rs = RankStream.track_values(values)

        actual = rs.get_rank(13)
        expected = 9

        assert actual == expected

from problems.sorting import alt_sort1
class Test_AltSort1(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_none(self):

        values = None

        actual = alt_sort1(values)
        expected = None

        assert actual == expected

    def test_empty(self):

        values = []

        actual = alt_sort1(values)
        expected = []

        assert actual == expected

    def test_case1(self):

        values = [5, 3, 1, 2, 3]

        actual = alt_sort1(values)
        expected = [5, 1, 3, 2, 3]

        assert actual == expected

    def test_case2(self):

        values = [3, 5, 1, 4, 9, 8, 2, 1]

        actual = alt_sort1(values)
        expected = [9, 1, 8, 1, 5, 2, 4, 3]

        assert actual == expected

    def test_case3(self):

        values = [4, 2, 1, 4, 6, 7, 9, 3]

        actual = alt_sort1(values)
        expected = [9, 1, 7, 2, 6, 3, 4, 4]

        assert actual == expected

    def test_case4(self):

        values = [4, 3, 5, 7, 1, 3, 8, 12, 4, 13, 5]

        actual = alt_sort1(values)
        expected = [13, 1, 12, 3, 8, 3, 7, 4, 5, 4, 5]

        assert actual == expected

    def test_case5(self):

        values = [12, 33, 12, 23, 4, 12, 83, 3, 31, 12, 41, 1, 2, 3, 4]

        actual = alt_sort1(values)
        expected = [83, 1, 41, 2, 33, 3, 31, 3, 23, 4, 12, 4, 12, 12, 12]

        assert actual == expected

from problems.sorting import alt_sort2
class Test_AltSort2(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_none(self):

        values = None

        actual = alt_sort2(values)
        expected = None

        assert actual == expected

    def test_empty(self):

        values = []

        actual = alt_sort2(values)
        expected = []

        assert actual == expected

    def test_case1(self):

        values = [5, 3, 1, 2, 3]

        actual = alt_sort2(values)
        expected = [5, 1, 3, 2, 3]

        assert actual == expected

    def test_case2(self):

        values = [3, 5, 1, 4, 9, 8, 2, 1]

        actual = alt_sort2(values)
        expected = [9, 1, 8, 1, 5, 2, 4, 3]

        assert actual == expected

    def test_case3(self):

        values = [4, 2, 1, 4, 6, 7, 9, 3]

        actual = alt_sort2(values)
        expected = [9, 1, 7, 2, 6, 3, 4, 4]

        assert actual == expected

    def test_case4(self):

        values = [4, 3, 5, 7, 1, 3, 8, 12, 4, 13, 5]

        actual = alt_sort2(values)
        expected = [13, 1, 12, 3, 8, 3, 7, 4, 5, 4, 5]

        assert actual == expected

    def test_case5(self):

        values = [12, 33, 12, 23, 4, 12, 83, 3, 31, 12, 41, 1, 2, 3, 4]

        actual = alt_sort2(values)
        expected = [83, 1, 41, 2, 33, 3, 31, 3, 23, 4, 12, 4, 12, 12, 12]

        assert actual == expected

from problems.sorting import sub_sort1
class Test_SubSort1(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_none(self):

        values = None

        actual = sub_sort1(values)
        expected = None

        assert actual == expected

    def test_case1(self):

        values = [1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19]

        actual = sub_sort1(values)
        expected = (3, 9)

        assert actual == expected

    def test_case2(self):

        values = [1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19, 4]

        actual = sub_sort1(values)
        expected = (3, 14)

        assert actual == expected

    def test_case3(self):

        values = [20, 1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19, 4]

        actual = sub_sort1(values)
        expected = (0, 15)

        assert actual == expected

    def test_case4(self):

        values = [1, 2, 4, 7, 10, 11, 7, 12, 6, 7, -1, 16, 18, 19]

        actual = sub_sort1(values)
        expected = (0, 11)

        assert actual == expected

    def test_case5(self):

        values = [1, 2, 3, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19]

        actual = sub_sort1(values)
        expected = (4, 10)

        assert actual == expected

from problems.sorting import CircusTower
class Test_CircusTower(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_none(self):

        values = None

        ct = CircusTower()

        actual = ct.max_tower()
        expected = None

        assert actual == expected

    def test_case1(self):

        people = [(65, 100), (70, 150), (56, 90), (75, 190), (60, 95), (68, 110)]

        ct = CircusTower()

        for weight, height in people:
            ct.add_person(weight, height)

        actual = ct.max_tower()
        expected = [(56, 90), (60, 95), (65, 100), (68, 110), (70, 150), (75, 190)]

        assert actual == expected

    def test_case2(self):

        people = [(65, 100), (70, 150), (56, 90), (75, 190), (60, 95), (68, 110), (45, 120)]

        ct = CircusTower()

        for weight, height in people:
            ct.add_person(weight, height)

        actual = ct.max_tower()
        expected = [(56, 90), (60, 95), (65, 100), (68, 110), (70, 150), (75, 190)]

        assert actual == expected

    def test_case3(self):

        people = [(65, 100), (70, 150), (56, 90), (75, 190), (60, 95), (68, 110), (45, 120)]

        ct = CircusTower()

        for weight, height in people:
            ct.add_person(weight, height)

        actual = ct.max_tower()
        expected = [(56, 90), (60, 95), (65, 100), (68, 110), (70, 150), (75, 190)]

        assert actual == expected

    def test_case4(self):

        people = [(65, 100), (70, 212), (56, 32), (48, 190), (60, 95), (68, 110), (45, 120)]

        ct = CircusTower()

        for weight, height in people:
            ct.add_person(weight, height)

        actual = ct.max_tower()
        expected = [(56, 32), (60, 95), (65, 100), (68, 110), (70, 212)]

        assert actual == expected

    def test_case5(self):

        people = [(65, 100), (70, 124), (56, 82), (48, 150), (60, 95), (68, 95), (45, 120), (45, 120)]

        ct = CircusTower()

        for weight, height in people:
            ct.add_person(weight, height)

        actual = ct.max_tower()
        expected = [(56, 82), (60, 95), (65, 100), (70, 124)]

        assert actual == expected