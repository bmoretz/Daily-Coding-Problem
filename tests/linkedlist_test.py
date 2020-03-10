import unittest

from problems.linkedlist import Node, SLinkedList
from problems.linkedlist import build_list
from problems.linkedlist import add_numbers1, add_numbers2
from problems.linkedlist import alternate1, alternate2
from problems.linkedlist import intersect1, intersect2
from problems.linkedlist import dedupe1, dedupe2
from problems.linkedlist import klast1, klast2
from problems.linkedlist import delete_middle1

class Test_SingleLinkedList(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        sl = SLinkedList()

        for d in range(0, 10):
            sl.push_back(d)
        
        sl.reverse()

        assert sl.elements() == [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]

class Test_SingleLinkedListReverse1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        sl = SLinkedList()

        for d in range(0, 10):
            sl.push_back(d)
        
        sl.reverse()

        assert sl.elements() == [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]

class Test_SingleLinkedListAdd1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        l1, l2 = SLinkedList(), SLinkedList()

        for x in [9, 9]: l1.push_back(x)
        for x in [5, 2]: l2.push_back(x)

        result = add_numbers1(l1, l2)
        
        assert result.elements() == [4, 2, 1]

class Test_SingleLinkedListAdd2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        l1, l2, result = SLinkedList(), SLinkedList(), SLinkedList()

        for x in [9, 9]: l1.push_back(x)
        for x in [5, 2]: l2.push_back(x)

        result.head = add_numbers2(l1.head, l2.head)
        
        assert result.elements() == [4, 2, 1]

class Test_SingleLinkedListAlt1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        items = SLinkedList()

        for index in range(1, 6):
            items.push_back(index)

        result = alternate1(items)

        assert result.elements() == [1, 3, 2, 5, 4]

class Test_SingleLinkedListAlt2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        items = SLinkedList()

        for index in range(1, 6):
            items.push_back(index)

        result = alternate2(items)

        assert result.elements() == [1, 3, 2, 5, 4]

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

class Test_Dedupe1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        assert dedupe1(None) == None

    def test_case2(self):

        expected = build_list([1])

        actual = dedupe1(build_list([1]))

        assert expected == actual
        
    def test_case3(self):

        expected = build_list([1, 2, 3, 4, 5])

        actual = dedupe1(build_list([1, 2, 3, 4, 3, 5, 2]))
        
        assert expected == actual 

    def test_case4(self):

        expected = build_list([1, 2])

        actual = dedupe1(build_list([1, 2, 2, 2, 2]))

        assert expected == actual 

    def test_case5(self):

        expected = build_list([3, 4])

        actual =  dedupe1(build_list([3, 3, 3, 4]))

        assert expected == actual

class Test_Dedupe2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        assert dedupe2(None) == None

    def test_case2(self):

        expected = build_list([1])

        actual = dedupe2(build_list([1]))

        assert expected == actual
        
    def test_case3(self):

        expected = build_list([1, 2, 3, 4, 5])

        actual = dedupe2(build_list([1, 2, 3, 4, 3, 5, 2]))
        
        assert expected == actual 

    def test_case4(self):

        expected = build_list([1, 2])

        actual = dedupe2(build_list([1, 2, 2, 2, 2]))

        assert expected == actual 

    def test_case5(self):

        expected = build_list([3, 4])

        actual =  dedupe2(build_list([3, 3, 3, 4]))

        assert expected == actual

class Test_KLast1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        assert klast1(None, 0) == None

    def test_case2(self):
        
        values = build_list([1, 2, 3, 4, 5, 6, 7])

        actual = klast1(values, 0)
        expected = 7
        
        assert actual == expected
        
    def test_case3(self):

        values = build_list([1, 2, 3, 4, 5, 6, 7])

        actual = klast1(values, 2)
        expected = 5

        assert actual == expected

    def test_case4(self):

        values = build_list([1, 2, 3, 4, 5, 6, 7])

        actual = klast1(values, 6)
        expected = 1
        
        assert actual == expected

    def test_case5(self):

        values = build_list([1, 2, 3, 4, 5, 6, 7])

        actual = klast1(values, 3)
        expected = 4

        assert expected == actual

class Test_KLast2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        assert klast2(None, 0) == None

    def test_case2(self):
        
        values = build_list([1, 2, 3, 4, 5, 6, 7])

        actual = klast2(values, 0)
        expected = 7
        
        assert actual == expected
        
    def test_case3(self):

        values = build_list([1, 2, 3, 4, 5, 6, 7])

        actual = klast2(values, 2)
        expected = 5

        assert actual == expected

    def test_case4(self):

        values = build_list([1, 2, 3, 4, 5, 6, 7])

        actual = klast2(values, 6)
        expected = 1
        
        assert actual == expected

    def test_case5(self):

        values = build_list([1, 2, 3, 4, 5, 6, 7])

        actual = klast2(values, 3)
        expected = 4

        assert expected == actual

class Test_DeleteMiddle2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        assert delete_middle1(None) == None

    def test_case2(self):
        
        actual, target = build_list(['a', 'b', 'c', 'd', 'e', 'f']), 'c'

        node = actual

        while node.data != target:
            node = node.next

        delete_middle1(node)

        expected = build_list(['a', 'b', 'd', 'e', 'f'])
        
        assert actual == expected
        
    def test_case3(self):
        
        actual, target = build_list(['a', 'b', 'c', 'd', 'e', 'f']), 'd'

        node = actual

        while node.data != target:
            node = node.next

        delete_middle1(node)

        expected = build_list(['a', 'b', 'c', 'e', 'f'])
        
        assert actual == expected

    def test_case3(self):
        
        actual, target = build_list(['a', 'b', 'c', 'd', 'e', 'f']), 'd'

        node = actual

        while node.data != target:
            node = node.next

        delete_middle1(node)

        expected = build_list(['a', 'b', 'c', 'e', 'f'])
        
        assert actual == expected

    def test_case3(self):
        
        actual, target = build_list(['a', 'b', 'c', 'd', 'e', 'f']), 'f'

        node = actual

        while node.data != target:
            node = node.next

        delete_middle1(node)

        expected = build_list(['a', 'b', 'c', 'd', 'e', 'f'])
        
        assert actual == expected