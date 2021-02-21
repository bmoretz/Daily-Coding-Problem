
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

        actual = minimum_index_sum().findRestaurant(list1, list2)

        expected = ['Shogun']

        assert actual == expected

    def test_case2(self):
        
        list1, list2 = ["Shogun","Tapioca Express","Burger King","KFC"], ["KNN","KFC","Burger King","Tapioca Express","Shogun"]

        actual = minimum_index_sum().findRestaurant(list1, list2)

        expected = ["Shogun","Tapioca Express","Burger King","KFC"]

        assert actual == expected

    def test_case3(self):

        list1, list2 = ["KFC"], ["KFC"]

        actual = minimum_index_sum().findRestaurant(list1, list2)

        expected = ["KFC"]

        assert actual == expected