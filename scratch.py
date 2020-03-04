from collections import Counter

'''One Away:

There are three types of edits that can be performed on strings:

insert a character,
remove a character,
replace a character

Given two strings, write a function to check if they are one edit (or zero edits) away.

Example:

pale, ple -> true
pales, pale -> true
pale, bale -> true
pale, bake -> false
'''

p1 = ['pale' , 'ple']
p2 = ['pales', 'pale']
p3 = ['pale', 'bale']
p4 = ['pale', 'bake']

def one_away(s1, s2):

    def get_differences(s1, s2):

        ordered = (s1, s2) if len(s1) > len(s2) else (s2, s1)

        primary, secondary = ordered[0], ordered[1]
        
        for c in secondary:

            index = primary.find(c)

            if index != -1:
                primary = primary[0 : index : ] + primary[index + 1 ::]

        return len(primary)

    if s1 is None or s1 is None: return False
    if len(s1) == 1 and len(s2) == 1: return True

    return get_differences(s1, s2) <= 1

print(one_away(p1[0], p1[1]))
print(one_away(p2[0], p2[1]))
print(one_away(p3[0], p3[1]))
print(one_away(p4[0], p4[1]))

