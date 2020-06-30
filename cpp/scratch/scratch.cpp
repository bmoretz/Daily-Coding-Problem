#include <bits/stdc++.h>
#include "../hackerrank/problem.h"

using namespace hackerrank;

struct tutorial_string_stream final : problem
{
	using problem::problem;

	std::vector<int> parse_ints( const std::string& str ) const
	{
		std::istringstream iss( str );
		std::vector<int> results;
		std::string integer;
		
		while( std::getline( iss, integer, ',' ) )
			results.emplace_back( std::stoi( integer ) );
		
		return results;
	}

	int main() override
	{
		std::string str;
		std::cin >> str;
		std::vector<int> integers = parse_ints( str );
		for( int i = 0; i < integers.size(); i++ ) {
			std::cout << integers[ i ] << "\n";
		}

		return 0;
	}
};

auto main() -> int
{
	auto problem = 
		tutorial_string_stream{ "c-tutorial-stringstream-testcases" };

	problem.run();

	return 0;
}