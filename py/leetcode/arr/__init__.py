'''
Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written.

Do the above modifications to the input array in place, do not return anything from your function.

Example 1:

Input: [1,0,2,3,0,4,5,0]
Output: null
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
Example 2:

Input: [1,2,3]
Output: null
Explanation: After calling your function, the input array is modified to: [1,2,3]

Note:

1 <= arr.length <= 10000
0 <= arr[i] <= 9
'''

from typing import List

class duplicate_zeros:
    
    def shift_arr( self, arr : List[int], index : int ) -> None:
        
        pos = len(arr) - 1
        
        while pos > 0 and pos > index:
            arr[pos] = arr[pos-1]
            pos -= 1
            
        
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        
        pos, n = 0, len(arr)
        
        while pos < n:
            
            if arr[pos] == 0 and pos < n - 1:
                
                self.shift_arr(arr, pos + 1 )
                arr[pos+1] = 0
                
                pos += 1
            elif pos == n:
                pos[arr] = 0
                
            pos += 1