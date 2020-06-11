'''Random Set.

Write a method to randomly generate a set of m integers from 
an array of size n. Each element must have equal probability
to be chosen.
'''

from random import randint

def get_unique_set(n, k):

    if k < n:
        raise RuntimeError('Cannot generate a unique set with k < n.')

    results = set()
    
    while len(results) < n:

        new = randint(0, k)

        if new not in results:
            results.add(new)

    return results

def get_random_set(data, m):

    bag = list(data)
    results = []

    while len(results) < m:
        
        index = randint(0, len(bag) - 1)

        results += [bag[index]]
        del bag[index]

    return results

items = get_unique_set(50, 100)

sub = get_random_set(items, 5)

print(sub)