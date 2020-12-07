
'''
66. Plus One.

Given a non-empty array of decimal digits representing a non-negative integer, 
increment one to the integer.

The digits are stored such that the most significant digit is at the head of 
the list, and each element in the array contains a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself. 

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Example 3:

Input: digits = [0]
Output: [1]

Constraints:

1 <= digits.length <= 100
0 <= digits[i] <= 9
'''

class plus_one:
    
    @staticmethod
    def plusOne(digits: List[int]) -> List[int]:
        
        if not digits: return []
        
        pos, carry = len(digits) - 1, 1
        
        while pos >= 0 and carry:
            
            digits[pos] = digits[pos] + carry
            
            if digits[pos] > 9:
                digits[pos], carry = 0, 1
                pos -= 1
            else:
                carry = 0
        
        if carry:
            digits = [carry] + digits
            
        return digits

actual = dominate_index.dominantIndex([3, 6, 1, 0])
expected = 1