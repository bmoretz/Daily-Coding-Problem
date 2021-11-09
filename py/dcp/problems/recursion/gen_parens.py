"""
Parens: Implement an algorithm to print all valid (e.g., properly opened and closed) combinations
of n pairs of parentheses.

EXAMPLE:

Input: 3
Output: ((())), (()()), (())(), ()(()), ()()()
"""

def gen_parens1(n):

    def gen(n):
        def wrap(p=''):
            return '(' + p + ')'

        if n == 1: return [wrap()]

        results = []

        for par in list(gen(n-1)):
            results.append(wrap(par))
            results.append(wrap() + par)

        return results
    
    if n == None: return None
    if n == 0: return ''

    return gen(n)