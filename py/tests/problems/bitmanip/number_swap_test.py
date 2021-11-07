import unittest

from dcp.problems.bit_manip.number_swapper import number_swap

class Test_NumberSwap1(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_case1(self):

        a, b = 10, 15

        actual_a, actual_b = number_swap(a, b)

        expected_a, expected_b = b, a

        assert actual_a == expected_a
        assert actual_b == expected_b

    def test_case2(self):

        a, b = 9, 414

        actual_a, actual_b = number_swap(a, b)

        expected_a, expected_b = b, a

        assert actual_a == expected_a
        assert actual_b == expected_b

    def test_case3(self):

        a, b = -934, 14

        actual_a, actual_b = number_swap(a, b)

        expected_a, expected_b = b, a

        assert actual_a == expected_a
        assert actual_b == expected_b

    def test_case4(self):

        a, b = -934, -11314

        actual_a, actual_b = number_swap(a, b)

        expected_a, expected_b = b, a

        assert actual_a == expected_a
        assert actual_b == expected_b

    def test_case5(self):

        a, b = 9232134124, 53253253211314

        actual_a, actual_b = number_swap(a, b)

        expected_a, expected_b = b, a

        assert actual_a == expected_a
        assert actual_b == expected_b