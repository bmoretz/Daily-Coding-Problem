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
	
	struct exceptional_server final : problem
	{
		explicit exceptional_server( std::string&& name )
			: problem( std::move( name ) )
		{
			entry_point = [this]() { return main(); };
		}


		class Server {
			static int load;

		public:
			static int compute( long long A, long long B ) {
				load += 1;
				if( A < 0 ) {
					throw std::invalid_argument( "A is negative" );
				}
				std::vector<int> v( A, 0 );
				int real = -1, cmplx = sqrt( -1 );
				if( B == 0 ) throw 0;
				real = ( A / B ) * real;
				int ans = v.at( B );
				return real + A - B * ans;
			}
			
			static int getLoad() {
				return load;
			}

			static void resetLoad()
			{
				load = 0;
			}
		};

		int main() {

			int t;
			std::cin >> t;
			while( t-- ) {
				long long A, B;
				std::cin >> A >> B;

				try
				{
					const auto result = Server::compute( A, B );

					std::cout << result << std::endl;
				}
				catch( const std::bad_alloc& )
				{
					std::cout << "Not enough memory" << std::endl;
				}
				catch( const std::out_of_range& ) {
					std::cout << "Exception: vector::_M_range_check: __n "
						<< "(which is " << B <<")"
						<< " >= this->size() (which is " << A << ")"
						<< std::endl;
				}
				catch( const std::exception& ex )
				{
					std::cout << "Exception: " << ex.what() << std::endl;
				}
				catch( ... )
				{
					std::cout << "Other Exception" << std::endl;
				}
			}

			std::cout << Server::getLoad() << std::endl;
			Server::resetLoad();
			return 0;
		}
	};

	int exceptional_server::Server::load = 0;
}