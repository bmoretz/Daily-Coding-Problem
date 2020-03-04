from collections import Counter

'''Palindrome Permutation:

Given a string, write a function to check if it is a permutation of a palindrome.

A palindrome is a word or phrase that is the same forwads or backwards.
A permutation is a rearrangement of letters.

They do not have to be real words.

Example:

Input: Tact Coa
Output: True (permutations: "taco cat", "atco cta", etc.)
'''

s1 = 'Tact Coa'
s2 = 'aba'
s3 = 'ab'
s4 = 'abcd'
s5 = 'tactcoapapa'

def is_palindrome_perm1(s):

    if s is None: return False
    if len(s) <= 2: return True

    occurrences = Counter(s.replace(' ', '').lower())

    n_odd = sum([0 if v % 2 == 0 else 1 for v in occurrences.values()])

    return n_odd == 1

print(is_palindrome_perm1(s5))

