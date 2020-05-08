import unittest

from py.problems.hashtable import two_sum1
class Test_TwoSum1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        arr, k = [10, 15, 3, 7], 17

        assert two_sum1(arr, k) == True

from py.problems.hashtable import LRUCache, Node, LinkedList
class Test_LRUCache(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):

        cache = LRUCache(5)

        for index in range(10):
            cache.set(index, index**2)

        assert list( cache.dict.keys() ) == [5, 6, 7, 8, 9]

from py.problems.hashtable import fewest_cuts1
class Test_FewestCuts(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):

        wall1 = [[3, 5, 1, 1], \
                [2, 3, 3, 2], \
                [5, 5], \
                [4, 4, 2], \
                [1, 3, 3, 3], \
                [1, 1, 6, 1, 1]]
                
        assert fewest_cuts1(wall1) == 2

    def test_case2(self):

        wall2 = [[1,2,2,1],
                [3,1,2],
                [1,3,2],
                [2,4],
                [3,1,2],
                [1,3,1,1]]
                
        assert fewest_cuts1(wall2) == 2

from py.problems.hashtable import SparseArray
class Test_SparseArray(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):

        arr, n = [0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1], 100

        sa = SparseArray(arr, n)

        non_zero = [5, 13, 19, 28]

        for index in range(len(arr)):

            if index in non_zero:
                assert sa.get(index) != 0
            else:
                assert sa.get(index) == 0

from py.problems.hashtable import SparseMatrix
class Test_SparseMatrix(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):

        mat = [[0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1], \
                [0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1], \
                [0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1], \
                [0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1], \
                [0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1]]
                
        n, m = 100, 100
        sm = SparseMatrix(mat, n, m)

        non_zero = [[5, 13, 19, 28], \
                    [5, 13, 19, 28], \
                    [5, 13, 19, 28], \
                    [5, 13, 19, 28], \
                    [5, 13, 19, 28]]

        for n, row in enumerate(mat):
            for m, _ in enumerate(row):

                if m in non_zero[n]:
                    assert sm.get(n, m) != 0
                else:
                    assert sm.get(n, m) == 0

from py.problems.hashtable import word_frequency
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