'''Number Swapper.

Write a function to swap a number in place (that is, without temporary variables).
'''

def number_swap(a, b):

    a = a ^ b
    b = b ^ a
    a = a ^ b

    return a, b