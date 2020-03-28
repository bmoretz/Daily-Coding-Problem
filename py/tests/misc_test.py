import unittest

from random import uniform


from py.problems.misc import Subscribers1
'''Classic Dictionary'''
class Test_Subscribers1(unittest.TestCase):
    
    def setUp(self):
        self.subs = Subscribers1([4, 8, 1, 9, 3, 5, 5, 3])

    def test_case1(self):
        assert self.subs.query(0, 4) == 25

from py.problems.misc import Subscribers2
'''Fenwick Tree'''
class Test_Subscribers2(unittest.TestCase):
    
    def setUp(self):
        self.subs = Subscribers2([4, 8, 1, 9, 3, 5, 5, 3])

    def test_case1(self):
        assert self.subs.query(0, 4) == 25

from py.problems.misc import DisjointSet, friend_groups
'''Disjoint set.'''
class Test_FriendGroups(unittest.TestCase):
    
    def setUp(self):
        self.friends = {
            0: [1, 2],
            1: [0, 5],
            2: [0],
            3: [6],
            4: [],
            5: [1],
            6: [3]
        }

    def test_case1(self):
        assert friend_groups(self.friends) == 3

from py.problems.misc import BloomFilter
class Test_BloomFilter(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        bf, nums = BloomFilter(), []

        for _ in range(100):
            n = int(uniform(0, 1000))
            bf.add(n)
            nums += [n]

        for n in nums:
            assert bf.check(n) == True