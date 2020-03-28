import unittest

from py.problems.simulation import estimate_pi
class Test_SimulatePi(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):       
        
        assert round( estimate_pi(10e5), 2) == 3.14