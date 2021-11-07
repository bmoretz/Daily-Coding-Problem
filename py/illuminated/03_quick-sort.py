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

from utility import get_test_file

def read_numbers():

    file_path = get_test_file('quick-sort', 'QuickSort.txt')

    with open(file_path, 'r') as f:
        lines = f.read().splitlines()
        numbers = [int(line) for line in lines]

    return numbers

''' quick sort with pivot statically set at 0 '''

def pivot_0(arr, left, right):
    return left

''' quick sort with pivot statically set at n '''

def pivot_n(arr, left, right): 
    return right

''' quick sort with pivot calculated to be the median value '''
def pivot_m(arr, left, right):
    
    mid = 0 if (right - left) == 1 else ((right - left)) // 2 + left
    
    candidate = sorted([arr[left], arr[mid], arr[right]])

    return arr.index(candidate[1])

def quick_sort(arr, left=0, right=None, choose_pivot=None, comp=0):
    
    def partition(arr, left, right, pivot):

        assert left <= pivot <= right

        p = arr[pivot]

        arr[left], arr[pivot] = arr[pivot], arr[left]

        j = left + 1

        for index in range(left + 1, right + 1):

            if arr[index] < p:
                arr[index], arr[j] = arr[j], arr[index]
                j += 1

        j -= 1

        arr[left], arr[j] = arr[j], arr[left]
    
        return j
    
    if right == None: right = len(arr) - 1

    n = right - left

    if n < 1: return 0

    comp = n

    pivot = choose_pivot(arr, left, right)

    j = partition(arr, left, right, pivot)

    comp += quick_sort(arr, left, j - 1, choose_pivot)
    comp += quick_sort(arr, j + 1, right, choose_pivot)

    return comp

def run_compare():
    
    for method in (pivot_0, pivot_n, pivot_m):

        numbers = read_numbers()

        comparisions = quick_sort(numbers, choose_pivot=method)

        assert numbers == sorted(numbers)

        print(f'method: ', method.__name__, ' sorted: ', len(numbers), ' elements with ', comparisions, ' comparisions.')

if __name__ == '__main__':
    run_compare()