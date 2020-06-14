import unittest

from py.problems.arr import product1
class Test_ArrayProduct1(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_case1(self):
        assert product1( [1, 2, 3, 4, 5] ) == [120, 60, 40, 30, 24]

    def test_case2(self):
        assert product1( [3, 2, 1] ) == [2, 3, 6]

from py.problems.arr import product2
class Test_ArrayProduct2(unittest.TestCase):
    
    def setUp(self):
        pass
    
    def test_case1(self):
        assert product2( [1, 2, 3, 4, 5] ) == [120, 60, 40, 30, 24]

    def test_case2(self):
        assert product2( [3, 2, 1] ) == [2, 3, 6]

from py.problems.arr import product3
class Test_ArrayProduct3(unittest.TestCase):

    def setUp(self):
        pass
    
    def test_case1(self):
        assert product3( [1, 2, 3, 4, 5] ) == [120, 60, 40, 30, 24]

    def test_case2(self):
        assert product3( [3, 2, 1] ) == [2, 3, 6]

from py.problems.arr import window1
class Test_SmallestWindow(unittest.TestCase):

    def setUp(self):
        pass
    
    def test_case1(self):
        assert window1( [3, 7, 5, 6, 9]) == (1, 3)
    
    def test_case2(self):
        assert window1( [3, 7, 5, 6, 9, 2, 3, 14, 15, 16, 17, 1.5]) == (1, 11)

from py.problems.arr import max_subarray_sum1
class Test_MaxSubarraySum(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):
        assert max_subarray_sum1( [34, -50, 42, 14, -5, 86]) == 137
    
    def test_case2(self):
        assert max_subarray_sum1( [-5, -1, 8, -9]) == 0

from py.problems.arr import smaller_counts1
class Test_SmallerCounts1(unittest.TestCase):

    def setUp(self):
        pass

    def test_case1(self):
        assert smaller_counts1( [3, 4, 9, 6, 1]) == [1, 1, 2, 1, 0]
    
    def test_case2(self):
        assert smaller_counts1( [2, 5, 4, 7, 8]) == [0, 1, 0, 0, 0]

from py.problems.arr import smallest_difference1
class Test_SmallestDifference1(unittest.TestCase):

    def setUp(self):
        pass

    def test_none(self):

        arr1 = []
        arr2 = None

        actual = smallest_difference1(arr1, arr2)
        expected = None

        assert actual == expected

    def test_case1(self):
        
        arr1 = [1, 3, 15, 11, 2]
        arr2 = [23, 127, 235, 19, 8]

        actual = smallest_difference1(arr1, arr2)
        expected = (11, 8, 3)

        assert actual == expected

    def test_case2(self):
        
        arr1 = [190, 73, 294, 240, 29]
        arr2 = [89, 117, 224, 30, 152]

        actual = smallest_difference1(arr1, arr2)
        expected = (29, 30, 1)

        assert actual == expected

    def test_case3(self):
        
        arr1 = [296, 254, 181, 12, 62]
        arr2 = [15, 4, 255, 110, 237]

        actual = smallest_difference1(arr1, arr2)
        expected = (254, 255, 1)

        assert actual == expected

from py.problems.arr import smallest_difference2
class Test_SmallestDifference2(unittest.TestCase):

    def setUp(self):
        pass

    def test_none(self):

        arr1 = []
        arr2 = None

        actual = smallest_difference2(arr1, arr2)
        expected = None

        assert actual == expected

    def test_case1(self):
        
        arr1 = [1, 3, 15, 11, 2]
        arr2 = [23, 127, 235, 19, 8]

        actual = smallest_difference2(arr1, arr2)
        expected = (11, 8, 3)

        assert actual == expected

    def test_case2(self):
        
        arr1 = [190, 73, 294, 240, 29]
        arr2 = [89, 117, 224, 30, 152]

        actual = smallest_difference2(arr1, arr2)
        expected = (30, 29, 1)

        assert actual == expected

    def test_case3(self):
        
        arr1 = [296, 254, 181, 12, 62]
        arr2 = [15, 4, 255, 110, 237]

        actual = smallest_difference2(arr1, arr2)
        expected = (255, 254, 1)

        assert actual == expected

from py.problems.arr import letters_numbers1
class Test_LettersNumbers1(unittest.TestCase):

    def setUp(self):
        pass

    def test_none(self):

        arr = None
        actual = letters_numbers1(arr)
        expected = -1

        assert actual == expected

    def test_case1(self):

        arr = ['a', 'b', 1, 'c', 'd', 'e', 3, 5, 6, 'g', 'h', 7]
        
        actual = letters_numbers1(arr)
        expected = ['b', 1, 'c', 'd', 'e', 3, 5, 6]

        assert actual == expected

    def test_case2(self):

        arr = ['a', 1, 1, 'a', 'a', 1, 'a', 1, 'a', 'a', 'a', 1]

        actual = letters_numbers1(arr)
        expected = ['a', 1, 1, 'a', 'a', 1, 'a', 1]

        assert actual == expected

    def test_case3(self):

        arr = ['a', 1, 1, 1, 'a', 1, 'a', 1, 'a', 1, 'a', 1, 'a', 1, 1, 1, 'a', 1, 'a', 1, 'a', 'a', 'a', 1]

        actual = letters_numbers1(arr)
        expected = [1, 'a', 1, 'a', 1, 'a', 1, 'a', 1, 'a']

        assert actual == expected

    def test_case4(self):

        arr = ['a', 1, 1, 1, 'a', 1, 1, 1, 'a', 1, 'a', 1, 'a', 1, 1, 1, 'a', 1, 'a', 1, 'a', 'a', 'a', 1]

        actual = letters_numbers1(arr)
        expected = ['a', 1, 1, 1, 'a', 1, 'a', 1, 'a', 1, 1, 1, 'a', 1, 'a', 1]

        assert actual == expected

    def test_case5(self):

        arr = ['a', 'b', 1, 'c', 'd', 'e', 3, 5, 6, 'g', 4, 7, 'a', 'b', 1, 'c', 'd', 'e', 3, 5, 6, 'g', 'h', 7]

        actual = letters_numbers1(arr)
        expected = ['a', 'b', 1, 'c', 'd', 'e', 3, 5, 6, 'g']

        assert actual == expected        

from py.problems.arr import letters_numbers2
class Test_LettersNumbers2(unittest.TestCase):

    def setUp(self):
        pass

    def test_none(self):

        arr = None
        actual = letters_numbers2(arr)
        expected = -1

        assert actual == expected

    def test_case1(self):

        arr = ['a', 'b', 1, 'c', 'd', 'e', 3, 5, 6, 'g', 'h', 7]
        actual = letters_numbers2(arr)
        expected = ['b', 1, 'c', 'd', 'e', 3, 5, 6]

        assert actual == expected

    def test_case2(self):

        arr = ['a', 1, 1, 'a', 'a', 1, 'a', 1, 'a', 'a', 'a', 1]

        actual = letters_numbers2(arr)
        expected = ['a', 1, 1, 'a', 'a', 1, 'a', 1]

        assert actual == expected

    def test_case3(self):

        arr = ['a', 1, 1, 1, 'a', 1, 'a', 1, 'a', 1, 'a', 1, 'a', 1, 1, 1, 'a', 1, 'a', 1, 'a', 'a', 'a', 1]

        actual = letters_numbers2(arr)
        expected = [1, 1, 1, 'a', 1, 'a', 1, 'a', 1, 'a']

        assert actual == expected

    def test_case4(self):

        arr = ['a', 1, 1, 1, 'a', 1, 1, 1, 'a', 1, 'a', 1, 'a', 1, 1, 1, 'a', 1, 'a', 1, 'a', 'a', 'a', 1]

        actual = letters_numbers2(arr)
        expected = ['a', 1, 1, 1, 'a', 1, 'a', 1, 'a', 1, 1, 1, 'a', 1, 'a', 1]

        assert actual == expected

    def test_case5(self):

        arr = ['a', 'b', 1, 'c', 'd', 'e', 3, 5, 6, 'g', 4, 7, 'a', 'b', 1, 'c', 'd', 'e', 3, 5, 6, 'g', 'h', 7]

        actual = letters_numbers2(arr)
        expected = ['a', 'b', 1, 'c', 'd', 'e', 3, 5, 6, 'g']

        assert actual == expected        