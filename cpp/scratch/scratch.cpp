#include <bits/stdc++.h>
#include "../hackerrank/problem.h"

using namespace hackerrank;

struct inherited_code final : problem
{	
	explicit inherited_code( std::string&& name )
		: problem( std::move( name ) )
	{
		entry_point = [this]() { return main(); };
	}

	struct bad_length_exception final :
		std::runtime_error
	{
		explicit bad_length_exception( const int length )
			: std::runtime_error( std::to_string( length ) )
		{ }
	};

	static bool check_username( const std::string& username ) {

		auto is_valid = true;
		const int n = username.length();

		if( n < 5 ) {
			throw bad_length_exception( n );
		}

		for( auto i = 0; i < n - 1; i++ ) 
		{
			if( username[ i ] == 'w' && username[ i + 1 ] == 'w' ) {
				is_valid = false;
			}
		}

		return is_valid;
	}
	
	int main()
	{
		int t; std::cin >> t;
		
		while( t-- ) 
		{
			std::string username;
			std::cin >> username;

			try 
			{
				const auto is_valid = check_username( username );
				std::cout << ( is_valid ? "Valid" : "Invalid" ) << '\n';				
			}
			catch( bad_length_exception e ) {
				std::cout << "Too short: " << e.what() << '\n';
			}
		}
		
		return 0;
	}
};

auto main() -> int
{
	auto problem = 
		inherited_code{ "inherited-code-testcases" };

	return problem.run();
}