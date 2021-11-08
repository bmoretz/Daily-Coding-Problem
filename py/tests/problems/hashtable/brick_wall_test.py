import unittest

from dcp.problems.hashtable.brick_wall import fewest_cuts1

class Test_FewestCuts(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):

        wall1 = [[3, 5, 1, 1], \
                [2, 3, 3, 2], \
                [5, 5], \
                [4, 4, 2], \
                [1, 3, 3, 3], \
                [1, 1, 6, 1, 1]]
                
        assert fewest_cuts1(wall1) == 2

    def test_case2(self):

        wall2 = [[1,2,2,1],
                [3,1,2],
                [1,3,2],
                [2,4],
                [3,1,2],
                [1,3,1,1]]
                
        assert fewest_cuts1(wall2) == 2