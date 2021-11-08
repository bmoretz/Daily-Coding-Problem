'''Regular Numbers.

A regular number in mathematics is defined as one which evenly divides some power of 60. Equivalently, we can say that a regular number is one whose only prime divisors are 2, 3, and 5.

These numbers have had many applications, from helping ancient Babylonians keep time to tuning instruments according to the diatonic scale.

Given an integer n, write a program that generates, in order, the first n regular numbers.
'''

import heapq

'''O(n^3)'''
def regular_numbers1(n):
    
    twos = [2 ** i for i in range(n)]
    threes = [3 ** i for i in range(n)]
    fives = [5 ** i for i in range(n)]

    solution = set()

    for two in twos:
        for three in threes:
            for five in fives:
                solution.add(two * three * five)

    return sorted(solution)[:n]

'''O(n log n)'''
def regular_numbers2(n):

    solution = [1]
    last = 0; count = 0

    while count < n:
        x = heapq.heappop(solution)

        if x > last:
            yield x

            last = x; count += 1

            heapq.heappush(solution, 2 * x)
            heapq.heappush(solution, 3 * x)
            heapq.heappush(solution, 5 * x)
