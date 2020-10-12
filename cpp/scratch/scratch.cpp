#include <bits/stdc++.h>

/*22. Generate Parentheses.

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 
Constraints:

1 <= n <= 8
*/

class gen_parenthesis
{
    static bool is_valid( const std::string& str )
    {
        auto balance = 0;

        for( auto c : str )
        {
            if( c == '(' )
                ++balance;
            else
                --balance;

            if( balance < 0 )
                return false;
        }

        return balance == 0;
    }

    static void generate( std::vector<std::string>& results,
        std::string& current, const int pos )
    {
        if( pos == current.length() )
        {
            if( is_valid( current ) )
                results.push_back( current );
        }
        else
        {
            current[ pos ] = '(';
            generate( results, current, pos + 1 );
            current[ pos ] = ')';
            generate( results, current, pos + 1 );
        }
    }

public:

    static std::vector<std::string> generate_parenthesis( const int n )
    {
        auto combinations = std::vector<std::string>();

    	// create a buffer string of 2*n length (2 chars for each pair)
        auto buff = std::string( n * 2, ' ' );

    	// gen recursively
        generate( combinations, buff, 0 );

        return combinations;
    }
};

auto main() -> int
{
    const auto actual = gen_parenthesis::generate_parenthesis( 3 );

    const auto expected = std::vector<std::string>
    {
        "((()))",
    	"(()())",
    	"(())()",
    	"()(())",
    	"()()()"
    };
	
	return 0;
}