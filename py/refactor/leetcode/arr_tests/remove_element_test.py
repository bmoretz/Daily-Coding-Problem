import unittest

from leetcode.arr import remove_element

class Test_RemoveElement(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        data = [3,2,2,3]
        new_len = remove_element.removeElement(data, 3)

        actual = data[0:new_len]
        expected = [2, 2]

        assert actual == expected

    def test_case2(self):
        
        data = [0,1,2,2,3,0,4,2]
        new_len = remove_element.removeElement(data, 2)

        actual = data[0:new_len]
        expected = [0,1,3,0,4]

        assert actual == expected