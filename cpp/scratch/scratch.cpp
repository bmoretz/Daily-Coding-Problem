#include <bits/stdc++.h>

/* 1328. Break a Palindrome.

Given a palindromic string palindrome, replace exactly one character by any lowercase English letter so that the string becomes the
lexicographically smallest possible string that isn't a palindrome.

After doing so, return the final string.  If there is no way to do so, return the empty string.

Example 1:

Input: palindrome = "abccba"
Output: "aaccba"

Example 2:

Input: palindrome = "a"
Output: ""
 
Constraints:
	1 <= palindrome.length <= 1000
	palindrome consists of only lowercase English letters.
*/

struct break_palindrome
{
	/// <summary>
	/// break palindrome
	///
	/// straight forward approach to replace the first non-a with an a, if we can't
	/// then just move up to the next ordering level by replacing the last character with a b.
	/// </summary>
	/// <param name="input">the input string</param>
	/// <returns>broken palindrome</returns>
    static std::string break_palindrome1( std::string input )
	{
        if( input.size() == 1 ) {
            return "";
        }
    	
        auto start = std::size_t(), stop = input.size() - 1;

    	while( start < stop ) 
        {
            if( input[ start ] != 'a' )
            {
                input[ start ] = 'a';
                return input;
            }
    		
            start++; stop--;
        }
    	
        input[ input.size() - 1 ] = 'b';

    	return input;
    }
};

auto main() -> int
{
    const auto input1 = "abccba";
    const auto input2 = "repaper";
	
	const auto input3 = std::vector<std::string>{ "3", "9", "20", "", "", "15", "7", "", "1", "", "", "1" };
	const auto input4 = std::vector<std::string>{ "0", "2", "4", "1", "", "3", "-1", "5", "1", "", "6", "", "8" };
	const auto input5 = std::vector<std::string>{ "0", "2", "4" , "1", "", "3", "-1", "5", "1", "", "6", "", "8" };

	const auto root = break_palindrome::build_tree( input1 );
	const auto result = break_palindrome::level_order_bottom( root.get() );

	return 0;
}
