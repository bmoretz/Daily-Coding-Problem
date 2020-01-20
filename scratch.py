from problems.stack_queue import Stack, MaxStack

'''4.2

Given a string of round, curly, and square opening and closing brackers, return whether the brackets are balanced (well-formed).

For example, 

given the string "([])[]({})", return true.
Given the string "([)]" or "((()", you should return false.
'''

instr = "((()"

def is_balanced(instr):
    braces = {'}' : '{', ')' : '(', ']' : '['}
    stack = Stack()
    
    for char in instr:

        if char in braces.values():
            stack.push(char)
        elif char in braces.keys():
            if braces.get(char) == stack.peek():
                stack.pop()

    return stack.length() == 0

print( is_balanced(instr) )
