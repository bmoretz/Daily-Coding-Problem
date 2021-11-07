import unittest

from problems.dynamic import fib1
class Test_Fibonacci(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        assert fib1(10) == 55

from problems.dynamic import fib2
class Test_Fibonacci(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        assert fib2(10) == 55

from problems.dynamic import staircase1
class Test_Staircase1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        n = 4

        assert staircase1(n, range(1, n)) == 7

from problems.dynamic import staircase2
class Test_Staircase2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        n = 4
        
        assert staircase2(n, range(1, n)) == 7

from problems.dynamic import num_encodings1
class Test_NumEncodings1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        assert num_encodings1('111') == 3

from problems.dynamic import num_encodings2
class Test_NumEncodings2(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):
        actual, expected = num_encodings2('111'), 1

        assert actual == expected

from problems.dynamic import build_houses
class Test_PaintHouses(unittest.TestCase):
    
    def setUp(self):
        self.cost_matrix = [
            [11, 12, 13],
            [14, 15, 16],
            [17, 18, 19]
        ]

    def test_case1(self):

        assert build_houses(self.cost_matrix) == 43
