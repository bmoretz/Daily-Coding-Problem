
''' Unique characters.

Implement an algorithm to determine if a string has all unique characters.

What if you can't use additional data structures?
'''

s1 = "abbbcdeffg"
s2 = "abcdefg"
s3 = None

def is_unique2(string):
    values = 0
    for char in string:

        current = ord(char) - ord('a')

        val = values & (1 << current)
        
        if val > 0:
            return False

        values |= (1 << current)

    return True


#print(2 & 1)
print(is_unique2(s1))

