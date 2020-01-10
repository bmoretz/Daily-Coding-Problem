'''Given a string and a number of lines k, print the string in zigzag form.

In zigzag, characters are printed out diagonally from top left to bottom right until reaching the k^th line, then back up to top right, and so on.

For example, given the sentence "thisisazigzag" and k = 4, you should print:

t     a     g
 h   s z   a
  i i   i z
   s     g
'''

stri, k = "thisisazigzag", 4
n = len(stri)

i = (2 * k) - 1

result = {new_list : [] for new_list in range(k)}

for index in range(k * n):
    line, char = index % k, index % n
    
    d = ( index % i ) - i
    
    result[line] +=  str( ' ' * line ) + stri[ char ]

