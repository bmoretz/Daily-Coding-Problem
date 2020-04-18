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

from py.problems.illuminated import count_inversions

file_path = os.getcwd() + '\py\\data\\IntegerArray.txt'

def to_array(str):
    return [int(c) for c in str]

def read_numbers():
    with open(file_path, 'r') as f:
        lines = f.read().splitlines()
        numbers = [int(line) for line in lines]
    return numbers

arr = read_numbers()
result = count_inversions(arr)

print(result)