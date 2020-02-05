import unittest

from problems.heap import RunningMedian1, running_median2

class Test_RunningMedian1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):       
        values, rm = [2, 1, 5, 7, 2, 0, 5], RunningMedian1()

        medians = []

        for val in values:
            rm.insert(val)
            medians.append(rm.median())

        assert medians == [2.0, 1.5, 2.0, 3.5, 2.0, 2.0, 2.0]

    def test_case2(self):
        pass

class Test_RunningMedian2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):       
        values = [2, 1, 5, 7, 2, 0, 5]

        medians = running_median2(values)

        assert medians == [2.0, 1.5, 2.0, 3.5, 2.0, 2.0, 2.0]
        
    def test_case2(self):
        pass
