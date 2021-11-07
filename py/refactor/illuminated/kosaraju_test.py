import unittest, os

from problems.illuminated import run_kosaraju

from .utility import get_test_data_path

class Test_Kosaraju(unittest.TestCase):

    def setUp(self):

        data_dir = os.path.join(get_test_data_path(), 'kosaraju')

        cases = {}

        for case in range(1, 7):
            cases[case] = os.path.join(data_dir,  f'problem8.10test{case}.txt')
        
        self.test_cases = cases

        self.expected_output = {
            1 : [3, 3, 3, 0, 0],
            2 : [3, 3, 2, 0, 0],
            3 : [3, 3, 1, 1, 0],
            4 : [7, 1, 0, 0, 0],
            5 : [6, 3, 2, 1, 0],
            6 : [3, 1, 1, 0, 0],
        }

    def test_cases_disk(self):

        for case in self.test_cases.items():

            result = run_kosaraju(case[1])

            assert result == self.expected_output[case[0]]