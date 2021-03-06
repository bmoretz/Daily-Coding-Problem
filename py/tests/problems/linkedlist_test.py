import unittest

from py.problems.linkedlist import Node, SLinkedList
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

from py.problems.linkedlist import add_numbers1
class Test_SingleLinkedListAdd1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        l1, l2 = SLinkedList(), SLinkedList()

        for x in [9, 9]: l1.push_back(x)
        for x in [5, 2]: l2.push_back(x)

        result = add_numbers1(l1, l2)
        
        assert result.elements() == [4, 2, 1]

from py.problems.linkedlist import add_numbers2
class Test_SingleLinkedListAdd2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        l1, l2, result = SLinkedList(), SLinkedList(), SLinkedList()

        for x in [9, 9]: l1.push_back(x)
        for x in [5, 2]: l2.push_back(x)

        result.head = add_numbers2(l1.head, l2.head)
        
        assert result.elements() == [4, 2, 1]

from py.problems.linkedlist import alternate1
class Test_SingleLinkedListAlt1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        items = SLinkedList()

        for index in range(1, 6):
            items.push_back(index)

        result = alternate1(items)

        assert result.elements() == [1, 3, 2, 5, 4]

from py.problems.linkedlist import alternate2
class Test_SingleLinkedListAlt2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        items = SLinkedList()

        for index in range(1, 6):
            items.push_back(index)

        result = alternate2(items)

        assert result.elements() == [1, 3, 2, 5, 4]

from py.problems.linkedlist import intersect1
class Test_SingleLinkedListIntersect1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        list1, list2 = SLinkedList(), SLinkedList()

        for x in [3, 7, 8, 10]: list1.push_back(x)
        for x in [99, 1, 8, 10]: list2.push_back(x)

        assert intersect1(list1, list2) == 8

from py.problems.linkedlist import intersect2
class Test_SingleLinkedListIntersect2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        list1, list2 = SLinkedList(), SLinkedList()

        for x in [3, 7, 8, 10]: list1.push_back(x)
        for x in [99, 1, 8, 10]: list2.push_back(x)
        
        result = intersect2(list1, list2)

        assert result.data == 8

from py.problems.linkedlist import build_list, tail, build_ref_list
from py.problems.linkedlist import dedupe1
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

from py.problems.linkedlist import dedupe2
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

from py.problems.linkedlist import klast1
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

from py.problems.linkedlist import klast2
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

from py.problems.linkedlist import delete_middle1
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

    def test_case4(self):
        
        actual, target = build_list(['a', 'b', 'c', 'd', 'e', 'f']), 'd'

        node = actual

        while node.data != target:
            node = node.next

        delete_middle1(node)

        expected = build_list(['a', 'b', 'c', 'e', 'f'])
        
        assert actual == expected

    def test_case5(self):
        
        actual, target = build_list(['a', 'b', 'c', 'd', 'e', 'f']), 'f'

        node = actual

        while node.data != target:
            node = node.next

        delete_middle1(node)

        expected = build_list(['a', 'b', 'c', 'd', 'e', 'f'])
        
        assert actual == expected

from py.problems.linkedlist import partition1
class Test_Partition1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        assert partition1(None, 0) == None

    def test_case2(self):
        
        head, partition = build_list([3, 5, 8, 5, 10, 2, 1]), 3

        actual = partition1(head, partition)

        expected = build_list([2, 1, 3, 5, 8, 5, 10])
        
        assert actual == expected
        
    def test_case3(self):
        
        head, partition = build_list([3, 5, 8, 5, 10, 2, 1]), 5

        actual = partition1(head, partition)

        expected = build_list([3, 2, 1, 5, 8, 5, 10])
        
        assert actual == expected

    def test_case4(self):
        
        head, partition = build_list([3, 5, 8, 5, 10, 2, 1]), 10

        actual = partition1(head, partition)

        expected = build_list([3, 5, 8, 5, 2, 1, 10])
        
        assert actual == expected

    def test_case5(self):
        
        head, partition = build_list([3, 5, 8, 5, 10, 2, 1]), 1

        actual = partition1(head, partition)

        expected = build_list([3, 5, 8, 5, 10, 2, 1])
        
        assert actual == expected

