import unittest

from dcp.problems.hashtable.sparse_array import SparseArray

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