#pragma once

#include <memory>
#include <string>
#include <stack>

namespace leetcode::stack
{
	/* 678. Valid Parenthesis String.

	Given a string containing only three types of characters: '(', ')' and '*', write a function to check
	whether this string is valid. We define the validity of a string by these rules:

	Any left parenthesis '(' must have a corresponding right parenthesis ')'.
	Any right parenthesis ')' must have a corresponding left parenthesis '('.
	Left parenthesis '(' must go before the corresponding right parenthesis ')'.
	'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.

	An empty string is also valid.

	Example 1:
	Input: "()"
	Output: True

	Example 2:
	Input: "(*)"
	Output: True

	Example 3:
	Input: "(*))"
	Output: True
	Note:

	The string size will be in the range [1, 100].
	*/

	struct valid_parenthesis
	{
		static bool check_valid_string( const std::string& input )
		{
			if( input.empty() ) return true;

			auto parens = std::stack<char>();
			auto wildcards = 0;

			for( auto chr : input )
			{
				if( chr == '(' )
				{
					parens.push( chr );
				}
				else if( chr == ')' )
				{
					if( !parens.empty() )
					{
						parens.pop();
					}
					else if( wildcards > 0 )
					{
						wildcards--;
					}
					else
					{
						return false;
					}
				}
				else
				{
					wildcards++;

					if( !parens.empty() )
					{
						parens.pop();
						wildcards++;
					}
				}
			}

			return parens.empty();
		}
	};

	/* 227. Basic Calculator II.

	Implement a basic calculator to evaluate a simple expression string.

	The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

	Example 1:

	Input: "3+2*2"
	Output: 7
	Example 2:

	Input: " 3/2 "
	Output: 1
	Example 3:

	Input: " 3+5 / 2 "
	Output: 5
	Note:

	You may assume that the given expression is always valid.
	Do not use the eval built-in library function.

	*/

	class basic_calculator_ii
	{
	public:

		/// <summary>
		/// calculates the numeric value of the passed in mathematical string expression.
		/// </summary>
		/// <param name="expr">the expression to evaluate</param>
		/// <returns>numerical value of the evaluated expression</returns>
		static int calculate( const std::string& expr )
		{
			if( expr.empty() ) return 0;

			auto ops = std::stack<int>();
			auto pos = std::size_t();

			ops.push( parse_next_operand( expr, pos ) );

			while( pos < expr.size() )
			{
				const auto op = parse_next_op( expr, pos );

				switch( op )
				{

				case '+':
				case '-':
				{
					ops.push( parse_next_operand( expr, pos ) );
				} break;

				case '*':
				case '/':
				{
					const auto left = ops.top();
					ops.pop();
					const auto right = parse_next_operand( expr, pos );

					ops.push( op == '*' ? left * right : left / right );
				} break;

				default:break;
				}
			}

			auto result = 0;

			while( !ops.empty() )
			{
				result += ops.top();
				ops.pop();
			}

			return result;
		}

		/// <summary>
		/// trim spaces
		///
		/// advances the location pointer while we have a space.
		/// </summary>
		/// <param name="input">expression to evaluate</param>
		/// <param name="pos">current location</param>
		static void trim_space( const std::string& input, std::size_t& pos )
		{
			while( std::isspace( input[ pos ] ) )
				pos++;
		}

		/// <summary>
		/// parses the next operand
		/// </summary>
		/// <param name="input">the expression to evaluate</param>
		/// <param name="pos">current position</param>
		/// <returns>operand</returns>
		static int parse_next_operand( const std::string& input, std::size_t& pos )
		{
			trim_space( input, pos );

			std::string result;

			auto sign = 1;

			if( input.at( pos ) == '-' )
			{
				sign = -1;
				++pos;
			}

			trim_space( input, pos );

			while( std::isdigit( input[ pos ] ) )
			{
				result += input[ pos++ ];
			}

			return std::stoi( result ) * sign;
		}

