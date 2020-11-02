#include <bits/stdc++.h>

/*150. Evaluate Reverse Polish Notation.

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:

Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
Example 1:

Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/

class evaluate_rpn
{
    static inline std::unordered_map<std::string, std::function<int( int, int )>> operators = {
        { "+", []( const int left, const int right ) { return left + right; } },
        { "-", []( const int left, const int right ) { return left - right; } },
        { "*", []( const int left, const int right ) { return left * right; } },
        { "/", []( const int left, const int right ) { return left / right; } }
    };

    static bool is_operator( const std::string& chr )
    {
        return operators.find( chr ) != operators.end();
    }

public:

    static int eval_rpn( const std::initializer_list<std::string>& tokens )
    {
        auto stack = std::stack<int>();

        for( auto& token : tokens )
        {
            if( is_operator( token ) )
            {
                const auto right = stack.top();
                stack.pop();
                const auto left = stack.top();
                stack.pop();

                auto result = operators[ token ]( left, right );

                stack.push( result );
            }
            else
            {
                stack.push( std::stoi( token ) );
            }
        }

        return stack.top();
    }
};

auto main() -> int
{
    auto actual = evaluate_rpn::eval_rpn( { "2","1","+","3","*" } );
    auto expected = 6;
		
	return 0;
}