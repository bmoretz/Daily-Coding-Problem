
import unittest

from py.leetcode.hashtable import is_isomorphic

class Test_IsIsomorphic(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        s, t = "egg", "add"
        
        actual = is_isomorphic.isIsomorphic(s, t)
        expected = True

        assert actual == expected

    def test_case2(self):
        
        s, t = "foo", "bar"
        
        actual = is_isomorphic.isIsomorphic(s, t)
        expected = False
        
        assert actual == expected

    def test_case3(self):
        
        s, t = "paper", "title"
        
        actual = is_isomorphic.isIsomorphic(s, t)
        expected = True
        
        assert actual == expected

from py.leetcode.hashtable import minimum_index_sum

class Test_MinimumIndexSum(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        list1, list2 = ["Shogun","Tapioca Express","Burger King","KFC"], ["KFC","Shogun","Burger King"]

        actual = minimum_index_sum.findRestaurant(list1, list2)

        expected = ['Shogun']

        assert actual == expected

    def test_case2(self):
        
        list1, list2 = ["Shogun","Tapioca Express","Burger King","KFC"], ["KNN","KFC","Burger King","Tapioca Express","Shogun"]

        actual = minimum_index_sum.findRestaurant(list1, list2)

        expected = ["Shogun","Tapioca Express","Burger King","KFC"]

        assert actual == expected

    def test_case3(self):

        list1, list2 = ["KFC"], ["KFC"]

        actual = minimum_index_sum.findRestaurant(list1, list2)

        expected = ["KFC"]

        assert actual == expected

from py.leetcode.hashtable import contains_duplicate_ii

class Test_ContainsDuplicate_II(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        nums, k = [1,2,3,1], 3

        actual = contains_duplicate_ii.containsNearbyDuplicate(nums, k)
        expected = True

        assert actual == expected

    def test_case2(self):
        
        nums, k = [1,0,1,1], 1

        actual = contains_duplicate_ii.containsNearbyDuplicate(nums, k)
        expected = True
        
        assert actual == expected

    def test_case3(self):

        nums, k = [1,2,3,1,2,3], 2

        actual = contains_duplicate_ii.containsNearbyDuplicate(nums, k)
        expected = False
        
        assert actual == expected


from py.leetcode.hashtable import group_anagrams

class Test_GroupAnagrams(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
                
        strs = ["eat","tea","tan","ate","nat","bat"]

        actual = group_anagrams().groupAnagrams(strs)
        expected = [['eat', 'tea', 'ate'], ['tan', 'nat'], ['bat']]

        assert actual == expected

    def test_case2(self):
        
        strs = [""]

        actual = group_anagrams().groupAnagrams(strs)
        expected = [[""]]
        
        assert actual == expected

    def test_case3(self):

        strs = ["a"]

        actual = group_anagrams().groupAnagrams(strs)
        expected = [["a"]]
        
        assert actual == expected

from py.leetcode.hashtable import valid_sudoku

class Test_ValidSudoku(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
                
        board = [["5","3",".",".","7",".",".",".","."],
                ["6",".",".","1","9","5",".",".","."],
                [".","9","8",".",".",".",".","6","."],
                ["8",".",".",".","6",".",".",".","3"],
                ["4",".",".","8",".","3",".",".","1"],
                ["7",".",".",".","2",".",".",".","6"],
                [".","6",".",".",".",".","2","8","."],
                [".",".",".","4","1","9",".",".","5"],
                [".",".",".",".","8",".",".","7","9"]]

        actual = valid_sudoku().isValidSudoku(board)
        expected = True

        assert actual == expected

    def test_case2(self):
        
        board = [["8","3",".",".","7",".",".",".","."],
                ["6",".",".","1","9","5",".",".","."],
                [".","9","8",".",".",".",".","6","."],
                ["8",".",".",".","6",".",".",".","3"],
                ["4",".",".","8",".","3",".",".","1"],
                ["7",".",".",".","2",".",".",".","6"],
                [".","6",".",".",".",".","2","8","."],
                [".",".",".","4","1","9",".",".","5"],
                [".",".",".",".","8",".",".","7","9"]]

        actual = valid_sudoku().isValidSudoku(board)
        expected = False
        
        assert actual == expected