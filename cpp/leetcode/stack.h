#pragma once

#include <functional>
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

	/* 739. Daily Temperatures.

	Given a list of daily temperatures T, return a list such that, for each day in the input, tells you
	how many days you would have to wait until a warmer temperature. If there is no future day for which
	this is possible, put 0 instead.

	For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output
	should be [1, 1, 4, 2, 1, 1, 0, 0].

	Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer
	in the range [30, 100].
	*/

	class next_hottest_temperature
	{
	public:

		static std::vector<int> daily_temperatures( const std::vector<int>& temps )
		{
			auto result = std::vector<int>( temps.size() );
			auto stack = std::stack<int>();

			for( int index = temps.size() - 1; index >= 0; --index )
			{
				const auto current = temps.at( index );

				while( !stack.empty() && current >= temps[ stack.top() ] )
					stack.pop();

				result[ index ] = stack.empty() ? 0 : stack.top() - index;

				stack.push( index );
			}

			return result;
		}
	};


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
		static inline std::unordered_map<std::string, std::function<int( int, int )>> operators_ = {
			{ "+", []( const int left, const int right ) { return left + right; } },
			{ "-", []( const int left, const int right ) { return left - right; } },
			{ "*", []( const int left, const int right ) { return left * right; } },
			{ "/", []( const int left, const int right ) { return left / right; } }
		};

		static bool is_operator( const std::string& chr )
		{
			return operators_.find( chr ) != operators_.end();
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

					auto result = operators_[ token ]( left, right );

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

	/*200. Number of Islands.

	Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.

	An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

	Example 1:

	Input: grid = [
	  ["1","1","1","1","0"],
	  ["1","1","0","1","0"],
	  ["1","1","0","0","0"],
	  ["0","0","0","0","0"]
	]
	Output: 1
	Example 2:

	Input: grid = [
	  ["1","1","0","0","0"],
	  ["1","1","0","0","0"],
	  ["0","0","1","0","0"],
	  ["0","0","0","1","1"]
	]
	Output: 3


	Constraints:

	m == grid.length
	n == grid[i].length
	1 <= m, n <= 300
	grid[i][j] is '0' or '1'.
	*/

	class num_islands_dfs
	{
		struct point
		{
			int row, col;

			point( const int x, const int y )
				: row{ x }, col{ y }
			{ }

			point operator+( const point& other ) const
			{
				return point( row + other.row, col + other.col );
			}
		};

		static inline std::vector<point> directions = std::vector<point>
		{
			{ 0, -1 }, {0, 1}, {-1, 0}, {1, 0}
		};

		static void map_connected( const std::vector<std::vector<char>>& grid,
			std::vector<std::vector<bool>>& visited,
			const int row, const int col )
		{
			const int num_rows = grid.size();
			const int num_cols = grid[ 0 ].size();

			visited[ row ][ col ] = true;

			auto stack = std::stack<point>();
			stack.push( { row, col } );

			while( !stack.empty() )
			{
				const auto cur = stack.top();
				stack.pop();

				visited[ cur.row ][ cur.col ] = true;

				for( auto dir : directions )
				{
					auto next = cur + dir;

					if( next.row < 0 || next.row >= num_rows ||
						next.col < 0 || next.col >= num_cols )
						continue;

					if( visited[ next.row ][ next.col ] ||
						grid[ next.row ][ next.col ] == '0' )
						continue;

					stack.push( next );
				}
			}
		}

	public:

		static int num_islands( const std::vector<std::vector<char>>& grid )
		{
			if( grid.empty() || grid[ 0 ].empty() ) return 0;

			const int num_rows = grid.size();
			const int num_cols = grid[ 0 ].size();

			auto visited = std::vector<std::vector<bool>>
				( grid.size(), std::vector<bool>( grid[ 0 ].size(), false ) );

			auto num_islands = 0;

			for( auto row = 0; row < num_rows; ++row )
			{
				for( auto col = 0; col < num_cols; ++col )
				{
					if( !visited[ row ][ col ] && grid[ row ][ col ] == '1' )
					{
						++num_islands;
						map_connected( grid, visited, row, col );
					}
				}
			}

			return num_islands;
		}
	};
}
