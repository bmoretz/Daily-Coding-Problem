from collections import Counter

'''String Compression.

Implement a methods to perform basic string compression using the counts of repeating characters.

For example,

The string aabcccccaaa would become a2b1c5a3.

If the "compressed" string would not become smaller than the original string, your methods should return the original string.

You can assume the string has only uppercase and lowercase letters (a-z).
'''

stri = 'aabbbbcccaaaeeert'

def compress(s):

    if s == None: return None

    result, prev, counter = '', s[0], 1

    for char in s[1:]:

        if char != prev:
            result += f'{prev}{counter}'
            prev, counter = char, 1
        else:
            counter += 1
    
    result += f'{prev}{counter}'

    return result if len(result) < len(s) else s

r = compress(stri)

print(r)

