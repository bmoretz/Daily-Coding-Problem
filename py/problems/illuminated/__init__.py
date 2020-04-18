'''Karatsuba's algorithm.

So: what's the product of the following two 64-digit numbers?

3141592653589793238462643383279502884197169399375105820974944592

2718281828459045235360287471352662497757247093699959574966967627
'''

from math import ceil

def karatsuba(x, y):

    def zero_pad(value, digits, left = True):

        for pad in range(digits):
            if left:
                value = '0' + value
            else:
                value = value + '0'

        return value

    def split(value):
        n = len(value)

        mid =  ceil(n / 2)

        return (int(value[:mid]), int(value[mid:]))

    x, y = str(x), str(y)

    nx, ny = len(x), len(y)

    n = max(nx, ny)
    j = n//2

    if n % 2 != 0:
        j += 1

    b_pad = n - j
    a_pad = b_pad * 2

    if nx == 1 and ny == 1:
        return int(x) * int(y)

    x, y = zero_pad(x, ny - nx), zero_pad(y, nx - ny)

    a, b = split(x)
    c, d = split(y)

    p = a + b
    q = c + d

    ac = karatsuba(a, c)
    bd = karatsuba(b, d)
    pq = karatsuba(p, q)

    abcd = pq - ac - bd

    A = int(zero_pad( str(ac), a_pad, left=False))
    B = int(zero_pad( str(abcd), b_pad, left=False))
    C = bd

    return A + B + C

'''
This file contains all of the 100,000 integers between 1 and 100,000 (inclusive) in some order, with no integer repeated.

Your task is to compute the number of inversions in the file given, where the i^{th}i 
th
  row of the file indicates the i^{th}i 
th
  entry of an array.

Because of the large size of this array, you should implement the fast divide-and-conquer algorithm covered in the video lectures.

The numeric answer for the given input file should be typed in the space below.

So if your answer is 1198233847, then just type 1198233847 in the space provided without any space / commas / any other punctuation marks. You can make up to 5 attempts, and we'll use the best one for grading.
'''

def count_inversions(arr):

    def ci(arr):

        n = len(arr)
        
        if n <= 1:
            return (0, arr)

        mid, inversions = n//2, 0

        # parse out results from left call
        left_inversions, left_set = ci(arr[:mid])
        inversions += left_inversions

        # parse results from right call
        right_inversions, right_set = ci(arr[mid:])
        inversions += right_inversions
        
        # merge results
        left_index, right_index = 0, 0

        result = []

        for index in range(n):
            
            left  = left_set[left_index] if left_index < len(left_set) else None
            right = right_set[right_index] if right_index < len(right_set) else None

            if not right or (left and left <= right):
                result += [left]
                left_index += 1
            else:
                result += [right]
                right_index += 1

                if left: inversions += len(left_set[left_index:])

        return (inversions, result)

    if arr == None:
        return (0, None)
    
    inversions, results = ci(arr)

    return inversions
    