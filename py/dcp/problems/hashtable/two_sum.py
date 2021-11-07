'''Two Sum.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given

[10, 15, 3, 7] and k = 17,

we should return True, since 10 + 7 = 17
'''

def two_sum1(lst, k):

    seen = {}

    for num in lst:
        if k - num in seen:
            return True

        seen[num] = True

    return False