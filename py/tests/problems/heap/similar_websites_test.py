import unittest

from dcp.problems.heap.similar_websites import similarity1

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