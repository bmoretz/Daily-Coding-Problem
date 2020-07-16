#pragma once

#include <deque>

#include "problem.h"

namespace hackerrank::lang
{
	struct cpp_template final : problem
	{
		explicit cpp_template( std::string&& name )
			: problem( std::move( name ) )
		{
			entry_point = []() { return main(); };
		}

		template <class T>
		class add_elements
		{
			T value_;

		public:
			explicit add_elements( T val )
			{
				value_ = val;
			}

			T add( T other ) const
			{
				return value_ + other;
			}
		};

		template <>
		class add_elements<int>
		{
			int value_;

		public:
			explicit add_elements( const int val ) { value_ = val; }

			int add( const int other ) const
			{
				return value_ + other;
			}
		};

		template <>
		class add_elements<std::string>
		{
			std::string value_;

		public:

			explicit add_elements( const std::string& val )
			{
				value_ = val;
			}

			std::string concatenate( const std::string& other )
			{
				return value_.append( other );
			}
		};

		static int main()
		{
			int n, i;
			std::cin >> n;

			for( i = 0; i < n; i++ )
			{
				std::string type;
				std::cin >> type;

				if( type == "float" )
				{
					double element1, element2;
					std::cin >> element1 >> element2;

					add_elements<double> myfloat( element1 );
					std::cout << myfloat.add( element2 ) << std::endl;
				}
				else if( type == "int" )
				{
					int element1, element2;
					std::cin >> element1 >> element2;
					add_elements<int> myint( element1 );
					std::cout << myint.add( element2 ) << std::endl;
				}
				else if( type == "string" )
				{
					std::string element1, element2;
					std::cin >> element1 >> element2;
					add_elements<std::string> mystring( element1 );
					std::cout << mystring.concatenate( element2 ) << std::endl;
				}
			}

			return 0;
		}
	};

	struct cpp_preprocessor final : problem
	{
		explicit cpp_preprocessor( std::string&& name )
			: problem( std::move( name ) )
		{
			entry_point = [this]() { return main(); };
		}

#define toStr(x) #x
#define io(s) std::cin >> s
#define foreach(list, index) for(int index = 0; index < list.size(); index++)
#define FUNCTION(name, op) void name(int &x, int y){ if(!(x op y)) x = y; }
#define INF 1e9

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

		FUNCTION( minimum, < )
			FUNCTION( maximum, > )

			int main() {
			int n; std::cin >> n;
			std::vector<int> v( n );
			foreach( v, i ) {
				io( v )[ i ];
			}
			int mn = INF;
			int mx = -INF;
			foreach( v, i ) {
				minimum( mn, v[ i ] );
				maximum( mx, v[ i ] );
			}
			int ans = mx - mn;
			std::cout << toStr( Result = ) << ' ' << ans;
			return 0;
		}
	};
}