
'''URLify.

Write a method to replace all spaces in a string with '%20'. You may assume that the string
has sufficient space at the end to hold the additional characters, and that you are given
the "true" length of the string.
'''

url = "Mr John Smith"
expected = "Mr%20John%20Smith"

url = 'a a'

''' O(N) runtime, O(n) space. '''
def urlify(url):

    def count_spaces(s):
        return sum([1 if c.isspace() else 0 for c in s])

    def to_str(s):
        return ''.join(s)

    if url is None: return None
    
    n = len(url) + count_spaces(url) * 2
    characters = [''] * n

    index, cur = len(url) - 1, n - 1

    while index > -1:

        if url[index].isspace():
            characters[cur] = '0'
            characters[cur - 1] = '2'
            characters[cur - 2] = '%'
            cur -= 3
        else:
            characters[cur] = url[index]
            cur -= 1

        index -= 1

    return to_str(characters)

r = urlify(url)

print(url)
print(r)
