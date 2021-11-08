import unittest

from dcp.problems.linkedlist.single import SLinkedList
from dcp.problems.linkedlist.node import build_ref_list
from dcp.problems.linkedlist.intersection import intersect1, intersect2, intersect5, intersect6
from dcp.problems.linkedlist.intersection import tail

class Test_SingleLinkedListIntersect1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        list1, list2 = SLinkedList(), SLinkedList()

        for x in [3, 7, 8, 10]: list1.push_back(x)
        for x in [99, 1, 8, 10]: list2.push_back(x)

        assert intersect1(list1, list2) == 8

class Test_SingleLinkedListIntersect2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        list1, list2 = SLinkedList(), SLinkedList()

        for x in [3, 7, 8, 10]: list1.push_back(x)
        for x in [99, 1, 8, 10]: list2.push_back(x)
        
        result = intersect2(list1, list2)

        assert result.data == 8

class Test_Intersect5(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        h1, h2 = build_ref_list([1, 2, 3, 4]), build_ref_list([5, 6])

        assert intersect5(h1, h2) == None

    def test_case2(self):
        
        h1, h2 = build_ref_list([1, 2, 3, 4]), build_ref_list([5, 6])

        tail(h2).next = h1

        assert intersect5(h1, h2) == h1
        
    def test_case3(self):
        
        h1, h2 = build_ref_list([5, 6]), build_ref_list([1, 2, 3, 4])

        tail(h1).next = h2

        actual = intersect5(h1, h2)
        
        expected = h2

        assert actual == expected

    def test_case4(self):
        h1, h2 = build_ref_list([5, 6]), build_ref_list([1, 2, 3, 4])

        tail(h1).next = h2

        actual = intersect5(h1, h2)
        
        expected = h2

        assert actual == expected

    def test_case5(self):
        h1, h2 = build_ref_list([1, 2, 3, 4]), build_ref_list([1, 2, 3, 4])

        actual = intersect5(h1, h2)
        
        expected = None

        assert actual == expected

    def test_case6(self):
        h1, h2 = build_ref_list([1, 2, 3, 4]), build_ref_list([1, 2, 3, 4])

        tail(h1).next = h2

        actual = intersect5(h1, h2)
        
        expected = h2

        assert actual == expected

class Test_Intersect6(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        h1, h2 = build_ref_list([1, 2, 3, 4]), build_ref_list([5, 6])

        assert intersect6(h1, h2) == None

    def test_case2(self):
        
        h1, h2 = build_ref_list([1, 2, 3, 4]), build_ref_list([5, 6])

        tail(h2).next = h1

        actual = intersect6(h1, h2)
        
        expected = h1

        assert actual == expected
        
    def test_case3(self):
        
        h1, h2 = build_ref_list([5, 6]), build_ref_list([1, 2, 3, 4])

        tail(h1).next = h2

        actual = intersect6(h1, h2)
        
        expected = h2

        assert actual == expected

    def test_case4(self):
        h1, h2 = build_ref_list([5, 6]), build_ref_list([1, 2, 3, 4])

        tail(h1).next = h2

        actual = intersect6(h1, h2)
        
        expected = h2

        assert actual == expected

    def test_case5(self):
        h1, h2 = build_ref_list([1, 2, 3, 4]), build_ref_list([1, 2, 3, 4])

        actual = intersect6(h1, h2)
        
        expected = None

        assert actual == expected

    def test_case6(self):
        h1, h2 = build_ref_list([1, 2, 3, 4]), build_ref_list([1, 2, 3, 4])

        tail(h1).next = h2

        actual = intersect6(h1, h2)
        
        expected = h2

        assert actual == expected