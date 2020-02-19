'''Regular expressions.

Implement regular expression matching with the following special characters.

- . (period) which matches any single character.

- * (asterisk) which matches zero or more of the preceeding element.

That is, implement a function that takes in a string and a valid regular expression and returns whether or not the string matches
the regular expression.

For example, given the regular expression ra. and the string "ray", your function should return True. The same regular expression
on the string "raymond" should return false.

Given the regular expression .*at and the string "chat", your function  should return true. The same regular expression on the
string "chats" should return false.
'''

def matches_first_char(s, r):
    return s[0] == r[0] or (r[0] == '.' and len(s) > 0)

def matches(r, s):

    if r == '':
        return s == ''

    if len(r) == 1 or r[1] != '*':
        # The first character in the regex is not succeded by a *.
        if matches_first_char(r, s):
            return matches(s[1:], r[1:])
        else:
            return False

    else:
        # The first character is succeded by a *.
        # First, try zero length.
        if matches(s, r[2:]):
            return True

        # If that doesn't match straight away, try globbing more prefixes
        # until the first character of the string doesn't match anymore.
        i = 0
        while matches_first_char(s[i:], r):
            if matches(s[i+1:], r[2:]):
                return True

            i += 1

result = matches("ray", "ra.")

print(result)