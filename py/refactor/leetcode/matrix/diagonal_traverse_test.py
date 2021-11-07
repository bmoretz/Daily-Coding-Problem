import unittest

from leetcode.matrix import diagonal_traverse

class Test_DiagonalTraverse(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
                
        mat = [
            [ 1, 2, 3 ],
            [ 4, 5, 6 ],
            [ 7, 8, 9 ]
        ]

        actual = diagonal_traverse.findDiagonalOrder(mat)

        expected = [1,2,4,7,5,3,6,8,9]

        assert actual == expected