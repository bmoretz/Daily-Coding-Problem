import unittest

from problems.stack_queue import Stack, MaxStack
from problems.stack_queue import bracket_balanced1, bracket_balanced2
from problems.stack_queue import max_subarray1, max_subarray2, max_subarray3
from problems.stack_queue import nstack1, nstack2
from problems.stack_queue import minstack
from problems.stack_queue import set_stack

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


class Test_Tristack1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        stack = nstack1()

        assert stack.is_empty(0) == True
        assert stack.is_empty(1) == True
        assert stack.is_empty(2) == True

        assert stack.peek(0) == None
        assert stack.peek(1) == None
        assert stack.peek(2) == None

        assert stack.data == []

    def test_case2(self):
        stack = nstack1()

        assert stack.is_empty(0) == True
        assert stack.is_empty(1) == True

        assert stack.peek(0) == None

        stack.push(0, "A")

        assert stack.pop(0) == "A"

        assert stack.is_empty(0) == True

        stack.push(1, "B")
        stack.push(0, "A")

        assert stack.is_empty(1) == False
        assert stack.peek(0) == "A"
        assert stack.peek(1) == "B"
        assert stack.is_empty(2) == True

        stack.push(0, "D")
        stack.push(1, "B")
        stack.push(2, "C")

        assert stack.peek(2) == "C"

        assert stack.pop(2) == "C"

        stack.push(0, "D")

        assert stack.pop(0) == "D"

        assert len(stack.data) == 6

    def test_case3(self):

        stack = nstack1()

        stack.push(0, 'A')
        stack.push(0, 'B')
        stack.push(0, 'C')

        assert stack.pop(0) == "C"
        assert stack.pop(0) == "B"
        assert stack.pop(0) == "A"

        assert stack.is_empty(0)

        assert stack.data == []

    def test_case4(self):

        stack = nstack1(3)

        stack.push(0, 'A')
        stack.push(1, 'B')
        stack.push(2, 'C')

        stack.push(0, 'B')

        assert stack.pop(0) == 'B'

        assert stack.data == ['A', 'B', 'C']

    def test_case5(self):

        stack = nstack1()

        stack.push(0, 'A')
        stack.push(0, 'A')
        stack.push(0, 'A')

        stack.push(1, 'B')

        stack.push(2, 'C')

        stack.push(0, 'A')

        assert stack.pop(0) == 'A'

        assert stack.pop(1) == 'B'

        assert stack.pop(2) == 'C'

        assert stack.pop(0) == 'A'
        assert stack.pop(0) == 'A'
        assert stack.pop(0) == 'A'

        assert stack.is_empty(0)
        assert stack.is_empty(1)
        assert stack.is_empty(2)

        assert stack.data == []


class Test_Tristack2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        stack = nstack2()

        assert stack.is_empty(0) == True
        assert stack.is_empty(1) == True
        assert stack.is_empty(2) == True

        assert stack.peek(0) == None
        assert stack.peek(1) == None
        assert stack.peek(2) == None

        assert stack.data == []

    def test_case2(self):
        stack = nstack2()

        assert stack.is_empty(0) == True
        assert stack.is_empty(1) == True

        assert stack.peek(0) == None

        stack.push(0, "A")

        assert stack.pop(0) == "A"

        assert stack.is_empty(0) == True

        stack.push(1, "B")
        stack.push(0, "A")

        assert stack.is_empty(1) == False
        assert stack.peek(0) == "A"
        assert stack.peek(1) == "B"
        assert stack.is_empty(2) == True

        stack.push(0, "D")
        stack.push(1, "B")
        stack.push(2, "C")

        assert stack.peek(2) == "C"

        assert stack.pop(2) == "C"

        stack.push(0, "D")

        assert stack.pop(0) == "D"

    def test_case3(self):

        stack = nstack2()

        stack.push(0, 'A')
        stack.push(0, 'B')
        stack.push(0, 'C')

        assert stack.pop(0) == "C"
        assert stack.pop(0) == "B"
        assert stack.pop(0) == "A"

        assert stack.is_empty(0)

        assert stack.data == []

    def test_case4(self):

        stack = nstack2(3)

        stack.push(0, 'A')
        stack.push(1, 'B')
        stack.push(2, 'C')

        stack.push(0, 'B')

        assert stack.pop(0) == 'B'

    def test_case5(self):

        stack = nstack2()

        stack.push(0, 'A')
        stack.push(0, 'A')
        stack.push(0, 'A')

        stack.push(1, 'B')

        stack.push(2, 'C')

        stack.push(0, 'A')

        assert stack.pop(0) == 'A'
        assert stack.pop(1) == 'B'
        assert stack.pop(2) == 'C'

        assert stack.pop(0) == 'A'
        assert stack.pop(0) == 'A'
        assert stack.pop(0) == 'A'

        assert stack.is_empty(0)
        assert stack.is_empty(1)

        assert stack.data == []

