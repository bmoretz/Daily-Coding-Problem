import unittest

from problems.heap import RunningMedian1, running_median2
from problems.heap import similarity1
from problems.heap import regular_numbers1, regular_numbers2
from problems.heap import huffman_coding1

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


class Test_RegularNumbers1(unittest.TestCase):
    
    def setUp(self):
        self.regulars = [1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, 16, 18, 20, 24, 25,
            27, 30, 32, 36, 40, 45, 48, 50, 54, 60, 64, 72, 75, 80, 81, 90, 96, 100,
                108, 120, 125, 128, 135, 144, 150, 160, 162, 180, 192, 200, 216, 225, 240, 
                243, 250, 256, 270, 288, 300, 320, 324, 360, 375, 384, 400, 405, 432, 450, 480,
                486, 500, 512, 540, 576, 600, 625, 640, 648, 675, 720, 729, 750, 768, 800, 810, 
                864, 900, 960, 972, 1000, 1024, 1080, 1125, 1152, 1200, 1215, 1250, 1280, 1296,
                1350, 1440, 1458, 1500, 1536]

    def test_case1(self):      
        assert regular_numbers1(10) == self.regulars[:10]

class Test_RegularNumbers2(unittest.TestCase):
    
    def setUp(self):
        self.regulars = [1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, 16, 18, 20, 24, 25,
            27, 30, 32, 36, 40, 45, 48, 50, 54, 60, 64, 72, 75, 80, 81, 90, 96, 100,
                108, 120, 125, 128, 135, 144, 150, 160, 162, 180, 192, 200, 216, 225, 240, 
                243, 250, 256, 270, 288, 300, 320, 324, 360, 375, 384, 400, 405, 432, 450, 480,
                486, 500, 512, 540, 576, 600, 625, 640, 648, 675, 720, 729, 750, 768, 800, 810, 
                864, 900, 960, 972, 1000, 1024, 1080, 1125, 1152, 1200, 1215, 1250, 1280, 1296,
                1350, 1440, 1458, 1500, 1536]

    def test_case1(self):      
        assert list(regular_numbers2(10)) == self.regulars[:10]

class Test_HuffmanCoding1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):       
        value = 'aaacccccceeeeeeeeff'

        coded = huffman_coding1(value)

        assert coded['a'] == '101'
        assert coded['c'] == '11'
        assert coded['e'] == '0'
        assert coded['f'] == '100'
        
    def test_case2(self):
        pass