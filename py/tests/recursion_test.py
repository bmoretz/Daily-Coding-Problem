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