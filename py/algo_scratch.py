import os

'''
The file contains all of the integers between 1 and 10,000 (inclusive, with no repeats) in unsorted order. 

The integer in the i^{th}ith row of the file gives you the i^{th}ith entry of an input array.

Your task is to compute the total number of comparisons used to sort the given input file by QuickSort. As you know, the number of comparisons depends on which elements are chosen as pivots, 
so we'll ask you to explore three different pivoting rules.

You should not count comparisons one-by-one. Rather, when there is a recursive call on a subarray of length mm, you should simply add m-1m−1 to your running total of comparisons.
(This is because the pivot element is compared to each of the other m-1m−1 elements in the subarray in this recursive call.)

WARNING: The Partition subroutine can be implemented in several different ways, and different implementations can give you differing numbers of comparisons. For this problem, you should implement the 
Partition subroutine exactly as it is described in the video lectures (otherwise you might get the wrong answer).

DIRECTIONS FOR THIS PROBLEM:

For the first part of the programming assignment, you should always use the first element of the array as the pivot element.
'''

file_path = os.getcwd() + '\py\\data\\QuickSort.txt'

def to_array(str):
    return [int(c) for c in str]

def read_numbers():
    with open(file_path, 'r') as f:
        lines = f.read().splitlines()
        numbers = [int(line) for line in lines]
    return numbers

''' quick sort with pivot statically set at 0'''

def qsort(arr, left, right, choose_pivot, comp=0):
    
    if left >= right: return 0

    n = right - left

    comp = n - 1

    pivot = choose_pivot(arr, left, right)

    arr[pivot], arr[left] = arr[left], arr[pivot]

    j = left + 1

    for index in range(left + 1, right):

        if arr[index] < arr[left]:
            arr[index], arr[j] = arr[j], arr[index]
            j += 1

    arr[left], arr[j - 1] = arr[j - 1], arr[left]

    comp += qsort(arr, left, j - 1, choose_pivot)
    comp += qsort(arr, j + 1, right, choose_pivot)

    return comp

def pivot_0(arr):

    def choose_pivot(arr, left, right):
        return left

    n = len(arr)

    return qsort(arr, 0, n, choose_pivot)

def pivot_n(arr):

    def choose_pivot(arr, left, right):
        return right - 1

    n = len(arr)

    return qsort(arr, 0, n, choose_pivot)

def pivot_m(arr):

    def choose_pivot(arr, left, right):

        mid = n // 2 - 1 if n % 2 == 0 else n // 2

        l, r, m = arr[left], arr[right - 1], arr[mid]

        values = sorted([l, r, m])
        
        index = 0

        if values[1] == arr[left]:
            index = left
        elif values[1] == arr[right - 1]:
            index = right
        else:
            index = mid

        return index

    n = len(arr)

    return qsort(arr, 0, n, choose_pivot)

nums = [5, 4, 3, 2, 1]
comps = pivot_n(nums)
print(comps)

num1 = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
comps = pivot_n(num1)

pivot_n(num1)

num2 = [8, 2, 4, 5, 7, 1]
comps = pivot_m(num2)

num2 = [13,10,6,7,14,5,8,12,1,19,4,11,16,9,17,3,2,18,20,15]
comps = pivot_m(num2)

q1 = pivot_0(read_numbers())
print(q1)

nums = read_numbers()
q2 = pivot_n(nums)
print(q2)

