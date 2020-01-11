'''Given a string and a number of lines k, print the string in zigzag form.

In zigzag, characters are printed out diagonally from top left to bottom right until reaching the k^th line, then back up to top right, and so on.

For example, given the sentence "thisisazigzag" and k = 4, you should print:

t     a     g
 h   s z   a
  i i   i z
   s     g
'''

stri, k = "thisisazigzag", 4

def get_spaces(row, desc, k):
    max_spaces = (k - 1) * 2 - 1

    if desc:
        spaces = max_spaces - row * 2
    else:
        spaces = max_spaces - (k - 1 - row) * 2
    return spaces

def is_descending(index, k):
    # Check whether the index is more or less than halfway
    # though its ocillation back to the starting point
    return index % (2 * (k - 1)) < k -1

def zigzag(sentence, k):
    n = len(sentence)
    result = ""

    for row in range(k):
        i = row
        line = [" " for _ in range(n)]

        while i < n:
            line[i] = sentence[i]
            desc = is_descending(i, k)
            spaces = get_spaces(row, desc, k)
            i += spaces + 1
        result += "".join(line) + "\n"
    return result

print(zigzag(stri, k))