from py.problems.linkedlist import rev_sum1
class Test_ReverseSum1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        assert rev_sum1(None, None) == None

    def test_case2(self):
        
        n1, n2 = build_list([7, 1, 6]), build_list([5, 9, 3])

        actual = rev_sum1(n1, n2)

        expected = build_list([1, 0, 1, 2])
        
        assert actual == expected
        
    def test_case3(self):
        
        n1, n2 = build_list([7, 1, 6]), build_list([5, 9, 2])

        actual = rev_sum1(n1, n2)

        expected = build_list([9, 1 , 2])
        
        assert actual == expected

    def test_case4(self):
        
        n1, n2 = build_list([1]), build_list([1])

        actual = rev_sum1(n1, n2)

        expected = build_list([2])
        
        assert actual == expected

    def test_case5(self):
        
        n1, n2 = build_list([0, 0, 0, 0]), build_list([9, 9, 9, 9])

        actual = rev_sum1(n1, n2)

        expected = build_list([9, 9, 9, 9])
        
        assert actual == expected

    def test_case6(self):
        
        n1, n2 = build_list([6]), build_list([5, 9, 3])

        actual = rev_sum1(n1, n2)

        expected = build_list([4, 0, 1])
        
        assert actual == expected

from py.problems.linkedlist import fwd_sum1
class Test_FwdSum1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        assert rev_sum1(None, None) == None

    def test_case2(self):
        
        n1, n2 = build_list([6, 1, 7]), build_list([2, 9, 5])

        actual = fwd_sum1(n1, n2)

        expected = build_list([9, 1, 2])
        
        assert actual == expected
        
    def test_case3(self):
        
        n1, n2 = build_list([6, 1, 7]), build_list([3, 9, 5])

        actual = fwd_sum1(n1, n2)

        expected = build_list([1, 0, 1, 2])
        
        assert actual == expected

    def test_case4(self):
        
        n1, n2 = build_list([1]), build_list([1])

        actual = fwd_sum1(n1, n2)

        expected = build_list([2])
        
        assert actual == expected

    def test_case5(self):
        
        n1, n2 = build_list([0, 0, 0, 0]), build_list([9, 9, 9, 9])

        actual = fwd_sum1(n1, n2)

        expected = build_list([9, 9, 9, 9])
        
        assert actual == expected

    def test_case6(self):
        
        n1, n2 = build_list([6]), build_list([3, 9, 5])

        actual = fwd_sum1(n1, n2)

        expected = build_list([4, 0, 1])
        
        assert actual == expected

from py.problems.linkedlist import is_palindrome1
class Test_IsPalindrome1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        assert is_palindrome1(None) == None

    def test_case2(self):
        
        data = build_list(['a', 'b', 'c', 'b', 'a'])

        assert is_palindrome1(data) == True
        
    def test_case3(self):
        
        data = build_list(['a', 'b', 'b', 'a'])

        assert is_palindrome1(data) == True

    def test_case4(self):
        
        data = build_list(['a', 'b', 'c', 'a', 'a'])

        assert is_palindrome1(data) == False

    def test_case5(self):
        
        data = build_list(['a', 'a', 'c', 'b', 'a'])

        assert is_palindrome1(data) == False

    def test_case6(self):
        
        data = build_list(['b', 'b', 'c', 'b', 'a'])

        assert is_palindrome1(data) == False

from py.problems.linkedlist import intersect5
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

from py.problems.linkedlist import intersect6
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

from py.problems.linkedlist import detect_loop1
class Test_DetectLoop1(unittest.TestCase):

    @staticmethod
    def set_loop(node, loop_back):

        loop_node, prev = None, None

        while node != None:
            if node.data == loop_back:
                loop_node = node
            prev = node
            node = node.next

        prev.next = loop_node

    def setUp(self):
        pass

    def test_case1(self):

        assert detect_loop1(None) == None

    def test_case2(self):
        
        node = build_ref_list(['A', 'B', 'C', 'D', 'E'])

        self.set_loop(node, 'C')

        actual = detect_loop1(node).data

        expected = 'C'

        assert actual == expected
        
    def test_case3(self):

        node = build_ref_list(['A', 'B', 'C', 'D', 'E'])

        self.set_loop(node, 'A')

        actual = detect_loop1(node).data

        expected = 'A'

        assert actual == expected

    def test_case4(self):
        node = build_ref_list(['A', 'B', 'C', 'D', 'E'])

        self.set_loop(node, 'D')

        actual = detect_loop1(node).data

        expected = 'D'

        assert actual == expected