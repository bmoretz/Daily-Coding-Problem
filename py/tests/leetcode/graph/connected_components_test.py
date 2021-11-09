import unittest

from dcp.leetcode.graph.connected_components import countComponents1, countComponents2, countComponents3, countComponents4

class Test_ConnectedComponents_I(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        n, edges = 5, [[0,1],[1,2],[3,4]]

        actual = countComponents1(n, edges)
        expected = 2

        assert actual == expected

    def test_case2(self):
        
        n, edges = 5, [[0,1],[1,2],[2,3],[3,4]]

        actual = countComponents1(n, edges)
        expected = 1

        assert actual == expected

    def test_case3(self):

        n, edges = 4, [[0,1],[2,3],[1,2]]

        actual = countComponents1(n, edges)
        expected = 1

        assert actual == expected

    def test_case4(self):

        n, edges = 3, [[1,0],[2,0]]

        actual = countComponents1(n, edges)
        expected = 1

        assert actual == expected

    def test_case5(self):

        n, edges = 7, [[0,1], [1,2], [1,3], [4,5], [4,6], [1,5]]

        actual = countComponents1(n, edges)
        expected = 1

        assert actual == expected

    def test_case6(self):

        n, edges = 8, [[1,0],[2,6],[1,7],[5,1],[6,4],[7,0],[0,5]]

        actual = countComponents2(n, edges)
        expected = 3

        assert actual == expected        
        
class Test_ConnectedComponents_II(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        n, edges = 5, [[0,1],[1,2],[3,4]]

        actual = countComponents2(n, edges)
        expected = 2

        assert actual == expected

    def test_case2(self):
        
        n, edges = 5, [[0,1],[1,2],[2,3],[3,4]]

        actual = countComponents2(n, edges)
        expected = 1

        assert actual == expected

    def test_case3(self):

        n, edges = 4, [[0,1],[2,3],[1,2]]

        actual = countComponents2(n, edges)
        expected = 1

        assert actual == expected

    def test_case4(self):

        n, edges = 3, [[1,0],[2,0]]

        actual = countComponents2(n, edges)
        expected = 1

        assert actual == expected

    def test_case5(self):

        n, edges = 7, [[0,1], [1,2], [1,3], [4,5], [4,6], [1,5]]

        actual = countComponents2(n, edges)
        expected = 1

        assert actual == expected

    def test_case6(self):

        n, edges = 8, [[1,0],[2,6],[1,7],[5,1],[6,4],[7,0],[0,5]]

        actual = countComponents2(n, edges)
        expected = 3

        assert actual == expected

class Test_ConnectedComponents_III(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        n, edges = 5, [[0,1],[1,2],[3,4]]

        actual = countComponents3(n, edges)
        expected = 2

        assert actual == expected

    def test_case2(self):
        
        n, edges = 5, [[0,1],[1,2],[2,3],[3,4]]

        actual = countComponents3(n, edges)
        expected = 1

        assert actual == expected

    def test_case3(self):

        n, edges = 4, [[0,1],[2,3],[1,2]]

        actual = countComponents3(n, edges)
        expected = 1

        assert actual == expected

    def test_case4(self):

        n, edges = 3, [[1,0],[2,0]]

        actual = countComponents3(n, edges)
        expected = 1

        assert actual == expected

    def test_case5(self):

        n, edges = 7, [[0,1], [1,2], [1,3], [4,5], [4,6], [1,5]]

        actual = countComponents3(n, edges)
        expected = 1

        assert actual == expected

    def test_case6(self):

        n, edges = 8, [[1,0],[2,6],[1,7],[5,1],[6,4],[7,0],[0,5]]

        actual = countComponents3(n, edges)
        expected = 3

        assert actual == expected

class Test_ConnectedComponents_IIII(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        n, edges = 5, [[0,1],[1,2],[3,4]]

        actual = countComponents4(n, edges)
        expected = 2

        assert actual == expected

    def test_case2(self):
        
        n, edges = 5, [[0,1],[1,2],[2,3],[3,4]]

        actual = countComponents4(n, edges)
        expected = 1

        assert actual == expected

    def test_case3(self):

        n, edges = 4, [[0,1],[2,3],[1,2]]

        actual = countComponents4(n, edges)
        expected = 1

        assert actual == expected

    def test_case4(self):

        n, edges = 3, [[1,0],[2,0]]

        actual = countComponents4(n, edges)
        expected = 1

        assert actual == expected

    def test_case5(self):

        n, edges = 7, [[0,1], [1,2], [1,3], [4,5], [4,6], [1,5]]

        actual = countComponents4(n, edges)
        expected = 1

        assert actual == expected

    def test_case6(self):

        n, edges = 8, [[1,0],[2,6],[1,7],[5,1],[6,4],[7,0],[0,5]]

        actual = countComponents4(n, edges)
        expected = 3

        assert actual == expected