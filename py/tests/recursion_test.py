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
