#pragma once

#include <sstream>
#include <stack>
#include <memory>
#include <cassert>

#include "problem.h"

namespace hackerrank::debug
{
	struct inherited_code final : problem
	{
		explicit inherited_code( std::string&& name )
			: problem( std::move( name ) )
		{
			entry_point = []() { return main(); };
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

			for( auto i = 0; i < n - 1; i++ ) {
				const auto index = static_cast< int >( i + 1 );

				if( username[ i ] == 'w' && username[ index ] == 'w' ) {
					is_valid = false;
				}
			}

			return is_valid;
		}

		static int main()
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
				catch( const bad_length_exception& e ) {
					std::cout << "Too short: " << e.what() << '\n';
				}
			}

			return 0;
		}
	};
}
