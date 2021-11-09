"""Is Well-Formed?

Given a string of round, curly, and square opening and closing brackets, return whether the brackets are balanced (well-formed).

For example, 

given the string "([])[]({})", return true.
Given the string "([)]" or "((()", you should return false.
"""

from .stack import Stack

def bracket_balanced1(instr):
    braces = {'}' : '{', ')' : '(', ']' : '['}
    stack = Stack()
    
    for char in instr:

        if char in braces.values():
            stack.push(char)
        elif char in braces.keys():
            if stack.is_empty(): 
                return False

            if braces.get(char) == stack.peek():
                stack.pop()

    return stack.is_empty()

def bracket_balanced2(instr):
    stack = []

    for char in instr:
        if char in ["(", "[", "{"]:
            stack.append(char)
        else:
            # Check character is not unmatched
            if not stack:
                return False
        
            # Character is a closing bracket. Check top of stack  matches.
            if (char == ")" and stack[-1] != "(") or \
                (char == "]" and stack[-1] != "[") or \
                (char == "}" and stack[-1] != "{"):
                return False
            stack.pop()

    return len(stack) == 0