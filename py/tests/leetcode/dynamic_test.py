import unittest

from py.leetcode.dynamic import house_robber

class Test_HouseRobber(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):

        nums = [1,2,3,1]

        actual = house_robber.rob(nums)
        expected = 4

        assert actual == expected

    def test_case1(self):

        nums = [2,1,1,2]

        actual = house_robber.rob(nums)
        expected = 4

        assert actual == expected        