class Test_MinStack(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        stack = minstack()

        assert stack.is_empty() == True
        assert stack.peek() == None
        assert stack.min() == None

        stack.push(0)

        assert stack.is_empty() == False
        assert stack.min() == 0
        assert stack.peek() == 0

        assert stack.pop() == 0
        assert stack.is_empty()

    def test_case2(self):
        stack = minstack()

        stack.push(0)
        stack.push(1)
        stack.push(2)
        stack.push(3)

        assert stack.is_empty() == False
        assert stack.min() == 0
        assert stack.peek() == 3

        assert stack.pop() == 3
        assert stack.min() == 0

        assert stack.pop() == 2
        assert stack.min() == 0

        assert stack.pop() == 1
        assert stack.min() == 0

        assert stack.pop() == 0

        assert stack.is_empty() == True

    def test_case3(self):
        stack = minstack()

        stack.push(4)
        stack.push(3)
        stack.push(2)
        stack.push(1)
        stack.push(0)

        assert stack.is_empty() == False
        assert stack.min() == 0
        assert stack.peek() == 0

        assert stack.pop() == 0
        assert stack.pop() == 1
        assert stack.pop() == 2
        assert stack.pop() == 3
        assert stack.pop() == 4

    def test_case4(self):
        stack = minstack()

        stack.push(4)
        stack.push(2)
        stack.push(-1)
        stack.push(5)
        stack.push(2)
        stack.push(0)

        assert stack.is_empty() == False
        assert stack.min() == -1
        assert stack.peek() == 0

        assert stack.pop() == 0
        assert stack.min() == -1

        assert stack.pop() == 2
        assert stack.min() == -1

        assert stack.pop() == 5
        assert stack.min() == -1

        assert stack.pop() == -1
        assert stack.min() == 2

        assert stack.pop() == 2
        
        assert stack.min() == 4
        assert stack.pop() == 4

        assert stack.is_empty() == True
        
    def test_case5(self):
        stack = minstack()

        stack.push(4)
        stack.push(2)
        stack.push(-1)
        stack.push(5)
        stack.push(2)
        stack.push(0)

        assert stack.is_empty() == False
        assert stack.min() == -1
        assert stack.peek() == 0

        assert stack.pop() == 0
        assert stack.min() == -1

        assert stack.pop() == 2
        assert stack.min() == -1

        assert stack.pop() == 5
        assert stack.min() == -1

        assert stack.pop() == -1
        assert stack.min() == 2

        assert stack.pop() == 2
        assert stack.min() == 4
        assert stack.pop() == 4

        assert stack.is_empty() == True
class Test_StackOfStacks(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        stack = set_stack(3)

        stack.push(4)
        stack.push(2)
        stack.push(-1)
        stack.push(5)
        stack.push(2)
        stack.push(0)

        assert stack.is_empty() == False

        assert stack.peek() == 0
        assert stack.pop() == 0

        assert stack.peek() == 2
        assert stack.pop() == 2

        assert stack.peek() == 5
        assert stack.pop() == 5

        assert stack.peek() == -1
        assert stack.pop() == -1

        assert stack.peek() == 2
        assert stack.pop() == 2

        assert stack.peek() == 4
        assert stack.pop() == 4

        assert stack.is_empty() == True

    def test_case2(self):
        stack = set_stack(3)

        stack.push(4)
        stack.push(2)
        stack.push(-1)
        stack.push(5)
        stack.push(2)
        stack.push(0)

        assert stack.is_empty() == False

        assert stack.pop_at(1) == -1
        assert stack.pop_at(1) == 2
        assert stack.pop_at(1) == 4

        assert stack.pop_at(1) == None

        assert stack.pop() == 0
        assert stack.pop() == 2
        assert stack.pop() == 5

    def test_case3(self):
        stack = set_stack(3)

        stack.push(4)
        stack.push(2)
        stack.push(-1)
        stack.push(5)
        stack.push(2)
        stack.push(0)

        assert stack.is_empty() == False

        assert stack.pop_at(1) == -1

        assert stack.pop() == 0
        assert stack.pop() == 2
        assert stack.pop() == 5

        assert stack.pop() == 2
        assert stack.pop() == 4

        assert stack.pop_at(1) == None


    def test_case4(self):
        stack = set_stack(3)

        stack.push(4)
        stack.push(2)
        stack.push(-1)
        stack.push(5)
        stack.push(2)
        stack.push(0)

        assert stack.is_empty() == False

        assert stack.pop_at(1) == -1
        assert stack.pop_at(1) == 2

        assert stack.pop() == 0
        assert stack.pop() == 2
        assert stack.pop() == 5

        assert stack.pop() == 4

        assert stack.pop_at(1) == None
        
    def test_case5(self):
        stack = set_stack(3)

        stack.push(4)
        stack.push(2)
        stack.push(-1)

        stack.push(5)
        stack.push(2)
        stack.push(0)

        stack.push(3)
        stack.push(8)
        stack.push(7)

        assert stack.is_empty() == False

        assert stack.pop_at(1) == 0
        assert stack.pop_at(2) == 2

        assert stack.pop() == 7

        assert stack.pop_at(2) == None

        assert stack.pop_at(1) == 5

        assert stack.pop() == 8

        assert stack.pop_at(1) == 4

        assert stack.pop() == 3
        assert stack.pop() == 2
        assert stack.pop() == -1

        assert stack.pop_at(1) == None