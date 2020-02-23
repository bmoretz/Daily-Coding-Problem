from collections import defaultdict

'''Number of ways to decode a string.

Given the mapping a = 1, b = 2, ..., z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message "111" should be 3, since it could be decoded as "aaa", "ka", and "ak".

You can assume that the messages are always decodable. For example, "001" is not allowed.
'''

stri = "111"

def num_encodings1(s):

    def num_encodings(s, total=0):
        # There are no valid encodings if the string starts with 0.
        if s.startswith('0'):
            return 0

        # Both the empty string and a single character should return 1.
        elif len(s) <= 1:
            return 1

        total += num_encodings(s[1:])

        if int(s[:2]) <= 26:
            total += num_encodings(s[2:])

        return total
    
    return num_encodings(s)

def num_encodings2(s):
    cache = defaultdict(int)
    cache[len(s)] = 1

    for i in reversed(range(len(s))):
        if s[i].startswith('0'):
            cache[i] = 0
        elif i == len(s) - 1:
            cache[i] = 1
        else:
            cache[i] += cache[i + 1]

            if int(s[i:i + 2]) <= 26:
                cache[i] = cache[i + 2]

    return cache[0]

print(num_encodings2(stri))
