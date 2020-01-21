from problems.stack_queue import Stack, MaxStack

from collections import deque

'''4.4
Reconstruct array using +/- signs

The sequance [0, 1, ..., N] has been jumbled, and the only clue you have for its order is an array representing whether each number is larger or smaller than the last.

Given this information, reconstruct an array that is consistent with it. 

For example, given 

[None, +, +, -, +],

You could return,

[1, 2, 3, 0, 4]
'''

lst = [None, '+', '+', '-', '+']

def reconstruct1(array):
    answer = []
    n = len(array) - 1
    stack = []

    for i in range(n):
        if array[i + 1] == '-':
            stack.append(i)
        else:
            answer.append(i)
            while stack:
                answer.append(stack.pop())

    stack.append(n)

    while stack:
        answer.append(stack.pop())

    return answer

print(reconstruct1(lst))