import unittest

from py.leetcode.recursion import pascals_triangle

class Test_PascalsTriangle(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        actual = pascals_triangle.generate(5)
        expected = [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

        assert actual == expected