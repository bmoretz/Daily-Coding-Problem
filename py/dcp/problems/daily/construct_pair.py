"""
Construct Pair.

cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair.
For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.

Given this implementation of cons:

def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair

"""

from typing import Callable

def cons(a, b) -> Callable[[int, int], Callable]:
    """
    definition from problem

    Args:
        a ([type]): first element
        b ([type]): last element
    """
    def pair(f):
        return f(a, b)
    return pair

def car(pair : Callable[[int, int], Callable]) -> int:
    """
    return the first element of the pair by invoking
    the function (cons) with a lamba, then simply return
    the first argument.

    Args:
        pair ([type]): pair constructed with cons

    Returns:
        [type]: first element
    """
    return pair(lambda a, _: a)

def cdr(pair : Callable[[int, int], Callable]) -> int:
    """
    return the second element of the pair by invoking
    the function (cons) with a lamba, then simply return
    the second argument.

    Args:
        pair ([type]): pair constructed with cons

    Returns:
        [type]: second element
    """    
    return pair(lambda _, b: b)
