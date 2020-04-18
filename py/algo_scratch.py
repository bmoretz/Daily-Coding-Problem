import os

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

file_path = os.getcwd() + '\py\\data\\IntegerArray.txt'

def to_array(str):
    return [int(c) for c in str]

def read_numbers():
    with open(file_path, 'r') as f:
        lines = f.read().splitlines()
        numbers = [int(line) for line in lines]
    return numbers

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

arr = read_numbers()
result = count_inversions(arr)
print(result)

#totalInversions = 0

#for arr in read_numbers():
#    totalInversions += count_inversions( arr )

#print(totalInversions)