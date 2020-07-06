#include <bits/stdc++.h>
#include "../hackerrank/problem.h"

using namespace hackerrank;

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
			catch( const std::out_of_range& oor ) {
				std::cout << "Exception: vector::_M_range_check: __n (which is " << B << 
					") >= this->size() (which is " << A << ")" << std::endl;
			}
			catch( std::exception const& ex )
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

auto main() -> int
{
	const auto problem =
		exceptional_server{"exceptional-server-testcases"};

	return problem.run(3);
}