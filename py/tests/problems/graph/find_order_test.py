import unittest

from dcp.problems.graph.find_order import find_order1

class Test_TopologicalSort1(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):

        courses = {
            'CSC300' : ['CSC100', 'CSC200'],
            'CSC200' : ['CSC100'],
            'CSC100' : []
        }        

        assert find_order1(courses) == ['CSC100', 'CSC200', 'CSC300']