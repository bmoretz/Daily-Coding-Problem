'''Sorted Merge.

You are given two sorted arrays, A and B, where A has a large enough
buffer at the end to hold B. Write a method to merge B into A in sorted order.
'''

A = None
B = None


def sorted_merge1(A, B):

    if A == None or B == None:
        return None

    a_pos = sum( [1 for num in A if num != None] ) - 1
    b_pos = len(B) - 1

    place = len(A) - 1

    for index in range(len(A) - 1, -1, -1):

        if a_pos != -1 and (b_pos == -1 or A[a_pos] >= B[b_pos]):
            A[index], A[a_pos] = A[a_pos], A[index]
            
            a_pos -= 1
        elif b_pos != -1:
            A[index], B[b_pos] = B[b_pos], None
            
            b_pos -= 1

    return A

results = sorted_merge1(A, B)

print(results)