import unittest

from dcp.problems.linkedlist.single import build_list
from dcp.problems.linkedlist.dedupe import dedupe1, dedupe2

class Test_Dedupe1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        assert dedupe1(None) == None

    def test_case2(self):

        expected = build_list([1])

        actual = dedupe1(build_list([1]))

        assert expected == actual
        
    def test_case3(self):

        expected = build_list([1, 2, 3, 4, 5])

        actual = dedupe1(build_list([1, 2, 3, 4, 3, 5, 2]))
        
        assert expected == actual 

    def test_case4(self):

        expected = build_list([1, 2])

        actual = dedupe1(build_list([1, 2, 2, 2, 2]))

        assert expected == actual 

    def test_case5(self):

        expected = build_list([3, 4])

        actual =  dedupe1(build_list([3, 3, 3, 4]))

        assert expected == actual


class Test_Dedupe2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        assert dedupe2(None) == None

    def test_case2(self):

        expected = build_list([1])

        actual = dedupe2(build_list([1]))

        assert expected == actual
        
    def test_case3(self):

        expected = build_list([1, 2, 3, 4, 5])

        actual = dedupe2(build_list([1, 2, 3, 4, 3, 5, 2]))
        
        assert expected == actual 

    def test_case4(self):

        expected = build_list([1, 2])

        actual = dedupe2(build_list([1, 2, 2, 2, 2]))

        assert expected == actual 

    def test_case5(self):

        expected = build_list([3, 4])

        actual =  dedupe2(build_list([3, 3, 3, 4]))

        assert expected == actual
