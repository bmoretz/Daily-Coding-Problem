import unittest

from random import uniform

from py.problems.misc import Subscribers1
'''Classic Dictionary'''
class Test_Subscribers1(unittest.TestCase):
    
    def setUp(self):
        self.subs = Subscribers1([4, 8, 1, 9, 3, 5, 5, 3])

    def test_case1(self):
        assert self.subs.query(0, 4) == 25

from py.problems.misc import Subscribers2
'''Fenwick Tree'''
class Test_Subscribers2(unittest.TestCase):
    
    def setUp(self):
        self.subs = Subscribers2([4, 8, 1, 9, 3, 5, 5, 3])

    def test_case1(self):
        assert self.subs.query(0, 4) == 25

from py.problems.misc import DisjointSet, friend_groups
'''Disjoint set.'''
class Test_FriendGroups(unittest.TestCase):
    
    def setUp(self):
        self.friends = {
            0: [1, 2],
            1: [0, 5],
            2: [0],
            3: [6],
            4: [],
            5: [1],
            6: [3]
        }

    def test_case1(self):
        assert friend_groups(self.friends) == 3

from py.problems.misc import BloomFilter
class Test_BloomFilter(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        bf, nums = BloomFilter(), []

        for _ in range(100):
            n = int(uniform(0, 1000))
            bf.add(n)
            nums += [n]

        for n in nums:
            assert bf.check(n) == True

from py.problems.misc import make_board
from py.problems.misc import check_win
class Test_TicTacToe(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_none(self):

        board = None

        actual = check_win(board)
        expected = None

        assert actual == expected

    def test_diag1(self):

        board = make_board()
        board[0] = ['O', 'X', 'X']
        board[1] = ['X', 'O', 'X']
        board[2] = ['O', 'X', 'O']

        actual = check_win(board)
        expected = True

        assert actual == expected

    def test_diag2(self):

        board = make_board()
        board[0] = ['X', 'X', 'O']
        board[1] = ['X', 'O', 'X']
        board[2] = ['O', 'X', 'O']

        actual = check_win(board)
        expected = True

        assert actual == expected

    def test_row1(self):

        board = make_board()
        board[0] = ['X', 'X', 'O']
        board[1] = ['X', 'X', 'X']
        board[2] = ['O', 'X', 'O']

        actual = check_win(board)
        expected = True

        assert actual == expected

    def test_row2(self):

        board = make_board()
        board[0] = ['X', 'X', 'O']
        board[1] = ['X', 'O', 'X']
        board[2] = ['O', 'O', 'O']

        actual = check_win(board)
        expected = True

        assert actual == expected

    def test_col1(self):

        board = make_board()
        board[0] = ['X', 'X', 'O']
        board[1] = ['X', 'O', 'X']
        board[2] = ['X', 'O', 'O']

        actual = check_win(board)
        expected = True

        assert actual == expected

    def test_col2(self):

        board = make_board()
        board[0] = ['X', 'X', 'O']
        board[1] = ['O', 'O', 'O']
        board[2] = ['X', 'O', 'O']

        actual = check_win(board)
        expected = True

        assert actual == expected

    def test_none(self):

        board = make_board()
        board[0] = ['X', 'X', 'O']
        board[1] = ['O', 'X', 'X']
        board[2] = ['X', 'O', 'O']

        actual = check_win(board)
        expected = False

        assert actual == expected

from py.problems.misc import MasterMind
class Test_MasterMind(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        mm = MasterMind(1234)

        guess = mm.to_guess([1, 2, 2, 4])

        actual = mm.guess(guess)
        expected = (0, 2)

        assert actual == expected

    def test_case2(self):

        mm = MasterMind(123)

        guess = mm.to_guess([1, 2, 2, 4])

        actual = mm.guess(guess)
        expected = (2, 0)

        assert actual == expected

    def test_case3(self):

        mm = MasterMind(511)

        guess = mm.to_guess([1, 2, 2, 4])

        actual = mm.guess(guess)
        expected = (1, 2)

        assert actual == expected

    def test_case4(self):

        mm = MasterMind(541)

        guess = mm.to_guess([1, 2, 2, 4])

        actual = mm.guess(guess)
        expected = (1, 1)

        assert actual == expected

    def test_case5(self):

        mm = MasterMind(123)

        guess = mm.to_guess([1, 2, 2, 4])

        actual = mm.guess(guess)
        expected = (2, 0)

        assert actual == expected

from py.problems.misc import pattern_match1
class Test_PatternMatch1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_none(self):

        value, pattern = None, 'ababa'

        actual = pattern_match1(pattern, value) 
        expected = None

        return actual == expected

    def test_case1(self):

        value, pattern = 'catcatgocatgo', 'aabab'

        actual = pattern_match1(pattern, value) 
        expected = True

        return actual == expected

    def test_case2(self):

        value, pattern = 'catcatgocatgo', 'aababb'

        actual = pattern_match1(pattern, value) 
        expected = False

        return actual == expected

    def test_case3(self):

        value, pattern = 'catcatgocatgocat', 'aababcat'

        actual = pattern_match1(pattern, value) 
        expected = True

        return actual == expected

    def test_case4(self):

        value, pattern = 'testjes', 'ab'

        actual = pattern_match1(pattern, value) 
        expected = True

        return actual == expected

    def test_case5(self):

        value, pattern = 'catcatgocatcatgocatcat', 'aabaabaa'

        actual = pattern_match1(pattern, value) 
        expected = True

        return actual == expected