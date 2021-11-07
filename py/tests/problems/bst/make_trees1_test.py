import unittest

from problems.bst import make_trees1

class Test_MakeTrees1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case3(self):       
        
        trees = make_trees1(N = 3)

        assert trees[0] == [1, 2, 3]
        assert trees[1] == [1, 3, 2]
        assert trees[2] == [2, 1, 3]
        assert trees[3] == [3, 1, 2]
        assert trees[4] == [3, 2, 1]