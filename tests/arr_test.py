import unittest

from problems.arr import product1, product2, product3
from problems.arr import window1
from problems.arr import max_subarray_sum1
from problems.arr import smaller_counts1

class Test_ArrayProduct1(unittest.TestCase):
    
    _inst = product1
    
    def setUp(self):
        pass
    
    def test_case1(self):
        assert self._inst.func( [1, 2, 3, 4, 5] ) == [120, 60, 40, 30, 24]

    def test_case2(self):
        assert self._inst.func( [3, 2, 1] ) == [2, 3, 6]

class Test_ArrayProduct2(unittest.TestCase):
    
    _inst = product2
    
    def setUp(self):
        pass
    
    def test_case1(self):
        assert self._inst.func( [1, 2, 3, 4, 5] ) == [120, 60, 40, 30, 24]

    def test_case2(self):
        assert self._inst.func( [3, 2, 1] ) == [2, 3, 6]


class Test_ArrayProduct3(unittest.TestCase):
    
    _inst = product3
    
    def setUp(self):
        pass
    
    def test_case1(self):
        assert self._inst.func( [1, 2, 3, 4, 5] ) == [120, 60, 40, 30, 24]

    def test_case2(self):
        assert self._inst.func( [3, 2, 1] ) == [2, 3, 6]

class Test_SmallestWindow(unittest.TestCase):

    _inst = window1

    def setUp(self):
        pass
    
    def test_case1(self):
        assert self._inst.func( [3, 7, 5, 6, 9]) == (1, 3)
    
    def test_case2(self):
        assert self._inst.func( [3, 7, 5, 6, 9, 2, 3, 14, 15, 16, 17, 1.5]) == (1, 11)

class Test_MaxSubarraySum(unittest.TestCase):

    _inst = max_subarray_sum1

    def setUp(self):
        pass

    def test_case1(self):
        assert self._inst.func( [34, -50, 42, 14, -5, 86]) == 137
    
    def test_case2(self):
        assert self._inst.func( [-5, -1, 8, -9]) == 0


class Test_SmallerCounts1(unittest.TestCase):

    _inst = smaller_counts1

    def setUp(self):
        pass

    def test_case1(self):
        assert self._inst.func( [3, 4, 9, 6, 1]) == [1, 1, 2, 1, 0]
    
    def test_case2(self):
        assert self._inst.func( [2, 5, 4, 7, 8]) == [0, 1, 0, 0, 0]

if __name__ == '__main__':
    unittest.main()