import unittest

from py.problems.matrix import print_mat, build_mat

from py.problems.matrix import rotate1
class Test_Rotate1(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):

        assert rotate1(None) == None

    def test_case2(self):
        expected = [[3, 1], [4, 2]]

        assert rotate1(build_mat(2, 2)) == expected

    def test_case3(self):
         expected = [[7, 4, 1], [8, 5, 2], [9, 6, 3]]

         assert rotate1(build_mat(3, 3)) == expected

    def test_case4(self):

        expected = [[13, 9, 5, 1], [14, 10, 6, 2], [15, 11, 7, 3], [16, 12, 8, 4]]
        
        assert rotate1(build_mat(4, 4)) == expected
    
    def test_case5(self):

        expected = [[21, 16, 11, 6, 1], [22, 17, 12, 7, 2], [23, 18, 13, 8, 3], [24, 19, 14, 9, 4], [25, 20, 15, 10, 5]]

        assert rotate1(build_mat(5, 5)) == expected

from py.problems.matrix import rotate2
class Test_Rotate2(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):

        assert rotate2(None) == None

    def test_case2(self):
        expected = [(3, 1), (4, 2)]

        assert rotate2(build_mat(2, 2)) == expected

    def test_case3(self):
         expected = [(7, 4, 1), (8, 5, 2), (9, 6, 3)]

         assert rotate2(build_mat(3, 3)) == expected
         
    def test_case4(self):

        expected = [(13, 9, 5, 1), (14, 10, 6, 2), (15, 11, 7, 3), (16, 12, 8, 4)]
        
        assert rotate2(build_mat(4, 4)) == expected
    
    def test_case5(self):

        expected = [(21, 16, 11, 6, 1), (22, 17, 12, 7, 2), (23, 18, 13, 8, 3), (24, 19, 14, 9, 4), (25, 20, 15, 10, 5)]

        assert rotate2(build_mat(5, 5)) == expected

from py.problems.matrix import zero1
class Test_Zero1(unittest.TestCase):

    def setUp(self):
        pass

    '''
    In:

    1 0 1 1
    1 1 1 1
    1 1 1 1
    1 1 1 1
    
    Out:

    0 0 0 0
    1 0 1 1
    1 0 1 1
    1 0 1 1    
    '''
    def test_case1(self):

        expected = [[0, 0, 0, 0], [1, 0, 1, 1], [1, 0, 1, 1], [1, 0, 1, 1]]

        m, n = 4, 4

        mat = [[1] * n for _ in range(m)]

        mat[0][1] = 0

        assert zero1(mat) == expected

    '''
    In:

    1 0 1 1
    1 1 0 1
    1 1 1 1
    1 1 1 1
    
    Out:

    0 0 0 0
    0 0 0 0
    1 0 0 1
    1 0 0 1  
    '''
    def test_case2(self):

        expected = [[0, 0, 0, 0], [0, 0, 0, 0], [1, 0, 0, 1], [1, 0, 0, 1]]

        m, n = 4, 4

        mat = [[1] * n for _ in range(m)]

        mat[0][1] = 0
        mat[1][2] = 0

        assert zero1(mat) == expected

    '''
    In:

    1 0 1 1 
    1 1 0 1
    1 1 1 1
    0 1 1 1
    
    Out:

    0 0 0 0
    0 0 0 0
    0 0 0 1
    0 0 0 0 
    '''
    def test_case3(self):

        expected = [[0, 0, 0, 0], [0, 0, 0, 0], [1, 0, 0, 1], [1, 0, 0, 1]]

        m, n = 4, 4

        mat = [[1] * n for _ in range(m)]

        mat[0][1] = 0
        mat[1][2] = 0

        assert zero1(mat) == expected