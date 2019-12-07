import unittest

from arr import arrprod, smallest_window

class Test_ArrayProd(unittest.TestCase):
    
    _func = arrprod
    
    def setUp(self):
        pass
    
    def test_case1(self):
        assert arrprod([1, 2, 3, 4, 5]) == [120, 60, 40, 30, 24]

    def test_case2(self):
        assert arrprod( [3, 2, 1] ) == [2, 3, 6]

class Test_SmallestWindow(unittest.TestCase):

    _func = smallest_window

    def setUp(self):
        pass
    
    def test_case1(self):
        assert smallest_window([3, 7, 5, 6, 9]) == (1, 3)
    
    def test_case2(self):
        assert smallest_window([3, 7, 5, 6, 9, 2, 3, 14, 15, 16, 17, 1.5]) == (1, 11)
        
if __name__ == '__main__':
    unittest.main()