#include <bits/stdc++.h>
#include <array>

/* 739. Daily Temperatures.

Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait
until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].
*/

class daily_temperatures
{
public:

	static std::vector<int> dailyTemperatures( std::vector<int>& temps )
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

auto main() -> int
{
	auto input1 = std::vector<int>{ 73, 74, 75, 71, 69, 72, 76, 73 };
	auto input2 = std::vector<int>{ 73, 74, 75, 71, 69, 72, 76, 73 };
	auto input3 = std::vector<int>{ 73, 74, 75, 71, 69, 72, 76, 73 };
	
	const auto result = daily_temperatures::dailyTemperatures( input1 );
	
	return 0;
}