import unittest

from leetcode.arr import plus_one

class Test_PlusOne(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        actual = plus_one.plusOne([4,3,2,1])
        expected = [4,3,2,2]

        assert actual == expected

    def test_case2(self):
        
        actual = plus_one.plusOne([4,3,3,9])
        expected = [4,3,4,0]

        assert actual == expected

    def test_case3(self):
        
        actual = plus_one.plusOne([9])
        expected = [1,0]

        assert actual == expected