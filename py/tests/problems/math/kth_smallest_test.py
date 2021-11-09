import unittest

from dcp.problems.math.kth_multiple import kth_smallest1, kth_smallest2

class Test_KthSmallest1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_none(self):

        actual = kth_smallest1(None)
        expected = None

        assert actual == expected

    def test_case1(self):

        actual = kth_smallest1(1)
        expected = 1

        assert actual == expected

    def test_case2(self):

        actual = kth_smallest1(5)
        expected = 9

        assert actual == expected

    def test_case3(self):

        actual = kth_smallest1(20)
        expected = 175

        assert actual == expected

    def test_case4(self):

        actual = kth_smallest1(74)
        expected = 10125

        assert actual == expected

    def test_case5(self):

        actual = kth_smallest1(48)
        expected = 2187

        assert actual == expected

class Test_KthSmallest2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_none(self):

        actual = kth_smallest2(None)
        expected = None

        assert actual == expected

    def test_case1(self):

        actual = kth_smallest2(1)
        expected = 1

        assert actual == expected

    def test_case2(self):

        actual = kth_smallest2(5)
        expected = 9

        assert actual == expected

    def test_case3(self):

        actual = kth_smallest2(20)
        expected = 175

        assert actual == expected

    def test_case4(self):

        actual = kth_smallest2(74)
        expected = 10125

        assert actual == expected

    def test_case5(self):

        actual = kth_smallest2(48)
        expected = 2187

        assert actual == expected