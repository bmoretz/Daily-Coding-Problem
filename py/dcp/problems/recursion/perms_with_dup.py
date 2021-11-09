"""
Permutations without duplicates.

Write a method to compute all permutations of a string of unique characters.
"""

def permutations1(chars):

    def get_perms(chars):
        n = len(chars)

        if n == 1: return chars
        
        results = []

        for index in range(len(chars)):

            cur, rem = chars[index], ''.join([c for i, c in enumerate(chars) if i != index])

            perms = get_perms(rem)

            for perm in perms:
                results.append(str(perm + cur))

        return results
    
    return get_perms(chars)