#include <bits/stdc++.h>

/*125. Valid Palindrome.
 *
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
 

Constraints:

s consists only of printable ASCII characters.
*/

class valid_palindrome
{
    static bool is_valid( const std::string& input, 
        const int index )
    {
        return std::isalpha( input[ index ] ) || std::isdigit( input[ index ] );
    }

public:

    static bool is_palindrome( const std::string& input )
    {
        const auto n = input.length();
        int left = 0, right = input.length() - 1;

        while( left < right )
        {
            while( left < right && !is_valid( input, left ) )
                ++left;

            while( right < n && !is_valid( input, right ) )
                --right;

            if( left < right && std::tolower( input[ left ] ) != std::tolower( input[ right ] ) )
                return false;

            ++left; --right;
        }

        return true;
    }
};

auto main() -> int
{
    const auto input = "A man, a plan, a canal: Panama";

    const auto actual = valid_palindrome::is_palindrome( input );
    const auto expected = true;
	
	return 0;
}