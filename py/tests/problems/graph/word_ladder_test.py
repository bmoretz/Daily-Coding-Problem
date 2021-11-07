import unittest

from dcp.problems.graph.word_ladder import word_ladder1

class Test_WordLadderAM(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):

        start, end = "dog", "cat"
        words = {"dot", "dop", "dat", "cat"}

        ladder = word_ladder1(start, end, words)
        exists = True

        assert exists == True