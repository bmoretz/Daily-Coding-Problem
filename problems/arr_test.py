import unittest

from arr import arrprod

class Test_ArrayProd(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_case1(self):
        assert arrprod([1, 2, 3, 4, 5]) == [120, 60, 40, 30, 24]

    def test_case2(self):
        assert arrprod( [3, 2, 1] ) == [2, 3, 6]

if __name__ == '__main__':
    unittest.main()