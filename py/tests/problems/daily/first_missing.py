import unittest

from dcp.problems.daily.first_missing import first_missing1

class Test_FirstMissing1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        assert first_missing1([3, 4, -1, 1]) == 2

    def test_case2(self):
        assert first_missing1([1, 2, 0]) == 3

    def test_case3(self):
        assert first_missing1([1, 2, 2, 1, 0]) == 3

from dcp.problems.daily.first_missing import first_missing2

class Test_FirstMissing2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):        
        assert first_missing2([3, 4, -1, 1]) == 2

    def test_case2(self):
        assert first_missing2([1, 2, 0]) == 3

    def test_case3(self):
        assert first_missing2([1, 2, 2, 1, 0]) == 3