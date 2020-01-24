import unittest

from problems.hashtable import two_sum1
from problems.hashtable import LRUCache
from problems.hashtable import SparseArray
from problems.hashtable import fewest_cuts1

class Test_TwoSum1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        arr, k = [10, 15, 3, 7], 17

        assert two_sum1(arr, k) == True

class Test_LRUCache(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):

        cache = LRUCache(5)

        for index in range(10):
            cache.set(index, index**2)

        assert list( cache.dict.keys() ) == [5, 6, 7, 8, 9]

class Test_FewestCuts(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):

        wall1 = [[3, 5, 1, 1], \
                [2, 3, 3, 2], \
                [5, 5], \
                [4, 4, 2], \
                [1, 3, 3, 3], \
                [1, 1, 6, 1, 1]]
                
        assert fewest_cuts1(wall1) == 2

    def test_case2(self):

        wall2 = [[1,2,2,1],
                [3,1,2],
                [1,3,2],
                [2,4],
                [3,1,2],
                [1,3,1,1]]
                
        assert fewest_cuts1(wall2) == 2

class Test_SparseArray(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):

        arr, n = [0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1], 100

        sa = SparseArray(arr, n)

        non_zero = [5, 13, 19, 28]

        for index in range(len(arr)):

            if index in non_zero:
                assert sa.get(index) != 0
            else:
                assert sa.get(index) == 0