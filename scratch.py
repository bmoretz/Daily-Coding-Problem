'''String Rotation.

Assume you have a method is_substring which checks if one word is a substring of another. Given two strings, s1 and s2, write code
to check if s2 is a rotation of s1 using only one call to is_substring (e.g., "waterbottle" is a rotation of "erbottlewat").
'''

def is_substring(s1, s2):
    return s1.index(s2) != -1

def is_rotation1(s1, s2):

    def rotate(s, n):
        return s[n:] + s[:n]

    if s1 is None or s2 is None: return None

    if not isinstance(s1, str) or not isinstance(s2, str):
        raise TypeError('s1 and s2 must be strings.')

    if len(s1) <= 1: return True

    rotations = ''

    for index in range(len(s1)):
        rotations += '|'.join([rotate(s1, index)])

    return is_substring(rotations, s2)

s1 = 'waterbottle'
s2 = 'erbottlewat'


is_rot = is_rotation1(s1, s2)

print(is_rot)