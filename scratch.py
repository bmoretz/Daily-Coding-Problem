import heapq

from collections import defaultdict
from problems.heap import regular_numbers1, regular_numbers2

'''Regular Numbers.

A regular number in mathematics is defined as one which evenly divides some power of 60. Equivalently, we can say that a regular number is one whose only prime divisors are 2, 3, and 5.

These numbers have had many applications, from helping ancient Babylonians keep time to tuning instruments according to the diatonic scale.

Given an integer n, write a program that generates, in order, the first n regular numbers.
'''

reg2 = regular_numbers2(10)
reg1 = regular_numbers1(10)

print(reg1)
print(list(reg2))