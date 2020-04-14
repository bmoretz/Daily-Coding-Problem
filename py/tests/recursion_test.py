import unittest

from py.problems.recursion import matches
class Test_RegularExpression(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        s, r = 'ray', 'ra.'

        assert matches(s, r) == True

    def test_case2(self):

        s, r = 'raymond', 'ra.'

        assert matches(s, r) == False

from py.problems.recursion import min_and_max1, min_and_max2
class Test_MinMax(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
    
        assert min_and_max1([4, 2, 7, 5, -1, 3, 6]) == (-1, 7)

    def test_case2(self):

        assert min_and_max2([4, 2, 7, 5, -1, 3, 6]) == (-1, 7)

from py.problems.recursion import nim1, nim2
class Test_PlayNim(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
    
        assert nim1([3, 4, 5]) == True

    def test_case2(self):

        assert nim2([3, 4, 5]) == True

from py.problems.recursion import triple_step1
class Test_TripleStep1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        n = 4

        actual = triple_step1(n)
        expected = 7

        assert actual == expected

    def test_case2(self):

        n = 10

        actual = triple_step1(n)
        expected = 274

        assert actual == expected

    def test_case3(self):

        n = 15

        actual = triple_step1(n)
        expected = 5768

        assert actual == expected

    def test_case4(self):

        n = 3

        actual = triple_step1(n)
        expected = 4

        assert actual == expected

    def test_case5(self):

        n = 8

        actual = triple_step1(n)
        expected = 81

        assert actual == expected

from py.problems.recursion import triple_step2
class Test_TripleStep2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        n = 4

        actual = triple_step2(n)
        expected = 7

        assert actual == expected

    def test_case2(self):

        n = 10

        actual = triple_step2(n)
        expected = 274

        assert actual == expected

    def test_case3(self):

        n = 15

        actual = triple_step2(n)
        expected = 5768

        assert actual == expected

    def test_case4(self):

        n = 3

        actual = triple_step2(n)
        expected = 4

        assert actual == expected

    def test_case5(self):

        n = 8

        actual = triple_step2(n)
        expected = 81

        assert actual == expected

from py.problems.recursion import build_grid
from py.problems.recursion import robot_walk1
class Test_RobotWalk1(unittest.TestCase):
    
    def setUp(self):
        pass
    
    '''
    0   0   0   0   0   0
    0   1   1   0   1   0
    1   0   0   0   1   0
    0   0   1   0   1   0
    0   0   1   0   0   0
    '''
    def test_case1(self):

        obsticals = [(1,1), (1,2), (1,4), (2, 0), (2, 4), (3, 2), (3, 4), (4,2)]

        grid = build_grid(6, 5, obsticals)

        actual = robot_walk1(grid)

        expected = [(0, 0), (0, 1), (0, 2), (0, 3), (0, 4), (0, 5), (1, 5), (2, 5), (3, 5), (4, 5)]

        assert actual == expected

    '''
    0   0   0   0   1   0
    0   1   1   0   1   0
    1   0   0   0   1   0
    0   0   1   0   1   0
    0   0   1   0   0   0
    '''
    def test_case2(self):

        obsticals = [(0, 4), (1,1), (1,2), (1,4), (2, 0), (2, 4), (3, 2), (3, 4), (4,2)]
        
        grid = build_grid(6, 5, obsticals)

        actual = robot_walk1(grid)

        expected = [(0, 0), (0, 1), (0, 2), (0, 3), (1, 3), (2, 3), (3, 3), (4, 3), (4, 4), (4, 5)]

        assert actual == expected

    '''
    0   1   0   0   1   0
    0   1   1   0   1   0
    1   0   0   0   1   0
    0   0   1   0   1   0
    0   0   1   0   0   0
    '''
    def test_case3(self):

        obsticals = [(0, 1), (0, 4), (1,1), (1,2), (1,4), (2, 0), (2, 4), (3, 2), (3, 4), (4,2)]
        
        grid = build_grid(6, 5, obsticals)

        actual = robot_walk1(grid)

        expected = [(0, 0), (1, 0), (-1, -1)] # no path

        assert actual == expected

    '''
    0   0   0   1   1   0
    0   1   0   0   1   0
    1   0   1   0   1   0
    0   0   1   0   0   1
    0   0   1   0   0   0
    '''
    def test_case4(self):

        obsticals = [(0, 4), (1,1), (0,4), (1,4), (2, 0), (2,2), (2, 4), (3, 2), (3, 4), (4,2)]
        
        grid = build_grid(6, 5, obsticals)

        actual = robot_walk1(grid)

        expected = [(0, 0), (0, 1), (0, 2), (0, 3), (1, 3), (2, 3), (3, 3), (4, 3), (4, 4), (4, 5)]

        assert actual == expected

    '''
    0   0   0   0   1   0
    0   1   0   0   1   0
    1   0   1   0   1   0
    0   0   1   0   1   0
    0   0   1   0   0   1
    '''
    def test_case5(self):

        obsticals = [(0, 4), (1,1), (0,4), (1,4), (2, 0), (2,2), (2, 4), (3, 2), (3, 4), (4,2), (4,5)]
        
        grid = build_grid(6, 5, obsticals)

        actual = robot_walk1(grid)

        expected = [(0, 0), (0, 1), (0, 2), (0, 3), (1, 3), (2, 3), (3, 3), (4, 3), (4, 4), (-1, -1), (1, 2), (1, 3), (2, 3), (3, 3), (4, 3), (4, 4), (-1, -1), (1, 0), (-1, -1)]

        assert actual == expected