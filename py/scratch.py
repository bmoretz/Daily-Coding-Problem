'''Recursive Multiply.

Write a recursive function to multiply two positive integers without 
using the * operator. You can use addition, subtraction, and bit shifting, 
but you should minimize the number of those operations.

'''

def rec_multiply1(a, b):

    def mult(a, b):  

        if b == 1:
            return a
        else:
            return a + mult(a, b - 1)

    if not (a or b): return None
    
    if a == 0 or b == 0: return 0      

    return mult(a, b)


res = rec_multiply1(17, 23)

print(res)