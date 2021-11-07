import unittest

from leetcode.arr import max_consecutive_ones

class Test_MaxConsecutiveOnes(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        s = [1,1,0,1,1,1]

        actual = max_consecutive_ones.findMaxConsecutiveOnes(s)
        expected = 3

        assert actual == expected

    def test_case2(self):
        
        s = [0,1,0,1,0,1,0,1,1,1,0]
        
        actual = max_consecutive_ones.findMaxConsecutiveOnes(s)
        expected = 3

        assert actual == expected