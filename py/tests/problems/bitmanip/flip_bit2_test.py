import unittest

from dcp.problems.bit_manip.flip_to_win import flip_bit2

class Test_BitFlip2(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_case1(self):

        actual = flip_bit2(None)

        expected = None
        
        assert actual == expected

    '''
    11011101111
    '''
    def test_case2(self):

        actual = flip_bit2(1775)
        
        expected = 8

        assert actual == expected

    '''
    10000000000
    '''
    def test_case3(self):

        actual = flip_bit2(1024)

        expected = 2

        assert actual == expected

    '''
    111111111
    '''
    def test_case4(self):

         actual = flip_bit2(511)

         expected = 9

         assert actual == expected

    '''
    11010000010011
    '''
    def test_case5(self):
    
        actual = flip_bit2(13331)
            
        expected = 4

        assert actual == expected