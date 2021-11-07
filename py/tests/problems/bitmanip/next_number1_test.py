import unittest

from problems.bit_manip import next_number1

class Test_NextNumber1(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_case1(self):

        actual = next_number1(83)

        expected = (75, 86)
        
        assert actual == expected

    def test_case2(self):

        actual = next_number1(1)

        expected = (None, 2)
        
        assert actual == expected

    def test_case3(self):

        actual = next_number1(96)

        expected = (80, 192)
        
        assert actual == expected

    def test_case4(self):

        actual = next_number1(64)

        expected = (32, 128)
        
        assert actual == expected

    def test_case5(self):

        actual = next_number1(57)

        expected = (41, 58)
        
        assert actual == expected