import unittest

from dcp.problems.hashtable.word_frequencies import word_frequency

class Test_WordFrequency(unittest.TestCase):

    def setUp(self):
        pass

    def test_none(self):

        words = None

        actual = word_frequency(words)
        expected = None

        assert actual == expected

    def test_case1(self):

        words = 'the cat in the hat'

        actual = word_frequency(words)
        expected = {'the': 2, 'cat': 1, 'in': 1, 'hat': 1}

        assert actual == expected

    def test_case2(self):

        words = 'In the tub, the boy fell on his bottom'

        actual = word_frequency(words)
        expected = {'in': 1, 'the': 2, 'tub': 1, 'boy': 1, 'fell': 1, 'on': 1, 'his': 1, 'bottom': 1}

        assert actual == expected

    def test_case3(self):

        words = 'I watched birds sitting in the balcony.'

        actual = word_frequency(words)
        expected = {'i': 1, 'watched': 1, 'birds': 1, 'sitting': 1, 'in': 1, 'the': 1, 'balcony': 1}

        assert actual == expected

    def test_case4(self):

        words = 'Having vowed to embark upon a much more satisfactory academic year, Bob and Mark, the two brothers from the Chapwick borough, ' + \
        'boarded a streetcar in early August, debarked at the Leeds Department Store in Chelsea, and purchased several pounds’ worth of school supplies.'

        actual = word_frequency(words)

        expected = {'having': 1, 'vowed': 1, 'to': 1, 'embark': 1, 'upon': 1, 'a': 2, 'much': 1, 'more': 1, 'satisfactory': 1, \
        'academic': 1, 'year': 1, 'bob': 1, 'and': 2, 'mark': 1, 'the': 3, 'two': 1, 'brothers': 1, 'from': 1, 'chapwick': 1, \
        'borough': 1, 'boarded': 1, 'streetcar': 1, 'in': 2, 'early': 1, 'august': 1, 'debarked': 1, 'at': 1, 'leeds': 1, \
        'department': 1, 'store': 1, 'chelsea': 1, 'purchased': 1, 'several': 1, 'pounds': 1, 'worth': 1, 'of': 1, 'school': 1, 'supplies': 1}

        assert actual == expected