'''Given a list of words, find all pairs of kunique indices such that the concatenation of the two words is a palindrome.

For example, given the list ["code", "edoc", "da", "d"], return [(0, 1), (1, 0), (2, 3)]
'''

def is_palindrome(stri):
    n = len(stri) - 1

    is_pal = True
    for index in range(n):
        is_pal &= stri[index] == stri[n - index]
    
    return is_pal

arr = ["code", "edoc", "da", "d"]

n, c = len(arr) - 1, 0
iters = []

for index in range(n, -1, -1):
    val = list(zip( [c] * index, [x + (c + 1) for x in range(index)] ))
    iters.append(val)
    c = c + 1

flattend = [item for sublist in iters for item in sublist]

results = []

for index, value in enumerate(flattend):

    e1, e2 = value[0], value[1]

    if is_palindrome(arr[e1] + arr[e2]):
        results.append((e1, e2))

    if is_palindrome(arr[e2] + arr[e1]):
        results.append((e2, e1))

print(results)
