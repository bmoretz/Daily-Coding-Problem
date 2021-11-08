import unittest

from dcp.problems.linkedlist.single import build_list
from dcp.problems.linkedlist.kth_last import klast1, klast2

class Test_KLast1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        assert klast1(None, 0) == None

    def test_case2(self):
        
        values = build_list([1, 2, 3, 4, 5, 6, 7])

        actual = klast1(values, 0)
        expected = 7
        
        assert actual == expected
        
    def test_case3(self):

        values = build_list([1, 2, 3, 4, 5, 6, 7])

        actual = klast1(values, 2)
        expected = 5

        assert actual == expected

    def test_case4(self):

        values = build_list([1, 2, 3, 4, 5, 6, 7])

        actual = klast1(values, 6)
        expected = 1
        
        assert actual == expected

    def test_case5(self):

        values = build_list([1, 2, 3, 4, 5, 6, 7])

        actual = klast1(values, 3)
        expected = 4

        assert expected == actual

class Test_KLast2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        assert klast2(None, 0) == None

    def test_case2(self):
        
        values = build_list([1, 2, 3, 4, 5, 6, 7])

        actual = klast2(values, 0)
        expected = 7
        
        assert actual == expected
        
    def test_case3(self):

        values = build_list([1, 2, 3, 4, 5, 6, 7])

        actual = klast2(values, 2)
        expected = 5

        assert actual == expected

    def test_case4(self):

        values = build_list([1, 2, 3, 4, 5, 6, 7])

        actual = klast2(values, 6)
        expected = 1
        
        assert actual == expected

    def test_case5(self):

        values = build_list([1, 2, 3, 4, 5, 6, 7])

        actual = klast2(values, 3)
        expected = 4

        assert expected == actual