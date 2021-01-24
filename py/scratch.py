
'''
557. Reverse Words in a String III.

Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
'''

class reverse_words_str_iii:
    @staticmethod
    def reverseWords(s: str) -> str:
        
        result = ''

        for word in s.split(' '):
            
            if result:
                result += ' '

            for l in reversed(list(word)):
                result += l

        return result

s 
actual = max_consecutive_ones.findMaxConsecutiveOnes(s)

expected = [2, 2]