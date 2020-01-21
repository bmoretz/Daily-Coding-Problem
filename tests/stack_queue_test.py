import unittest

from problems.stack_queue import Stack, MaxStack
from problems.stack_queue import bracket_balanced1, bracket_balanced2
from problems.stack_queue import max_subarray1, max_subarray2, max_subarray3

class Test_BaseStack(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        s = Stack()

        for i in range(0, 5):
            s.push(i)

        assert s.length() == 5

class Test_MaxStack(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        s = MaxStack()

        for i in [2, 3, 5, 1, 4]:
            s.push(i)

        assert s.max() == 5


class Test_BracketBalanced1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        assert bracket_balanced1("([])[]({})") == True

    def test_case2(self):
        assert bracket_balanced1("}") == False

    def test_case3(self):
        assert bracket_balanced1("([)]") == False

    def test_case4(self):
        assert bracket_balanced1("((()") == False

class Test_BracketBalanced2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        assert bracket_balanced2("([])[]({})") == True

    def test_case2(self):
        assert bracket_balanced2("}") == False

    def test_case3(self):
        assert bracket_balanced2("([)]") == False

    def test_case4(self):
        assert bracket_balanced2("((()") == False

class Test_MaxSub1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        arr, k = [10, 5, 2, 7, 8, 7], 3

        assert max_subarray1(arr, k) == [10, 7, 8, 8]
    
    def test_case2(self):
        arr, k = [1, 2, 3, 4, 5, 6, 7, 8, 9], 3

        assert max_subarray1(arr, k) == [3, 4, 5, 6, 7, 8, 9]

class Test_MaxSub2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        arr, k = [10, 5, 2, 7, 8, 7], 3

        assert max_subarray2(arr, k) == [10, 7, 8, 8]

    def test_case2(self):
        arr, k = [1, 2, 3, 4, 5, 6, 7, 8, 9], 3

        assert max_subarray2(arr, k) == [3, 4, 5, 6, 7, 8, 9]

class Test_MaxSub3(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        arr, k = [10, 5, 2, 7, 8, 7], 3

        assert max_subarray3(arr, k) == [10, 7, 8, 8]

    def test_case2(self):
        arr, k = [1, 2, 3, 4, 5, 6, 7, 8, 9], 3

        assert max_subarray3(arr, k) == [3, 4, 5, 6, 7, 8, 9]
 