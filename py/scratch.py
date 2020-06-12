'''Missing Number.

An array A contains all the integers from 0 to n, except for one number
which is missing. In this problem, we cannot access an entire integer in A
with a single operation. The elements of A are represented in binary, and
the only operation we can use to access them is "fetch the jth bit of A[i],"
which takes constant time. Write code to find the missing integer. Can you
do it in O(N) time?
'''

def to_bin_arr(num):
    return [int(s) for s in bin(num)[2:]]

def build_num_arr(n, exclude):

    arr = []

    for index in range(n+1):

        if index == exclude:
            continue

        arr += to_bin_arr(index)

    return arr

def missing_brute(arr):

    cur, index = 0, 0
    n = len(arr)

    while index < n:
        
        expected = to_bin_arr(cur)

        for j in expected:
            
            if arr[index] != j:
                return cur

            index += 1

        cur += 1
    
    return cur

s = build_num_arr(10, 10)

res = missing_brute(s)

print(res)