		/// <summary>
		/// parse the next operator
		///
		/// read the next operator and increments the position place holder unless it's
		/// subtraction, then we just return the op and the current index so the number
		/// parser routine picks up the negative in the number.
		/// </summary>
		/// <param name="input">the expression</param>
		/// <param name="pos">current index to evaluate</param>
		/// <returns>the operand to execute</returns>
		static char parse_next_op( const std::string& input, std::size_t& pos )
		{
			trim_space( input, pos );

			return pos == input.size() ? ' ' :
				input.at( pos ) == '-' ?
				input.at( pos ) : input.at( pos++ );
		}
	};

	/*1472. Design Browser History.

	You have a browser of one tab where you start on the homepage and you can visit another
	url, get back in the history number of steps or move forward in the history number of steps.

	Implement the BrowserHistory class:

	BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
	void visit(string url) visits url from the current page. It clears up all the forward history.

	string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x,
	you will return only x steps. Return the current url after moving back in history at most steps.
	string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x,
	you will forward only x steps. Return the current url after forwarding in history at most steps.

	Example:

	Input:

	["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
	[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
	Output:
	[null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]

	Explanation:

	BrowserHistory browserHistory = new BrowserHistory("leetcode.com");
	browserHistory.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
	browserHistory.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
	browserHistory.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
	browserHistory.back(1);                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
	browserHistory.back(1);                   // You are in "facebook.com", move back to "google.com" return "google.com"
	browserHistory.forward(1);                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
	browserHistory.visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
	browserHistory.forward(2);                // You are in "linkedin.com", you cannot move forward any steps.
	browserHistory.back(2);                   // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
	browserHistory.back(7);                   // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"

	Constraints:

	1 <= homepage.length <= 20
	1 <= url.length <= 20
	1 <= steps <= 100
	homepage and url consist of  '.' or lower case English letters.
	At most 5000 calls will be made to visit, back, and forward.
	*/

	class browser_history
	{
		std::stack<std::string> back_, forward_;

	public:

		explicit browser_history( const std::string& home_page )
		{
			back_.push( home_page );
		}

		void visit( const std::string& url )
		{
			back_.push( url );
			forward_ = std::stack<std::string>{ };
		}

		std::string back( int steps )
		{
			while( back_.size() > 1 && steps != 0 )
			{
				forward_.push( back_.top() );
				back_.pop();
				--steps;
			}

			return back_.top();
		}

		std::string forward( int steps )
		{
			while( !forward_.empty() && steps != 0 )
			{
				back_.push( forward_.top() );
				forward_.pop();
				--steps;
			}

			return back_.top();
		}
	};

	/*901. Online Stock Span.

	Write a class StockSpanner which collects daily price quotes for some stock,
	and returns the span of that stock's price for the current day.

	The span of the stock's price today is defined as the maximum number of consecutive
	days (starting from today and going backwards) for which the price of the stock was less than or equal to today's price.

	For example, if the price of a stock over the next 7 days were [100, 80, 60, 70, 60, 75, 85],
	then the stock spans would be [1, 1, 1, 2, 1, 4, 6].

	Example 1:

	Input: ["StockSpanner","next","next","next","next","next","next","next"], [[],[100],[80],[60],[70],[60],[75],[85]]
	Output: [null,1,1,1,2,1,4,6]
	Explanation:
	First, S = StockSpanner() is initialized.  Then:
	S.next(100) is called and returns 1,
	S.next(80) is called and returns 1,
	S.next(60) is called and returns 1,
	S.next(70) is called and returns 2,
	S.next(60) is called and returns 1,
	S.next(75) is called and returns 4,
	S.next(85) is called and returns 6.

	Note that (for example) S.next(75) returned 4, because the last 4 prices
	(including today's price of 75) were less than or equal to today's price.

	Note:

	Calls to StockSpanner.next(int price) will have 1 <= price <= 10^5.
	There will be at most 10000 calls to StockSpanner.next per test case.
	There will be at most 150000 calls to StockSpanner.next across all test cases.
	The total time limit for this problem has been reduced by 75% for C++, and 50% for all other languages.

	*/

	class stock_spanner
	{
		std::stack<std::pair<int, int>> prev_;

	public:

		int next( const int price )
		{
			auto days = 1;

			while( !prev_.empty() && price >= prev_.top().first )
			{
				days += prev_.top().second;

				prev_.pop();
			}

			prev_.push( { price, days } );

			return days;
		}
	};

}
