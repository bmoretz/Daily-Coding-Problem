import unittest

from dcp.problems.dynamic.n_encodings import num_encodings1

class Test_NumEncodings1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        assert num_encodings1('111') == 3

from dcp.problems.dynamic.n_encodings import num_encodings2
class Test_NumEncodings2(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):
        actual, expected = num_encodings2('111'), 1

        assert actual == expected