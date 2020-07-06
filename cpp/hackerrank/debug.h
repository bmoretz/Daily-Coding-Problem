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
			{
			}
		};

		static bool check_username( const std::string& username )
		{
			auto is_valid = true;
			const int n = username.length();

			if( n < 5 )
			{
				throw bad_length_exception( n );
			}

			for( auto i = 0; i < n - 1; i++ )
			{
				const auto index = static_cast< int >( i + 1 );

				if( username[ i ] == 'w' && username[ index ] == 'w' )
				{
					is_valid = false;
				}
			}

			return is_valid;
		}

		static int main()
		{
			int t;
			std::cin >> t;

			while( t-- )
			{
				std::string username;
				std::cin >> username;

				try
				{
					const auto is_valid = check_username( username );
					std::cout << ( is_valid ? "Valid" : "Invalid" ) << '\n';
				}
				catch( const bad_length_exception& e )
				{
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
			entry_point = []() { return main(); };
		}

		class server
		{
			static int load_;

		public:
			static int compute( const long long A, const long long B )
			{
				load_ += 1;
				if( A < 0 )
				{
					throw std::invalid_argument( "A is negative" );
				}

				std::vector<int> v( A, 0 );
				int real = -1, cmplx = sqrt( -1 );
				if( B == 0 ) throw 0;
				real = ( A / B ) * real;
				const auto ans = v.at( B );
				return real + A - B * ans;
			}

			static int get_load()
			{
				return load_;
			}

			static void reset_load()
			{
				load_ = 0;
			}
		};

		static int main()
		{
			int t;
			std::cin >> t;
			while( t-- )
			{
				long long A, B;
				std::cin >> A >> B;

				try
				{
					const auto result = server::compute( A, B );

					std::cout << result << std::endl;
				}
				catch( const std::bad_alloc& )
				{
					std::cout << "Not enough memory" << std::endl;
				}
				catch( const std::out_of_range& )
				{
					std::cout << "Exception: vector::_M_range_check: __n "
						<< "(which is " << B << ")"
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

			std::cout << server::get_load() << std::endl;
			server::reset_load();
			return 0;
		}
	};

	int exceptional_server::server::load_ = 0;

	struct hotel_prices final : problem
	{
		explicit hotel_prices( std::string&& name )
			: problem( std::move( name ) )
		{
			entry_point = []() { return main(); };
		}

		class hotel_room
		{
		public:
			virtual ~hotel_room() = default;

			hotel_room( const int bedrooms, const int bathrooms )
				: bedrooms_( bedrooms ), bathrooms_( bathrooms )
			{
			}

			virtual int get_price()
			{
				return 50 * bedrooms_ + 100 * bathrooms_;
			}

		private:
			int bedrooms_;
			int bathrooms_;
		};

		class hotel_apartment : public hotel_room
		{
		public:
			
			hotel_apartment( const int bedrooms, const int bathrooms )
				: hotel_room( bedrooms, bathrooms )
			{
			}

			int get_price() override
			{
				return hotel_room::get_price() + 100;
			}
		};

		static int main()
		{
			int n;
			std::cin >> n;
			std::vector<hotel_room*> rooms;
			for( auto i = 0; i < n; ++i )
			{
				std::string room_type;
				int bedrooms;
				int bathrooms;
				std::cin >> room_type >> bedrooms >> bathrooms;
				if( room_type == "standard" )
				{
					rooms.push_back( new hotel_room( bedrooms, bathrooms ) );
				}
				else
				{
					rooms.push_back( new hotel_apartment( bedrooms, bathrooms ) );
				}
			}

			auto total_profit = 0;
			for( auto room : rooms )
			{
				total_profit += room->get_price();
			}

			std::cout << total_profit << std::endl;
			rooms.clear();

			for( auto room : rooms )
				delete room;
			
			return 0;
		}
	};
}