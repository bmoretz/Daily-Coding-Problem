import unittest

from dcp.problems.hashtable.sparse_matrix import SparseMatrix

class Test_SparseMatrix(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):

        mat = [[0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1], \
                [0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1], \
                [0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1], \
                [0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1], \
                [0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1]]
                
        n, m = 100, 100
        sm = SparseMatrix(mat, n, m)

        non_zero = [[5, 13, 19, 28], \
                    [5, 13, 19, 28], \
                    [5, 13, 19, 28], \
                    [5, 13, 19, 28], \
                    [5, 13, 19, 28]]

        for n, row in enumerate(mat):
            for m, _ in enumerate(row):

                if m in non_zero[n]:
                    assert sm.get(n, m) != 0
                else:
                    assert sm.get(n, m) == 0