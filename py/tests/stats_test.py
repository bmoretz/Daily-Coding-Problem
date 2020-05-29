import unittest

from py.problems.stats import distribution_fitting

class Test_DistributionFitting1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_norm(self):

        investments = [
            11624, 9388, 9471, 8927,
            10865, 7698, 11744, 9238,
            10319, 9750, 11462, 7939
        ]
        
        actual = distribution_fitting('norm', investments)

        expected = (200, 230)

        assert expected[0] < actual[0] < expected[1]

    def test_cauchy(self):

        investments = [
            11624, 9388, 9471, 8927,
            10865, 7698, 11744, 9238,
            10319, 9750, 11462, 7939
        ]
        
        actual = distribution_fitting('cauchy', investments)

        expected = (200, 230)

        assert expected[0] < actual[0] < expected[1]

    def test_expon(self):

        investments = [
            11624, 9388, 9471, 8927,
            10865, 7698, 11744, 9238,
            10319, 9750, 11462, 7939
        ]
        
        actual = distribution_fitting('expon', investments)

        expected = (200, 230)

        assert expected[0] < actual[0] < expected[1]