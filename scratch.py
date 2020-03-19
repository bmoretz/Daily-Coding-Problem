from problems.stack_queue import Stack

'''Sort Stack.

Write a program to sort a stack such that the smallest items are on top. You can use an 
additional temporary stack, but you mat not copy the elements into any other data structure
(such as an array). The stack supports the following operations:

push, pop, peek, and is_empty.
'''

def sort_stack(stack):

    def shift_min(stack, cutoff):
        temp, maximum, n = Stack(), None, 0

        while not stack.is_empty() and n < cutoff:
            
            current = stack.pop()

            if maximum is None or current > maximum:
                maximum = current

            temp.push(current)
            n += 1
        
        stack.push(maximum)

        while not temp.is_empty():

            current = temp.pop()

            if current == maximum:
                minimum = None
                continue

            stack.push(current)
        
        return stack

    def get_len(stack):

        temp, n = Stack(), 0

        while not stack.is_empty():
            temp.push(stack.pop())
            n += 1

        return (temp, n)

    if stack is None: return

    stack, n = get_len(stack)

    for index in reversed(range(1, n + 1)):
        stack = shift_min(stack, index)

    return stack

data = Stack()

data.push(2)
data.push(3)
data.push(5)
data.push(1)
data.push(4)

actual = sort_stack(data)

while not actual.is_empty():
    print(actual.pop())
