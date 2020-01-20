from problems.stack_queue import Stack, MaxStack

'''4.2

Given a string of round, curly, and square opening and closing brackers, return whether the brackets are balanced (well-formed).

For example, 

given the string "([])[]({})", return true.
Given the string "([)]" or "((()", you should return false.
'''

instr = "([])[]({})"

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

print( bracket_balanced2(instr) )
