import unittest, os

from problems.illuminated import quick_sort
from problems.illuminated import pivot_0, pivot_n, pivot_m
from problems.illuminated import get_sort_data

from .utility import get_test_file

def get_sort_data():
    
    file_path = get_test_file('quick-sort', 'QuickSort.txt')

    def read_numbers():

        with open(file_path, 'r') as f:
            lines = f.read().splitlines()
            numbers = [int(line) for line in lines]
            
        return numbers

    return read_numbers()

class Test_QuickSort(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_pivot_0(self):

        arr = get_sort_data()

        quick_sort(arr, choose_pivot=pivot_0)
        
        assert arr == sorted(arr)

    def test_pivot_n(self):

        arr = get_sort_data()

        quick_sort(arr, choose_pivot=pivot_n)
        
        assert arr == sorted(arr)

    def test_pivot_m(self):

        arr = get_sort_data()

        quick_sort(arr, choose_pivot=pivot_m)
        
        assert arr == sorted(arr)