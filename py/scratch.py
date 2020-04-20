'''Permutations without Dups.

Write a method to compute all permutations of a string of unique characters.
'''


def permutations(chars, allow_dups=False):
    
    n = len(chars)

    if n == 1: return chars
    
    results = []

    for index in range(len(chars)):

        cur, rem = chars[index], ''.join([c for i, c in enumerate(chars) if i != index])

        perms = permutations(rem)

        for perm in perms:
            
            lr = str(perm + cur)

            if lr in results and allow_dups:
                results.append(lr)
            else:
                results.append(lr)

            rl = str(cur + perm)

            if rl in results and allow_dups:
                results.append(rl)
            else:
                results.append(rl)

    return results

perms = permutations('abcd', False)

print(len(perms))
print(perms)