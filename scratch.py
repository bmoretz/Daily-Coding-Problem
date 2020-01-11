'''2.4 - Determine smallest rotated string:

You are given a string of length n and an integer k. The string can be manipulated by taking one of the first k letters and moving it to the end of the string.

Write a program to determine the lexicographically smallest string that can be created after an unlimted number of moves.

For example, suppose we are given the string daily and k = 1. The best we can create in this case is ailyd.
'''

stri, k = "daily", 1

i = len(stri)
string = list(stri)

# Rotate so that i is at the beginning.

while i > 0:
    string = string[1:] + string[:1]
    i -= 1

    # Move the first two letters to the end in reversed order.
    string = string[:1] + string[2:] + string[1:2]
    string = string[1:] + string[:1]

    # Rotate back to the initial position.
    while len(string) > k + 1:
        string = string[1:] + string[:1]
        k += 1

print(''.join(string))