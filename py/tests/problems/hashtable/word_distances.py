import unittest

from dcp.problems.hashtable.word_distance import WordDistances

class Test_WordDistances(unittest.TestCase):

    def setUp(self):
        pass

    def test_none(self):

        words = None

        wd = WordDistances(words)

        actual = wd.get_distance(None, None)
        expected = None

        assert actual == expected

    def test_case1(self):

        words = ['cat', 'dog', 'puppie', 'rat', 'song', 'guess', 'math', 'prime', 'song', 'dust', 'rust', 'cat']

        wd = WordDistances(words)

        actual = wd.get_distance('rust', 'dog')
        expected = 9

        assert actual == expected
        
    def test_case2(self):

        words = ['cat', 'dog', 'puppie', 'rat', 'song', 'guess', 'math', 'prime', 'song', 'dust', 'rust', 'cat']

        wd = WordDistances(words)

        actual = wd.get_distance('rust', 'cat')
        expected = 1

        assert actual == expected

    def test_case3(self):

        words = ['cat', 'dog', 'puppie', 'rat', 'song', 'guess', 'math', 'prime', 'song', 'dust', 'rust', 'cat']

        wd = WordDistances(words)

        actual = wd.get_distance('dog', 'math')
        expected = 5

        assert actual == expected

    def test_case4(self):

        words = ['cat', 'dog', 'puppie', 'rat', 'song', 'guess', 'math', 'prime', 'song', 'dust', 'rust', 'cat']

        wd = WordDistances(words)

        actual = wd.get_distance('cat', 'prime')
        expected = 4

        assert actual == expected

    def test_case5(self):

        words = ['cat', 'dog', 'puppie', 'rat', 'song', 'guess', 'math', 'prime', 'song', 'dust', 'rust', 'cat']

        wd = WordDistances(words)

        actual = wd.get_distance('puppie', 'song')
        expected = 2

        assert actual == expected