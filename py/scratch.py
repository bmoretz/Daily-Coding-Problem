"""
Decoding.

Given the mapping a = 1, b = 2, … z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message ‘111’ would give 3, since it could be decoded as ‘aaa’, ‘ka’, and ‘ak’.

You can assume that the messages are decodable. For example, ‘001’ is not allowed.
"""

def decode(msg : str) -> int:

    msg_len = len(msg)

    n_solutions = [1] * (msg_len + 1)

    for index in range(2, msg_len+1):
        last_digit = int(msg[index-1])
        two_last_digits = int(msg[(index-2):index])

        if last_digit > 0:
            n_solutions[index] = n_solutions[index - 1]

        if two_last_digits > 9 & two_last_digits < 27:
            n_solutions[index] += n_solutions[index - 2]

    return n_solutions[-1]

print(decode('111'))