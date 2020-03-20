import unittest

from problems.stack_queue import Stack
class Test_Stack(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        stack = Stack()

        assert stack.is_empty() == True

        assert stack.pop() == None

    def test_case2(self):

        stack = Stack()

        assert stack.is_empty() == True

        stack.push(2)

        assert stack.is_empty() == False
        assert stack.peek() == 2

        stack.push(3)

        assert stack.is_empty() == False
        assert stack.peek() == 3

        stack.push(5)

        assert stack.is_empty() == False
        assert stack.peek() == 5

        stack.push(1)

        assert stack.is_empty() == False
        assert stack.peek() == 1

        stack.push(4)

        assert stack.is_empty() == False
        assert stack.peek() == 4

    def test_case3(self):
        stack = Stack()

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

    def test_case4(self):
        stack = Stack()

        stack.push(4)
        stack.push(2)
        stack.push(-1)

        assert stack.is_empty() == False

        assert stack.peek() == -1

        stack.push(5)
        
        assert stack.peek() == 5

        stack.push(2)
        
        assert stack.peek() == 2

        stack.push(0)

        assert stack.peek() == 0

        assert stack.pop() == 0
        assert stack.pop() == 2
        assert stack.pop() == 5

        assert stack.peek() == -1

        assert stack.pop() == -1
        assert stack.pop() == 2
        assert stack.pop() == 4

        assert stack.is_empty() == True

    def test_case5(self):
        stack = Stack()

        stack.push(4)

        assert stack.is_empty() == False

        assert stack.peek() == 4
        assert stack.pop() == 4

        assert stack.is_empty() == True

        stack.push(2)
        stack.push(-1)
        stack.push(5)

        assert stack.is_empty() == False

        assert stack.peek() == 5
        assert stack.pop() == 5

        assert stack.peek() == -1
        assert stack.pop() == -1

        assert stack.peek() == 2
        assert stack.pop() == 2

        assert stack.is_empty() == True

        stack.push(2)
        stack.push(0)

        assert stack.is_empty() == False

        assert stack.pop() == 0
        assert stack.pop() == 2

        assert stack.is_empty() == True

from problems.stack_queue import Queue
class Test_Queue(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        queue = Queue()

        queue.enqueue(1)

        assert queue.dequeue() == 1

        assert queue.is_empty() == True

        queue.enqueue(2)

        assert queue.peek() == 2

        queue.enqueue(3)

        assert queue.peek() == 2

        queue.enqueue(4)

        assert queue.peek() == 2

        queue.enqueue(5)

        assert queue.peek() == 2

        assert queue.is_empty() == False
        
    def test_case2(self):
        queue = Queue()

        assert queue.is_empty() == True

        queue.enqueue(1)

        assert queue.peek() == 1

        queue.enqueue(2)

        assert queue.peek() == 1

        queue.enqueue(3)

        assert queue.is_empty() == False
        assert queue.peek() == 1

        assert queue.dequeue() == 1
        assert queue.peek() == 2

        assert queue.dequeue() == 2
        assert queue.peek() == 3

        assert queue.dequeue() == 3

        assert queue.is_empty() == True

    def test_case3(self):
        queue = Queue()

        assert queue.peek() == None
        assert queue.dequeue() == None

        queue.enqueue(1)
        queue.enqueue(2)
        queue.enqueue(3)
        queue.enqueue(4)
        queue.enqueue(5)

        assert queue.peek() == 1
        assert queue.dequeue() == 1

        assert queue.peek() == 2
        assert queue.dequeue() == 2

        assert queue.peek() == 3
        assert queue.dequeue() == 3

        queue.enqueue(2)

        assert queue.peek() == 4
        assert queue.dequeue() == 4

        assert queue.peek() == 5
        assert queue.dequeue() == 5

        assert queue.peek() == 2
        assert queue.dequeue() == 2

        assert queue.is_empty() == True

    def test_case4(self):
        queue = Queue()

        queue.enqueue(1)
        queue.enqueue(2)
        queue.enqueue(3)

        assert queue.peek() == 1
        assert queue.dequeue() == 1

        assert queue.peek() == 2
        assert queue.dequeue() == 2

        queue.enqueue(4)

        assert queue.peek() == 3

        queue.enqueue(5)

        assert queue.peek() == 3

        assert queue.dequeue() == 3

        assert queue.peek() == 4
        assert queue.dequeue() == 4

        assert queue.dequeue() == 5

        assert queue.is_empty() == True

    def test_case6(self):

        queue = Queue()

        assert queue.is_empty() == True

        queue.enqueue(2)

        assert queue.is_empty() == False
        assert queue.peek() == 2

        queue.enqueue(3)

        assert queue.is_empty() == False
        assert queue.peek() == 2

        queue.enqueue(5)

        assert queue.is_empty() == False
        assert queue.peek() == 2

        queue.enqueue(1)

        assert queue.is_empty() == False
        assert queue.peek() == 2

        queue.enqueue(4)

        assert queue.is_empty() == False
        assert queue.peek() == 2

from problems.stack_queue import MaxStack
class Test_MaxStack(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        s = MaxStack()

        for i in [2, 3, 5, 1, 4]:
            s.push(i)

        assert s.max() == 5

from problems.stack_queue import bracket_balanced1
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

from problems.stack_queue import bracket_balanced2
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

from problems.stack_queue import max_subarray1
class Test_MaxSub1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        arr, k = [10, 5, 2, 7, 8, 7], 3

        assert max_subarray1(arr, k) == [10, 7, 8, 8]
    
    def test_case2(self):
        arr, k = [1, 2, 3, 4, 5, 6, 7, 8, 9], 3

        assert max_subarray1(arr, k) == [3, 4, 5, 6, 7, 8, 9]

from problems.stack_queue import max_subarray2
class Test_MaxSub2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        arr, k = [10, 5, 2, 7, 8, 7], 3

        assert max_subarray2(arr, k) == [10, 7, 8, 8]

    def test_case2(self):
        arr, k = [1, 2, 3, 4, 5, 6, 7, 8, 9], 3

        assert max_subarray2(arr, k) == [3, 4, 5, 6, 7, 8, 9]

from problems.stack_queue import max_subarray3
class Test_MaxSub3(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        arr, k = [10, 5, 2, 7, 8, 7], 3

        assert max_subarray3(arr, k) == [10, 7, 8, 8]

    def test_case2(self):
        arr, k = [1, 2, 3, 4, 5, 6, 7, 8, 9], 3

        assert max_subarray3(arr, k) == [3, 4, 5, 6, 7, 8, 9]

from problems.stack_queue import nstack1
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

from problems.stack_queue import nstack2
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

from problems.stack_queue import minstack
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

from problems.stack_queue import set_stack1
class Test_StackOfStacks1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        stack = set_stack1(3)

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
        stack = set_stack1(3)

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
        stack = set_stack1(3)

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
        stack = set_stack1(3)

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
        stack = set_stack1(3)

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

from problems.stack_queue import set_stack2
class Test_StackOfStacks2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        stack = set_stack2(3)

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
        stack = set_stack2(3)

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
        stack = set_stack2(3)

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
        stack = set_stack2(3)

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
        stack = set_stack2(3)

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

from problems.stack_queue import my_queue1
class Test_MyQueue1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        queue = my_queue1()

        queue.enqueue(1)

        assert queue.dequeue() == 1

        assert queue.is_empty() == True

        queue.enqueue(2)

        assert queue.peek() == 2

        queue.enqueue(3)

        assert queue.peek() == 2

        queue.enqueue(4)

        assert queue.peek() == 2

        queue.enqueue(5)

        assert queue.peek() == 2

        assert queue.is_empty() == False
        
    def test_case2(self):
        queue = my_queue1()

        assert queue.is_empty() == True

        queue.enqueue(1)

        assert queue.peek() == 1

        queue.enqueue(2)

        assert queue.peek() == 1

        queue.enqueue(3)

        assert queue.is_empty() == False
        assert queue.peek() == 1

        assert queue.dequeue() == 1
        assert queue.peek() == 2

        assert queue.dequeue() == 2
        assert queue.peek() == 3

        assert queue.dequeue() == 3

        assert queue.is_empty() == True

    def test_case3(self):
        queue = my_queue1()

        assert queue.peek() == None
        assert queue.dequeue() == None

        queue.enqueue(1)
        queue.enqueue(2)
        queue.enqueue(3)
        queue.enqueue(4)
        queue.enqueue(5)

        assert queue.peek() == 1
        assert queue.dequeue() == 1

        assert queue.peek() == 2
        assert queue.dequeue() == 2

        assert queue.peek() == 3
        assert queue.dequeue() == 3

        queue.enqueue(2)

        assert queue.peek() == 4
        assert queue.dequeue() == 4

        assert queue.peek() == 5
        assert queue.dequeue() == 5

        assert queue.peek() == 2
        assert queue.dequeue() == 2

        assert queue.is_empty() == True

    def test_case4(self):
        queue = my_queue1()

        queue.enqueue(1)
        queue.enqueue(2)
        queue.enqueue(3)

        assert queue.peek() == 1
        assert queue.dequeue() == 1

        assert queue.peek() == 2
        assert queue.dequeue() == 2

        queue.enqueue(4)

        assert queue.peek() == 3

        queue.enqueue(5)

        assert queue.peek() == 3

        assert queue.dequeue() == 3

        assert queue.peek() == 4
        assert queue.dequeue() == 4

        assert queue.dequeue() == 5

        assert queue.is_empty() == True

from problems.stack_queue import sort_stack1

class Test_SortStack1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        data = Stack()

        data.push(2)
        data.push(3)
        data.push(5)
        data.push(1)
        data.push(4)

        result = sort_stack1(data)

        assert result.pop() == 1
        assert result.pop() == 2
        assert result.pop() == 3
        assert result.pop() == 4
        assert result.pop() == 5

        assert result.is_empty() == True
        
    def test_case2(self):
        data = Stack()

        data.push(5)
        data.push(4)
        data.push(3)
        data.push(2)
        data.push(1)

        result = sort_stack1(data)

        assert result.pop() == 1
        assert result.pop() == 2
        assert result.pop() == 3
        assert result.pop() == 4
        assert result.pop() == 5

        assert result.is_empty() == True

    def test_case3(self):
        data = Stack()

        data.push(-2)
        data.push(-3)
        data.push(-5)
        data.push(-1)
        data.push(-4)

        result = sort_stack1(data)

        assert result.pop() == -5
        assert result.pop() == -4
        assert result.pop() == -3
        assert result.pop() == -2
        assert result.pop() == -1

        assert result.is_empty() == True

    def test_case4(self):
        data = Stack()

        data.push(1)
        data.push(2)
        data.push(3)
        data.push(4)
        data.push(5)

        result = sort_stack1(data)

        assert result.pop() == 1
        assert result.pop() == 2
        assert result.pop() == 3
        assert result.pop() == 4
        assert result.pop() == 5

        assert result.is_empty() == True

from problems.stack_queue import Animal, Species
from problems.stack_queue import AnimalShelter1
class Test_AnimalShelter1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        shelter = AnimalShelter1()

        assert shelter.dequeue_any() == None
        assert shelter.dequeue_cat() == None
        assert shelter.dequeue_dog() == None

    def test_case2(self):
        shelter = AnimalShelter1()

        shelter.enqueue(Animal("Burt", Species.Dog))
        shelter.enqueue(Animal("Ernie", Species.Dog))
        shelter.enqueue(Animal("Garfield", Species.Cat))
        shelter.enqueue(Animal("Whiskers", Species.Cat))
        shelter.enqueue(Animal("Angus", Species.Dog))

        adopt1 = shelter.dequeue_any()

        assert adopt1.name == "Burt" and adopt1.species == Species.Dog

        adopt2 = shelter.dequeue_cat()

        assert adopt2.name == "Garfield" and adopt2.species == Species.Cat

        adopt3 = shelter.dequeue_dog()

        assert adopt3.name == "Ernie" and adopt3.species == Species.Dog

        adopt4 = shelter.dequeue_any()

        assert adopt4.name == "Whiskers" and adopt4.species == Species.Cat

        adopt5 = shelter.dequeue_cat()

        assert adopt5 == None

        adopt6 = shelter.dequeue_dog()

        assert adopt6.name == "Angus" and adopt6.species == Species.Dog

    def test_case3(self):
        shelter = AnimalShelter1()

        assert shelter.dequeue_any() == None

        shelter.enqueue(Animal("Burt", Species.Dog))
        shelter.enqueue(Animal("Ernie", Species.Dog))

        adopt1 = shelter.dequeue_any()

        assert adopt1.name == "Burt" and adopt1.species == Species.Dog

        assert shelter.dequeue_cat() == None

        adopt2 = shelter.dequeue_any()

        assert adopt2.name == "Ernie" and adopt2.species == Species.Dog

        assert shelter.dequeue_any() == None


    def test_case4(self):
        shelter = AnimalShelter1()

        assert shelter.dequeue_any() == None

        shelter.enqueue(Animal("Burt", Species.Dog))
        shelter.enqueue(Animal("Ernie", Species.Dog))
        shelter.enqueue(Animal("Angus", Species.Dog))
        shelter.enqueue(Animal("Garfield", Species.Cat))
        shelter.enqueue(Animal("Whiskers", Species.Cat))
        shelter.enqueue(Animal("Grumpy", Species.Cat))

        adopt1 = shelter.dequeue_cat()
        assert adopt1.name == "Garfield" and adopt1.species == Species.Cat

        adopt2 = shelter.dequeue_cat()
        assert adopt2.name == "Whiskers" and adopt2.species == Species.Cat

        adopt3 = shelter.dequeue_cat()
        assert adopt3.name == "Grumpy" and adopt3.species == Species.Cat

        assert shelter.dequeue_cat() == None

        adopt4 = shelter.dequeue_dog()
        assert adopt4.name == "Burt" and adopt4.species == Species.Dog

        adopt5 = shelter.dequeue_dog()
        assert adopt5.name == "Ernie" and adopt5.species == Species.Dog

        adopt6 = shelter.dequeue_dog()
        assert adopt6.name == "Angus" and adopt6.species == Species.Dog

        assert shelter.dequeue_cat() == None
        assert shelter.dequeue_dog() == None
        assert shelter.dequeue_any() == None

from problems.stack_queue import AnimalShelter2
from time import sleep
class Test_AnimalShelter2(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):
        
        shelter = AnimalShelter2()

        assert shelter.dequeue_any() == None
        assert shelter.dequeue_cat() == None
        assert shelter.dequeue_dog() == None

    def test_case2(self):
        shelter = AnimalShelter2()

        shelter.enqueue(Animal("Burt", Species.Dog))
        sleep(.01)
        shelter.enqueue(Animal("Ernie", Species.Dog))
        sleep(.01)
        shelter.enqueue(Animal("Garfield", Species.Cat))
        sleep(.01)
        shelter.enqueue(Animal("Whiskers", Species.Cat))
        sleep(.01)
        shelter.enqueue(Animal("Angus", Species.Dog))

        adopt1 = shelter.dequeue_any()

        assert adopt1.name == "Burt" and adopt1.species == Species.Dog

        adopt2 = shelter.dequeue_cat()

        assert adopt2.name == "Garfield" and adopt2.species == Species.Cat

        adopt3 = shelter.dequeue_dog()

        assert adopt3.name == "Ernie" and adopt3.species == Species.Dog

        adopt4 = shelter.dequeue_any()

        assert adopt4.name == "Whiskers" and adopt4.species == Species.Cat

        adopt5 = shelter.dequeue_cat()

        assert adopt5 == None

        adopt6 = shelter.dequeue_dog()

        assert adopt6.name == "Angus" and adopt6.species == Species.Dog

    def test_case3(self):
        shelter = AnimalShelter2()

        assert shelter.dequeue_any() == None

        shelter.enqueue(Animal("Burt", Species.Dog))
        shelter.enqueue(Animal("Ernie", Species.Dog))

        adopt1 = shelter.dequeue_any()

        assert adopt1.name == "Burt" and adopt1.species == Species.Dog

        assert shelter.dequeue_cat() == None

        adopt2 = shelter.dequeue_any()

        assert adopt2.name == "Ernie" and adopt2.species == Species.Dog

        assert shelter.dequeue_any() == None


    def test_case4(self):
        shelter = AnimalShelter2()

        assert shelter.dequeue_any() == None

        shelter.enqueue(Animal("Burt", Species.Dog))
        shelter.enqueue(Animal("Ernie", Species.Dog))
        shelter.enqueue(Animal("Angus", Species.Dog))
        shelter.enqueue(Animal("Garfield", Species.Cat))
        shelter.enqueue(Animal("Whiskers", Species.Cat))
        shelter.enqueue(Animal("Grumpy", Species.Cat))

        adopt1 = shelter.dequeue_cat()
        assert adopt1.name == "Garfield" and adopt1.species == Species.Cat

        adopt2 = shelter.dequeue_cat()
        assert adopt2.name == "Whiskers" and adopt2.species == Species.Cat

        adopt3 = shelter.dequeue_cat()
        assert adopt3.name == "Grumpy" and adopt3.species == Species.Cat

        assert shelter.dequeue_cat() == None

        adopt4 = shelter.dequeue_dog()
        assert adopt4.name == "Burt" and adopt4.species == Species.Dog

        adopt5 = shelter.dequeue_dog()
        assert adopt5.name == "Ernie" and adopt5.species == Species.Dog

        adopt6 = shelter.dequeue_dog()
        assert adopt6.name == "Angus" and adopt6.species == Species.Dog

        assert shelter.dequeue_cat() == None
        assert shelter.dequeue_dog() == None
        assert shelter.dequeue_any() == None