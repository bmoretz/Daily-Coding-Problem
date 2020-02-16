import unittest

from problems.misc import Subscribers1, Subscribers2

'''Classic Dictionary'''
class Test_Subscribers1(unittest.TestCase):
    
    def setUp(self):
        self.subs = Subscribers1([4, 8, 1, 9, 3, 5, 5, 3])

    def test_case1(self):
        assert self.subs.query(0, 4) == 25

'''Fenwick Tree'''
class Test_Subscribers2(unittest.TestCase):
    
    def setUp(self):
        self.subs = Subscribers2([4, 8, 1, 9, 3, 5, 5, 3])

    def test_case1(self):
        assert self.subs.query(0, 4) == 25