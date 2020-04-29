'''
basic implementation of merge sort 
'''

def merge_sort1(values):

    def merge_sort(values):
        n = len(values)

        if n <= 1:
            return values

        mid = int(n/2)

        left = values[:mid]
        left = merge_sort(left)

        right = values[mid:]
        right = merge_sort(right)

        left_ptr, right_ptr = 0, 0

        result = []

        for index in range(n):

            if left_ptr == len(left):
                # left set empty, fill from right
                while right_ptr < len(right):
                    result += [right[right_ptr]]
                    right_ptr += 1

            elif right_ptr == len(right):
                # right set empty, fill from left
                while left_ptr < len(left):
                    result += [left[left_ptr]]
                    left_ptr += 1

            # take min element from both sides
            elif left[left_ptr] <= right[right_ptr]:
                result += [left[left_ptr]]
                left_ptr += 1
            else:
                result += [right[right_ptr]]
                right_ptr += 1

        return result
    
    if values == None: return None

    return merge_sort(values)

'''Sorted Merge.

You are given two sorted arrays, A and B, where A has a large enough
buffer at the end to hold B. Write a method to merge B into A in sorted order.
'''

A = [1, 3, 5, 9, 10, 15]
B = [2, 4, 6, 8, 12, 13]

A = A + [None] * len(B)

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