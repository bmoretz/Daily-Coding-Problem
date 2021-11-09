import unittest

from dcp.leetcode.disjoint_set.quick_find import UnionFind

class Test_QuickFind(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):

        uf = UnionFind(10)

        # 1-2-5-6-7    ||    3-8-9-4

        uf.union(1, 2)
        uf.union(2, 5)
        uf.union(5, 6)
        uf.union(6, 7)

        uf.union(3, 8)
        uf.union(8, 9)


        assert uf.connected(1, 5) == True
        assert uf.connected(5, 7) == True
        assert uf.connected(4, 9) == False

        uf.union(9, 4)

        assert uf.connected(4, 9) == True

    def test_case2(self):

        uf = UnionFind(8)

        # 0-1-2 || 3 || 4-5-6-7
        
        uf.union(0, 1)
        uf.union(1, 2)

        uf.union(4, 5)
        uf.union(5, 6)
        uf.union(6, 7)

        assert uf.connected(1, 5) == False
        assert uf.connected(0, 2) == True

        assert uf.connected(3, 2) == False
        assert uf.connected(3, 4) == False

        uf.union(3, 4)

        assert uf.connected(3, 7) == True        