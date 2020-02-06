import unittest

from problems.heap import RunningMedian1, running_median2
from problems.heap import similarity1

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

class Test_SiteSimilarity1(unittest.TestCase):
    
    def setUp(self):
        self.sites = [('google.com', 1), ('google.com', 3), ('google.com', 5), \
                        ('pets.com', 1), ('pets.com', 2), ('yahoo.com', 6), ('yahoo.com', 2), \
                        ('yahoo.com', 3), ('yahoo.com', 4), ('yahoo.com', 5), \
                        ('wikipedia.org', 4), ('wikipedia.org', 5), ('wikipedia.org', 6), \
                        ('wikipedia.org', 7), ('bing.com', 1), ('bing.com', 3), ('bing.com', 5), \
                        ('bing.com', 6)]

    def test_case1(self):       
        
        assert similarity1(self.sites, k = 1) == [('google.com', 'bing.com')]
        
    def test_case2(self):
        
        assert similarity1(self.sites, k = 2) == [('yahoo.com', 'wikipedia.org'), \
                        ('google.com', 'bing.com')]