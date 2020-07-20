#pragma once

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

	struct cpp_operator_overloading final : problem
	{
		explicit cpp_operator_overloading( std::string&& name )
			: problem( std::move( name ) )
		{
			entry_point = []() { return main(); };
		}

		class Matrix
		{
		public:
			std::vector<std::vector<int>> a;

			Matrix() = default;

			Matrix( const int rows, const int cols )
			{
				a.resize( rows );

				for( auto row = 0; row < rows; ++row )
				{
					a[ row ].resize( cols );
				}
			}

			Matrix operator+( const Matrix& other )
			{
				const auto rows = a.size(), cols = a[ 0 ].size();
				Matrix result( rows, cols );

				for( auto row = 0; row < rows; ++row )
				{
					for( auto col = 0; col < cols; ++col )
					{
						result.a[ row ][ col ] = a[ row ][ col ] + other.a[ row ][ col ];
					}
				}

				return result;
			}
		};

		static int main() {

			int cases, k;
			std::cin >> cases;
			for( k = 0; k < cases; k++ ) {
				Matrix x;
				Matrix y;
				Matrix result;
				int n, m, i, j;
				std::cin >> n >> m;
				for( i = 0; i < n; i++ ) {
					std::vector<int> b;
					int num;
					for( j = 0; j < m; j++ ) {
						std::cin >> num;
						b.push_back( num );
					}
					x.a.push_back( b );
				}
				for( i = 0; i < n; i++ ) {
					std::vector<int> b;
					int num;
					for( j = 0; j < m; j++ ) {
						std::cin >> num;
						b.push_back( num );
					}
					y.a.push_back( b );
				}
				result = x + y;
				for( i = 0; i < n; i++ ) {
					for( j = 0; j < m; j++ ) {
						std::cout << result.a[ i ][ j ] << " ";
					}
					std::cout << std::endl;
				}
			}

			return 0;
		}
	};

	struct overload_operators final : problem
	{
		explicit overload_operators( std::string&& name )
			: problem( std::move( name ) )
		{
			entry_point = []() { return main(); };
		}

		class complex
		{
		public:
			int a, b;

			complex() = default;

			complex( const int r, const int i )
			{
				a = r; b = i;
			}

			void input( std::string s )
			{
				auto v1 = 0;
				auto i = 0;

				while( s[ i ] != '+' )
				{
					v1 = v1 * 10 + s[ i ] - '0';
					i++;
				}

				while( s[ i ] == ' ' || s[ i ] == '+' || s[ i ] == 'i' )
				{
					i++;
				}

				auto v2 = 0;

				while( i < s.length() )
				{
					v2 = v2 * 10 + s[ i ] - '0';
					i++;
				}
				
				a = v1;
				b = v2;
			}

			complex operator+( const complex& other ) const
			{
				return complex( a + other.a, ( b + other.b ) );
			}

			friend std::ostream& operator<<( std::ostream& os, const complex& obj )
			{
				os << obj.a << "+i" << obj.b;

				return os;
			}
		};

		static int main()
		{
			complex x, y;
			std::string s1, s2;
			std::cin >> s1;
			std::cin >> s2;
			x.input( s1 );
			y.input( s2 );
			
			const auto z = x + y;
			std::cout << z << std::endl;

			return 0;
		}
	};

	struct workshop_optimization final : problem
	{
		explicit workshop_optimization( std::string&& name )
			: problem( std::move( name ) )
		{
			entry_point = [this]() { return main(); };
		}

		struct workshop
		{
			int end_time;
			int start_time;
			int duration;

			bool operator<( const workshop& r ) const
			{
				return end_time < r.end_time;
			}
		};

		struct available_workshops
		{
			int n;
			workshop* a;
		};

		static available_workshops* initialize( const int* start_time, const int* duration, const int n )
		{
			const auto ptr = new available_workshops;
			ptr->n = n;
			ptr->a = new workshop[ n ];

			for( auto i = 0; i < n; i++ )
			{
				ptr->a[ i ].start_time = start_time[ i ];
				ptr->a[ i ].duration = duration[ i ];
				ptr->a[ i ].end_time = start_time[ i ] + duration[ i ];
			}

			return ptr;
		}

		int calculate_max_workshops( available_workshops* ptr ) const
		{
			std::sort( ptr->a, ptr->a + ptr->n );
			auto m = 1;
			auto end_time = ptr->a[ 0 ].end_time;

			for( auto i = 1; i < ptr->n; i++ )
			{
				if( ptr->a[ i ].start_time >= end_time )
				{
					m += 1;
					end_time = ptr->a[ i ].end_time;
				}
			}

			return m;
		}

		int main()
		{
			int n;
			std::cin >> n;
			const auto start_time = new int[ n ];
			const auto duration = new int[ n ];

			for( auto i = 0; i < n; i++ )
			{
				std::cin >> start_time[ i ];
			}

			for( auto i = 0; i < n; i++ )
			{
				std::cin >> duration[ i ];
			}

			const auto ptr = initialize( start_time, duration, n );
			std::cout << calculate_max_workshops( ptr ) << std::endl;

			return 0;
		}
	};
}